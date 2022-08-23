#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 400005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
using namespace std;

int n,k;
int s[maxn],head[maxn],heavy[maxn],d[maxn],p[maxn],pos[maxn],rpos[maxn];
ll e[maxn];
int cnt = 0;
ll valmax[4*maxn],valmin[4*maxn];

vector<pair<int,ll> > a[maxn];

void dfs(int u)
{
    s[u] = 1;
    int scmax = 0;
    Forv(i,a[u])
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        if(v == p[u]) continue;
        p[v] = u;
        d[v] = d[u] + 1;
        e[v] = w;
        dfs(v);
        s[u] += s[v];
        if(s[v] > scmax)
            scmax = s[v], heavy[u] = v;
    }
}

void hld(int u,int cur_head)
{
    head[u] = cur_head;
    pos[u] = ++cnt;
    rpos[cnt] = u;
    if(heavy[u])
        hld(heavy[u],cur_head);
    Forv(i,a[u])
    {
        int v = a[u][i].fi;
        if(v != p[u] && v != heavy[u]) hld(v,v);
    }
}

void init(int node,int l,int r)
{
    if(l == r)
    {
        valmax[node] = valmin[node] = e[rpos[l]];
        return;
    }
    int c = (l+r)/2;
    init(2*node,l,c);
    init(2*node+1,c+1,r);
    valmax[node] = max(valmax[2*node],valmax[2*node+1]);
    valmin[node] = min(valmin[2*node],valmin[2*node+1]);
}

ll getmax(int node,int l,int r,int i,int j)
{
    if(i > j) return -INF;
    if(l > j || r < i) return -INF;
    if(i <= l && r <= j) return valmax[node];
    int c = (l+r)/2;
    return max(getmax(2*node,l,c,i,j),getmax(2*node+1,c+1,r,i,j));
}

ll getmin(int node,int l,int r,int i,int j)
{
    if(i > j) return INF;
    if(l > j || r < i) return INF;
    if(i <= l && r <= j) return valmin[node];
    int c = (l+r)/2;
    return min(getmin(2*node,l,c,i,j),getmin(2*node+1,c+1,r,i,j));
}

pair<ll,ll> get_ans(int u,int v)
{
    ll ansmax = -INF,ansmin = INF;
    for(;head[u] != head[v]; u = p[head[u]])
    {
        if(d[head[u]] < d[head[v]]) swap(u,v);
        ansmax = max(ansmax,getmax(1,1,n,pos[head[u]],pos[u]));
        ansmin = min(ansmin,getmin(1,1,n,pos[head[u]],pos[u]));
    }
    //cerr << "# " << dem << endl;
    if(pos[u] < pos[v]) swap(u,v);
    ansmax = max(ansmax,getmax(1,1,n,pos[v] + 1,pos[u]));
    ansmin = min(ansmin,getmin(1,1,n,pos[v] + 1,pos[u]));
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
    dfs(1);
    hld(1,1);
    init(1,1,n);
    //For(i,1,n) cerr << i << ' '  << pos[i]<<' ' <<  head[i] << endl;
    scanf("%d",&k);
    For(i,1,k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        pair<ll,ll> ans = get_ans(u,v);
        printf("%lld %lld\n",ans.fi,ans.se);
    }
}
