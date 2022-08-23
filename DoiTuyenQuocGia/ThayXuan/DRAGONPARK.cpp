#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,q,st[maxn],ed[maxn],cnt = 0,p[maxn][20];
ll e[maxn],val[4*maxn],add[4*maxn];

int nhan[maxn];

vector<int> a[maxn];

void dfs(int u,int parent)
{
    st[u] = ++cnt;
    nhan[cnt] = u;
    For(i,1,19) p[u][i] = p[p[u][i-1]][i-1];
    for(int v : a[u])
    {
        if(v == parent) continue;
        p[v][0] = u;
        dfs(v,u);
    }
    ed[u] = cnt;
}

void down(int node,int d1,int d2)
{
    if(d1 % 2 == 1) val[2*node] ^= add[node];
    if(d2 % 2 == 1) val[2*node+1] ^= add[node];
    add[2*node] ^= add[node];
    add[2*node+1] ^= add[node];
    add[node] = 0;
}

void update(int node,int l,int r,int i,int j,ll v)
{
    if(l > j || r < i) return;
    if(i <= l && r <= j)
    {
        if((r - l + 1) % 2 == 1) val[node] ^= v;
        add[node] ^= v;
        return;
    }
    int c = (l+r)/2;
    down(node,c - l + 1,r - c);
    update(2*node,l,c,i,j,v);
    update(2*node+1,c+1,r,i,j,v);
    val[node] = val[2*node] ^ val[2*node+1];
}

ll get(int node,int l,int r,int i,int j)
{
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return val[node];
    int c = (l+r)/2;
    down(node,c - l + 1,r - c);
    return get(2*node,l,c,i,j) ^ get(2*node+1,c+1,r,i,j);
}

bool chklca(int u,int v)
{
    return(st[u] <= st[v] && ed[u] >= ed[v]);
}

int lca(int u,int v)
{
    if(chklca(u,v)) return u;
    Forr(i,19,0) if(p[u][i] && !chklca(p[u][i],v)) u = p[u][i];
    return p[u][0];
}

int main()
{
    freopen("DRAGONPARK.inp","r",stdin);
    freopen("DRAGONPARK.out","w",stdout);
    scanf("%d%d",&n,&q);
    For(i,1,n)
        scanf("%lld",&e[i]);
    For(i,1,n-1)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    For(u,1,n) update(1,1,n,st[u],ed[u],e[u]);
    while(q--)
    {
        int type,u,v;
        scanf("%d%d%d",&type,&u,&v);
        if(type == 1)
        {
            update(1,1,cnt,st[u],ed[u],e[u]);
            e[u] = v;
            update(1,1,cnt,st[u],ed[u],e[u]);
        }
        else
        {
            int s = lca(u,v);
            ll ans = 0;
            ans = get(1,1,cnt,st[u],st[u]) ^ get(1,1,cnt,st[v],st[v]) ^ e[s];
            printf("%lld\n",ans);
        }
    }
}
