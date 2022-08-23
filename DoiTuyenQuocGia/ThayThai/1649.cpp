#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int P[maxn],h[maxn],st[maxn],ed[maxn],minc[maxn][20],p[maxn][20],cnt = 0;

struct edge
{
    int u,v;
    ll w;
} e[maxn];

int n,m;

vector<pair<int,ll> > adj[maxn];

bool cmp(edge x,edge y)
{
    return x.w > y.w;
}

void make_set(int i)
{
    P[i] = i;
    h[i] = 0;
}

int Find(int i)
{
    while(i != P[i]) i = P[i];
    return i;
}

bool Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    if(h[x] < h[y]) P[x] = y;
    else
    {
        P[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

vector<edge> out;

void dfs(int u,int parent)
{
    //cout << u << ' ' << parent << endl;
    st[u] = ++cnt;
    For(i,1,19) p[u][i] = p[p[u][i-1]][i-1];
    For(i,1,19) minc[u][i] = min(minc[u][i-1],minc[p[u][i-1]][i-1]);
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i].fi;
        ll w = adj[u][i].se;
        if(v == parent) continue;
        p[v][0] = u;
        minc[v][0] = w;
        dfs(v,u);
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

int get(int u,int v)
{
    int s = lca(u,v);
    ll tmp = INF;
    Forr(i,19,0)
        if(p[u][i] && chklca(s,p[u][i]))
        {
            tmp = min(tmp,1ll*minc[u][i]);
            u = p[u][i];
        }
    Forr(i,19,0)
        if(p[v][i] && chklca(s,p[v][i]))
        {
            tmp = min(tmp,1ll*minc[v][i]);
            v = p[v][i];
        }
    return tmp;
}

int main()
{
    scanf("%d%d",&n,&m);
    For(i,1,m)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        e[i] = {u,v,w};
    }
    sort(e+1,e+1+m,cmp);
    For(i,1,n) make_set(i);
    For(i,1,m)
    {
        int u = e[i].u,v = e[i].v;
        ll w = e[i].w;
        if(Union(u,v))
        {
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        else out.push_back(e[i]);
    }
    dfs(1,0);
    ll ans = 0;
    for(edge x : out)
        ans += get(x.u,x.v) - x.w;
    cout << ans << endl;
}
