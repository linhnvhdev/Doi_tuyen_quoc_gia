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

int n,q,cnt = 0,p[maxn],d[maxn];
ll e[maxn],val[4*maxn],add[4*maxn];
int head[maxn],heavy[maxn],s[maxn],pos[maxn];

int nhan[maxn];

vector<int> a[maxn];

void init(int node,int l,int r)
{
    if(l == r)
    {
        val[node] = e[nhan[l]];
        return;
    }
    int c = (l+r)/2;
    init(2*node,l,c);
    init(2*node+1,c+1,r);
    val[node] = val[2*node] ^ val[2*node+1];
}

void update(int node,int l,int r,int i,int j,ll v)
{
    if(l > j || r < i) return;
    if(i <= l && r <= j)
    {
        val[node] ^= v;
        return;
    }
    int c = (l+r)/2;
    update(2*node,l,c,i,j,v);
    update(2*node+1,c+1,r,i,j,v);
    val[node] = val[2*node] ^ val[2*node+1];
}

ll get(int node,int l,int r,int i,int j)
{
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return val[node];
    int c = (l+r)/2;
    return get(2*node,l,c,i,j) ^ get(2*node+1,c+1,r,i,j);
}

void dfs(int u,int parent)
{
    s[u] = 1;
    int sconmax = 0;
    for(int v : a[u])
    {
        if(v == parent) continue;
        p[v] = u;
        d[v] = d[u] + 1;
        dfs(v,u);
        s[u] += s[v];
        if(s[v] > sconmax)
            heavy[u] = v, sconmax = s[v];
    }
}

void hld(int u,int cur_head)
{
    head[u] = cur_head; pos[u] = ++cnt;
    nhan[cnt] = u;
    if(heavy[u])
        hld(heavy[u],cur_head);
    for(int v : a[u])
        if(v != p[u] && v != heavy[u])
            hld(v,v);
}

ll get_sum(int u,int v)
{
    ll tmp = 0;
    for(; head[u] != head[v]; u = p[head[u]])
    {
        if(d[head[u]] < d[head[v]]) swap(u,v);
        tmp ^= get(1,1,n,pos[head[u]],pos[u]);
    }
    if(pos[u] > pos[v]) swap(u,v);
    tmp ^= get(1,1,n,pos[u],pos[v]);
    return tmp;
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
    hld(1,1);
    init(1,1,n);
    while(q--)
    {
        int type,u,v;
        scanf("%d%d%d",&type,&u,&v);
        if(type == 1)
        {
            update(1,1,n,pos[u],pos[u],e[u]);
            e[u] = v;
            update(1,1,n,pos[u],pos[u],e[u]);
        }
        else
            printf("%lld\n",get_sum(u,v));
    }
}
