#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define TASKNAME "CONVEX"
#define maxN 300
#define maxLine maxN * (maxN - 1) * 2

typedef long long lli;
struct TPoint
{
    int x, y;
};
typedef TPoint TVector;

struct TLineSegment
{
    int u, v;
    TVector dir;
    bool fake;
    bool deleted;
};

TPoint p[maxN];
TLineSegment L[maxLine];
bool avail[maxLine];
int TopoList[maxLine], deg[maxLine];
int nTopoList;
int nLines = 0;
int first[maxN];
int neighbor[maxLine], proper[maxLine], nextidx[maxLine];
int fref[maxN][maxN], bref[maxN][maxN];
int f[maxN][maxN];
int n;

inline TVector operator -(const TVector &u, const TVector &v)
{
    TVector r;
    r.x = u.x - v.x;
    r.y = u.y - v.y;
    return r;
}

inline lli operator *(const TVector &u, const TVector &v)
{
    return (lli)u.x * v.y - (lli)u.y * v.x;
}

inline bool CCW(const TPoint &A, const TPoint &B, const TPoint &C)
{
    return (B - A) * (C - B) > 0;
}

inline void Maximize(int &Target, int Value)
{
    if (Value > Target) Target = Value;
}

inline bool operator < (const TPoint &p, const TPoint &q)
{
    if (p.y != q.y) return p.y < q.y;
    else return p.x < q.x;
}

void Enter()
{
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    sort(p, p + n);
}

inline void MakeLine(TLineSegment &L, int u, int v, bool fake)
{
    L.u = u; L.v = v; L.fake = fake;
    if (fake) L.dir = p[u] - p[v];
    else L.dir = p[v] - p[u];
}

inline void AddLine(int u, int v)
{
    MakeLine(L[nLines++], u, v, false);
    MakeLine(L[nLines++], u, v, true);
}

inline bool Kind(const TVector &v)
{
    if (v.y > 0 || (v.y == 0 && v.x > 0)) return 0;
    else return 1;
}

inline bool operator < (const TLineSegment &L1, const TLineSegment &L2)
{
    int k1 = Kind(L1.dir); int k2 = Kind(L2.dir);
    if (k1 != k2) return k1 < k2;
    return L1.dir * L2.dir > 0;
}

void Init()
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            {
                AddLine(i, j); AddLine(j, i);
            }
    sort(L, L + nLines);
    //Building reference table
    TLineSegment *line = &L[0];
    for (int k = 0; k < nLines; k++, line++)
    {
        line->deleted = false;
        if (line->fake) bref[line->u][line->v] = k;
        else fref[line->u][line->v] = k;
    }
    //Compute neighbor pointers, remember: NO circular list
    fill(first, first + n, -1);
    for (int i = nLines - 1; i >= 0; i--)
    {
        neighbor[i] = first[L[i].u];
        if (!L[i].fake)
            first[L[i].u] = i;
    }
    //Compute proper neighbor pointer
    fill(proper, proper + nLines, -1);
    for (int i = nLines - 1; i >= 0; i--)
    {
        int j = neighbor[i];
        if (j < 0) continue;
        if (L[i].dir * L[j].dir != 0) proper[i] = j;
        else proper[i] = proper[j];
    }
}

void PerformDelete(int base)
{
    base--;
    if (base < 0) return;
    for (int i = base + 1; i < n; i++)
    {
        L[fref[base][i]].deleted = true;
        L[fref[i][base]].deleted = true;
        L[bref[base][i]].deleted = true;
        L[bref[i][base]].deleted = true;
    }
}

void AdjustNeighbor(int i)
{
    int j = neighbor[i];
    if (j < 0) return;
    if (L[j].deleted) neighbor[i] = neighbor[j];
}

void AdjustProper(int i)
{
    int j = proper[i];
    if (j < 0) return;
    if (L[j].deleted) proper[i] = neighbor[j];
}

void InitByBase(int base)
{
    //Delete all points before base, keep sorted order of L
    PerformDelete(base);
    //Adjust Neighbor Pointers
    for (int i = base; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            AdjustNeighbor(fref[i][j]);
            AdjustNeighbor(bref[i][j]);
            AdjustNeighbor(fref[j][i]);
            AdjustNeighbor(bref[j][i]);
        }
    //Adjust Proper pointers
    for (int i = base; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            AdjustProper(fref[i][j]);
            AdjustProper(bref[i][j]);
            AdjustProper(fref[j][i]);
            AdjustProper(bref[j][i]);
        }
    //Recalculate nextidx
    fill(nextidx, nextidx + nLines, -1);
    for (int i = base; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            int k;
            k = fref[i][j];
            nextidx[k] = proper[bref[j][i]];
            k = fref[j][i];
            nextidx[k] = proper[bref[i][j]];
        }
}

inline bool Valid(int base, int i)
{
    if (CCW(p[base], p[L[i].u], p[L[i].v])) return true;
    return L[i].u == base;
}

void DFS(int base, int i)
{
    avail[i] = false;
    int j;
    j = neighbor[i];
    if (j >= 0 && Valid(base, j) && avail[j])
        DFS(base, j);
    j = nextidx[i];
    if (j >= 0 && Valid(base, j) && avail[j])
        DFS(base, j);
    TopoList[nTopoList++] = i;
}

void Relax(int base, int i)
{
    int j;
    j = neighbor[i];
    if (j >= 0 && Valid(base, j))
        Maximize(f[L[j].u][L[j].v], f[L[i].u][L[i].v]);
    j = nextidx[i];
    if (j >= 0 && Valid(base, j))
        Maximize(f[L[j].u][L[j].v], f[L[i].u][L[i].v] + 1);
}

int Optimization(int base)
{
    int i = first[base];
    fill(begin(f[base]), end(f[n - 1]), 0);
    f[L[i].u][L[i].v] = 1;
    for (int i = nTopoList - 1; i >= 0; i--)
        Relax(base, TopoList[i]);
    int res = 0;
    for (int i = base; i < n; i++)
        for (int j = base; j < n; j++)
            if (CCW(p[base], p[i], p[j]))
                Maximize(res, f[i][j]);
    return res + 1;
}

int Solve1(int base)
{
    InitByBase(base);
    nTopoList = 0;
    fill(begin(avail), end(avail), true);
    DFS(base, first[base]);
    return Optimization(base);
}

void Solve()
{
    int res = 3, res1;
    for (int base = 0; base < n - 3; base++)
    {
        if (n - base <= res) break;
        res1 = Solve1(base);
        if (res1 > res) res = res1;
    }
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(TASKNAME".INP", "r", stdin);
    freopen(TASKNAME".OUT", "w", stdout);
    Enter();
    Init();
    Solve();
}
