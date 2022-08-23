#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define INF 1e9
using namespace std;

int m,n,p[maxn][25],st[maxn],ed[maxn],cnt = 0,d[maxn],ans = 0;

vector<int> a[maxn];

void dfs(int u)
{
    st[u] = ++cnt;
    For(i,1,19) p[u][i] = p[p[u][i-1]][i-1];
    for(int v : a[u])
    {
        if(v == p[u][0]) continue;
        p[v][0] = u;
        dfs(v);
    }
    ed[u] = cnt;
}

bool chklca(int u,int v)
{
    return st[u] <= st[v] && ed[u] >= ed[v];
}

int lca(int u,int v)
{
    if(chklca(u,v)) return u;
    Forr(i,19,0) if(p[u][i] && !chklca(p[u][i],v)) u = p[u][i];
    return p[u][0];
}

void dfs2(int u)
{
    for(int v : a[u])
    {
        if(v == p[u][0]) continue;
        dfs2(v);
        d[u] += d[v];
    }
    if(d[u] > 0) ans++;
}

int main()
{
    fast_read;
    freopen("CHECKNET.inp","r",stdin);
    freopen("CHECKNET.out","w",stdout);
    cin >> n >> m;
    For(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    For(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
        d[lca(u,v)] -= 2;
    }
    dfs2(1);
    cout << ans << endl;
}
