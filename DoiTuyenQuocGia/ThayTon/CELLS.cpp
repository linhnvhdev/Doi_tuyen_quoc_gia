#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Ford(i,a,b) for(int i = a; i >= b; --i)
#define Bit(x, i) ((x >> i) & 1)
#define maxN 5005
#define debug(a, b) cout<<a<<" "<<b
#define MAX 1000005
#define ll long long
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct data
{
    int x, y, id;
} d[MAX];

int m, n, k, a[maxN][maxN],  minc[MAX], maxc[MAX], minh[MAX], maxh[MAX];
char s;
int cnt = 0;
ll tree[4 * MAX], ans = 0;
struct event
{
    int id, sta, fi, se;
} p[MAX];

vector<int> cot, hang;

void Sub1()
{
    ans = 0;
    For(i,1,k)
    {
        int idx = d[i].x, idy = d[i].y;
        while(true)
        {
            a[idx][idy] = 1;
            int u = idx + dx[d[i].id], v = idy + dy[d[i].id];
            if(u < 0 || u > m || v < 0 || v > n)break;
            idx = u; idy = v;
        }
    }
    For(i,0,m)
        For(j,0,n)
            if(a[i][j])ans++;
    cout<<ans;
}

bool Check(int u, int v)
{
    if(maxc[v] < u && u < minc[v])return false;
    if(maxh[u] < v && v < minh[u])return false;
    return true;
}

bool cmp (event X, event Y)
{
    if(X.id != Y.id)return X.id < Y.id;
    if(X.sta != Y.sta)return X.sta > Y.sta;
    return X.fi < Y.fi;
}

void Update(int id, int l, int r, int i, int val)
{
    if(i < l || r < i)return;
    if(l == r)
    {
        tree[id] += 1ll * val;
        return;
    }
    int c = (r + l) / 2, p1 = 2 * id, p2 = 2 * id + 1;
    Update(p1, l, c, i, val);
    Update(p2, c + 1, r, i, val);
    tree[id] = tree[p1] + tree[p2];
}

int Get(int id, int l, int r, int i, int j)
{
    if(j < l || r < i)return 0;
    if(i <= l && r <= j)return tree[id];
    int c = (r + l) / 2, p1 = 2 * id, p2 = 2 * id + 1;
    return Get(p1, l, c, i, j) + Get(p2, c + 1, r, i, j);
}

void Sub2()
{
    For(i,0,m)
    {
        minh[i] = n + 1;
        maxh[i] = -1;
    }
    For(i,0,n)
    {
        minc[i] = m + 1;
        maxc[i] = -1;
    }
    ans = 0;
    For(i,1,k)
    {
        int u = d[i].x, v = d[i].y;
        if(d[i].id % 2 == 0)
        {
            cot.push_back(v);
            if(d[i].id == 0)minc[v] = min(minc[v], u);
            else
                maxc[v] = max(maxc[v], u);
        }
        else
        {
            hang.push_back(u);
            if(d[i].id == 1)minh[u] = min(minh[u], v);
            else
                maxh[u] = max(maxh[u], v);
        }
    }
    sort(hang.begin(), hang.end());
    sort(cot.begin(), cot.end());
    hang.resize(unique(hang.begin(), hang.end()) - hang.begin());
    cot.resize(unique(cot.begin(), cot.end()) - cot.begin());
    For(i,0,m)
    {
        int cur = minh[i] <= maxh[i] ? n + 1 : n + 1 - (minh[i] - maxh[i] - 1);
        ans += cur;
    }
    For(i,0,n)
    {
        int cur = minc[i] <= maxc[i] ? m + 1 : m + 1 - (minc[i] - maxc[i] - 1);
        ans += cur;
    }
//    for(int u : hang)
//        for(int v : cot)
//            if(Check(u, v))ans--;
//      //Sub2()
    For(i,0,m)
    {
        if(minh[i] <= maxh[i])
        {
            p[++cnt] = {0, 1, i ,0};
            p[++cnt] = {n, -1, i, 0};
        }
        else
        {
            if(minh[i] != n + 1)
            {
                p[++cnt] = {minh[i], 1, i, 0};
                p[++cnt] = {n, -1, i, 0};
            }
            if(maxh[i] != -1)
            {
                p[++cnt] = {0, 1, i, 0};
                p[++cnt] = {maxh[i], -1, i, 0};
            }
        }
    }
    For(i,0,n)
    {
        if(minc[i] <= maxc[i])p[++cnt] = {i, 0, 0, m};
        else
        {
            if(minc[i] != m + 1)p[++cnt] = {i, 0, minc[i], m};
            if(maxc[i] != -1)p[++cnt] = {i, 0, 0, maxc[i]};
        }
    }
    sort(p+1,p+1+cnt,cmp);
    For(i,1,cnt)
    {
        if(p[i].sta == 0)
        {
            int u = p[i].fi, v = p[i].se;
            ans -= Get(1, 0, m, u, v);
        }
        else
        {
            int vt = p[i].fi, add = p[i].sta;
            Update(1, 0, m, vt, add);
        }
    }
    cout<<ans;
}
int main()
{
    freopen("cells.inp", "r", stdin);
    freopen("cells.out", "w", stdout);
    fast_read;
    cin>>m>>n;
    cin>>k;
    For(i,1,k)
    {
        cin>>d[i].x>>d[i].y>>s;
        if(s == 'N')d[i].id = 0; if(s == 'E')d[i].id = 1;
        if(s == 'S')d[i].id = 2; if(s == 'W')d[i].id = 3;
    }
    Sub2();
}
