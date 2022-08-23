#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Ford(i,a,b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
#define maxN 100005
#define Bit(x, i) ((x >> i) & 1)
using namespace std;
struct data
{
    int x, y, val;
}d[maxN];
int n, m, cnt = 0, par[maxN], h[maxN];
int p[maxN][25], dmin[maxN][25], id = 0, be[maxN], en[maxN];
vector<data>out;
vector<pii>edge[maxN];
ll ans = 0;
void Make_set(int i)
{
    par[i] = i;
    h[i] = 0;
}
int Find(int i)
{
    while(i != par[i])i = par[i];
    return i;
}
bool Union(int i, int j)
{
    int x = Find(i), y = Find(j);
    if(x == y)return false;
    if(h[x] < h[y])par[x] = y;
    else
    {
        par[y] = x;
        if(h[x] == h[y])h[x]++;
    }
    return true;
}
bool cmp(data u, data v)
{
    return u.val > v.val;
}

void dfs(int u, int parent)
{
    be[u] = ++id;
    For(i,1,20)
    {
        p[u][i] = p[p[u][i - 1]][i - 1];
        dmin[u][i] = min(dmin[u][i - 1], dmin[p[u][i - 1]][i - 1]);
    }
    for(pii c : edge[u])
    {
        int v = c.fi, w = c.se;
        if(v == parent)continue;
        p[v][0] = u;
        dmin[v][0] = w;
        dfs(v, u);
    }
    en[u] = id;
}
bool Check(int u, int v)
{
    return (be[u] <= be[v] && en[v] <= en[u]);
}
int Lca(int u, int v)
{
    if(Check(u, v))return u;
    Ford(i,20,0)
        if(p[u][i] && !Check(p[u][i], v))u = p[u][i];
    return p[u][0];
}
ll Get(data cur)
{
    int u = cur.x, v = cur.y, r = Lca(u, v), tmp = 1e9;
    Ford(i,20,0)
        if(p[u][i] && Check(r, p[u][i]))
        {
            tmp = min(tmp, dmin[u][i]);
            u = p[u][i];
        }
    Ford(i,20,0)
        if(p[v][i] && Check(r, p[v][i]))
        {
            tmp = min(tmp, dmin[v][i]);
            v = p[v][i];
        }
    return 1ll * (tmp - cur.val);
}
int main()
{
    scanf("%d%d", &n, &m);
    For(i,1,m)
        scanf("%d%d%d", &d[i].x, &d[i].y, &d[i].val);
    sort(d + 1, d + 1 + m, cmp);
    For(i,1,n)Make_set(i);
    For(i,1,m)
    {
        int u = d[i].x, v = d[i].y, w = d[i].val;
        if(Union(u, v) && cnt < n - 1)
        {
            cnt++;
            edge[u].push_back({v, w});
            edge[v].push_back({u, w});
        }
        else
            out.push_back(d[i]);
    }
    dfs(1, 0);
    for(data cur : out)
        ans += Get(cur);
    printf("%lld", ans);
}
