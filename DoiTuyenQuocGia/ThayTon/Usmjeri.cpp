#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a; i >= b; --i)
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define maxn 300005
#define Bit(i,j) ((j>>i) &1 )
using namespace std;

const ll mod = 1e9 + 7;
int n,m,st[maxn],ed[maxn] , p[maxn][21],cnt = 0,color[maxn];
int low[maxn];
int d[maxn];
vector<int > e [maxn];
ll ans = 1 ;
bool vs[maxn];
vector<pair<int,int> > edge [maxn]  ;

void dfs(int u,int parent)
{
    st[u] = ++cnt;
    For(i,1,19) p[u][i] = p[p[u][i-1]][i-1];
    for(int v :e[u])
    {
        if(v == parent ) continue;
        p[v][0] = u;
        d[v] = d[u] + 1;
        dfs(v,u);
    }
    ed[u] = cnt;
}

bool chklca(int u ,int v)
{
    return(st[v] >= st[u] && ed[v] <= ed[u]) ;
}

int LCA(int u,int v)
{
    if(chklca(u,v)) return u;
    Forr(i,19,0)
        if(p[u][i] && !chklca(p[u][i],v)) u = p[u][i];
    return p[u][0];
}

void duyet(int u,int parent,int mau)
{
    vs[u] = true;
    if(color[u])
    {
        if(mau != color[u])
        {
            cout<<"0";
            exit(0);
        }
        return;
    }
    color[u] = mau;
    for(pii cur : edge[u])
    {
        int v = cur.fi ;
        int w = cur.se ;
        if(v == parent) continue ;
        if(w == 1) duyet(v,u,mau);
        else duyet(v,u,-1*mau);
    }
}

int DFS(int u,int parent)
{
    for(int v : e[u])
    {
        if(v == parent) continue;
        int tmp = DFS(v,u);
        low[u] = min(low[u],tmp);
        if(tmp < d[u])
        {
            edge[u].push_back({v,1});
            edge[v].push_back({u,1});
        }
    }
    return low[u];
}

int main ()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("usmjeri.inp","r",stdin);
    freopen("usmjeri.out","w",stdout);
    cin>>n>>m;
    For(i,1,n-1)
    {
        int u ,v ;
        cin>> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1,0);
    For(i,1,n) low[i] = d[i];
    For(i,1,m)
    {
        int u ,v ;
        cin>> u >> v;
        int lca = LCA(u,v);
        low[u] = min(low[u],d[lca]);
        low[v] = min(low[v],d[lca]);
        if(u != lca && v != lca)
        {
            edge[u].push_back({v,-1});
            edge[v].push_back({u,-1});
        }
    }
    DFS(1,0);
    For(i,2,n)
    {
        if(vs[i]) continue;
        duyet(i,0,1);
        ans = (ans * 2) %mod;
    }
    cout<<ans ;
}
