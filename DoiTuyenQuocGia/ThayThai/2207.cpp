#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 200005
#define pii pair<int,int>
#define fi first
#define se second
#define INF 1e18
#define ll long long
using namespace std;

struct edge
{
    int u,v,id;
    ll w;
} e[maxn];

int n,m,P[maxn],h[maxn];
int st[maxn],ed[maxn],cnt = 0,d[maxn];
int p[maxn][25];
ll maxc[maxn][25];

bool used[maxn];
pair<pii,ll> c[maxn];
vector<pair<int,ll> > a[maxn];

bool cmp(edge x,edge y)
{
    return x.w < y.w;
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
    if(h[x] < h[y])
        P[x] = y;
    else
    {
        P[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

void dfs(int u,int parent)
{
   st[u] = ++cnt;
   For(i,1,19) p[u][i] = p[p[u][i-1]][i-1];
   For(i,1,19) maxc[u][i] = max(maxc[u][i-1],maxc[p[u][i-1]][i-1]);
   Forv(i,a[u])
   {
       int v = a[u][i].fi;
       ll w = a[u][i].se;
       if(v == parent) continue;
       p[v][0] = u;
       maxc[v][0] = w;
       dfs(v,u);
   }
   ed[u] = cnt;
}

bool chklca(int u,int v)
{
    return (st[u] <= st[v] && ed[u] >= ed[v]);
}

int lca(int u,int v)
{
    if(chklca(u,v)) return u;
    Forr(i,19,0) if(p[u][i] && !chklca(p[u][i],v)) u = p[u][i];
    return p[u][0];
}

ll Findmax(int u,int lca)
{
    ll test = 0;
    Forr(i,19,0)
        if(chklca(lca,p[u][i]))
        {
            test = max(test,maxc[u][i]);
            u = p[u][i];
        }
    return test;
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d%d",&n,&m);
    For(i,1,m)
    {
        scanf("%d%d%lld",&e[i].u,&e[i].v,&e[i].w);
        e[i].id = i;
        c[i] = {{e[i].u,e[i].v},e[i].w};
    }
    sort(e+1,e+1+m,cmp);
    For(i,1,n) make_set(i);
    ll cur_ans = 0;
    int canh = 0;
    For(i,1,m)
    {
        if(Union(e[i].u,e[i].v))
        {
            a[e[i].u].push_back({e[i].v,e[i].w});
            a[e[i].v].push_back({e[i].u,e[i].w});
            used[e[i].id] = true;
            cur_ans += e[i].w;
            canh++;
            if(canh == n-1) break;
        }
    }
    dfs(1,0);
    ll ans = INF;
    For(i,1,m)
    {
        if(used[i]) continue;
        int u = c[i].fi.fi, v = c[i].fi.se;
        ll w = c[i].se;
        int s = lca(u,v);
        ll cur = max(Findmax(u,s),Findmax(v,s));
        ans = min(ans,cur_ans - cur + w);
    }
    cout << ans << endl;
}
