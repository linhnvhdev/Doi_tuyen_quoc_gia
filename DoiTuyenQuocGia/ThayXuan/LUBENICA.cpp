#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,k;
ll p[maxn][22],d[maxn],vmax[maxn][22],vmin[maxn][22];

vector<pair<int,ll> > a[maxn];

void dfs(int u,int parent)
{
    Forv(i,a[u])
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        if(v == parent) continue;
        p[v][0] = u;
        d[v] = d[u] + 1;
        vmax[v][0] = vmin[v][0] = w;
        dfs(v,u);
    }
}

pair<ll,ll> lca(int u,int v)
{
    ll ansmin = INF,ansmax = -INF;
    if(d[u] < d[v]) swap(u,v);
    Forr(i,19,0)
        if(d[p[u][i]] >= d[v])
        {
            ansmin = min(ansmin,vmin[u][i]);
            ansmax = max(ansmax,vmax[u][i]);
            u = p[u][i];
        }
    if(u == v) return {ansmin,ansmax};
    Forr(i,19,0)
        if(p[u][i] != p[v][i])
        {
            ansmax = max(ansmax,max(vmax[u][i],vmax[v][i]));
            ansmin = min(ansmin,min(vmin[u][i],vmin[v][i]));
            u = p[u][i];
            v = p[v][i];
        }
    ansmin = min(ansmin,min(vmin[u][0],vmin[v][0]));
    ansmax = max(ansmax,max(vmax[u][0],vmax[v][0]));
    return {ansmin,ansmax};
}

int main()
{
    freopen("LUBENICA.inp","r",stdin);
    freopen("LUBENICA.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n-1)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    p[1][0] = 1;
    vmax[1][0] = -INF;
    vmin[1][0] = INF;
    dfs(1,0);
    For(j,1,19)
        For(i,1,n)
        {
            p[i][j] = p[p[i][j-1]][j-1];
            vmax[i][j] = max(vmax[i][j-1],vmax[p[i][j-1]][j-1]);
            vmin[i][j] = min(vmin[i][j-1],vmin[p[i][j-1]][j-1]);
        }
    scanf("%d",&k);
    For(i,1,k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        pair<ll,ll> ans = lca(u,v);
        //cerr << i << endl;
        printf("%lld %lld\n",ans.fi,ans.se);
    }
}
