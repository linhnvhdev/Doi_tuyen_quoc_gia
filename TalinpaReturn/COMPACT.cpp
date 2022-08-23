


#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxN 100005
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, m, a[10 * maxN], mina[4 * maxN], maxa[4 * maxN], d[5005][5005];
bool ok[5005][5005];
int trc[maxN], f[maxN];
pii p[10 * maxN];

void Find(int cur)
{
    if(cur == 0)return;
    Find(trc[cur]);
    printf("%d ", cur);
}

void Update(int node, int l, int r, int i, int j, int val)
{
    if(l == i && r == j)
    {
        mina[node] = maxa[node] = val;
        return;
    }
    int c = (r + l) / 2, p1 = 2 * node + 1, p2 = 2 * node + 2;
    if(i <= c) Update(p1, l, c, i, min(j, c), val);
    if(c < j) Update(p2, c + 1, r, max(c + 1, i), j, val);
    mina[node] = min(mina[p1], mina[p2]);
    maxa[node] = max(maxa[p1], maxa[p2]);
}

int GetMin(int node, int l, int r, int i, int j)
{
    if(l == i && r == j)
        return mina[node];
    int c = (r + l) / 2, p1 = 2 * node + 1, p2 = 2 * node + 2, cur = 1e9;
    if(i <= c)cur = min(cur, GetMin(p1, l, c, i, min(j, c)));
    if(c < j)cur = min(cur, GetMin(p2, c + 1, r, max(c + 1, i), j));
    return cur;
}

int GetMax(int node, int l, int r, int i, int j)
{
    if(l == i && r == j)
        return maxa[node];
    int c = (r + l) / 2, p1 = 2 * node + 1, p2 = 2 * node + 2, cur = 0;
    if(i <= c)cur = max(cur, GetMax(p1, l, c, i, min(j, c)));
    if(c < j)cur = max(cur, GetMax(p2, c + 1, r, max(c + 1, i), j));
    return cur;
}

void Add(int id, int pos, int val)
{
    for(int i = pos ; i <= m+1; i += (i & (-i)))
        d[id][i] += val;
}

int Get(int id, int pos)
{
    int tmp = 0;
    for(int i = pos;i > 0;i -= (i&(-i)))
        tmp += d[id][i];
    return tmp;
}

bool Check(int i, int j)
{
    int minc = GetMin(1, 1, n, i, j), maxc = GetMax(1, 1, n, i, j);
    if(i > 1)
        if(Get(i - 1, maxc) - Get(i - 1, minc-1) != 0)return false;
    if(j < n)
    {
        int tmp = Get(n, maxc) - Get(n, minc-1);
        int cur = Get(j, maxc) - Get(j, minc-1);
        if(tmp - cur != 0)return false;
    }
    return true;
}

void Sub12()
{
    For(j,1,n)
        For(i,1,j)
            Add(j, a[i], 1);
    For(i,1,n)f[i] = -1e9;
    For(i,1,n)
        For(j,i,n)
            if(Check(i, j))
            {
                ok[i][j] = true;
                if(i == 1 && ok[i][j])f[j] = 1;
            }
    For(i,1,n)
        For(j,0,i - 1)
            if(ok[j + 1][i] && f[j] + 1 > f[i])
            {
                f[i] = f[j] + 1;
                trc[i] = j;
            }
    printf("%d\n", f[n]);
    Find(n);
}

void Test()
{
    printf("1\n");
    printf("%d", n);
}

int main()
{
    freopen("compact.inp", "r", stdin);
    freopen("compact.out", "w", stdout);
    scanf("%d%d", &n, &m);
    For(i,1,n)
    {
        scanf("%d", &a[i]);
        Update(1, 1, n, i, i, a[i]);
    }
    if(n <= 5000)Sub12();
    else
        Test();
}
