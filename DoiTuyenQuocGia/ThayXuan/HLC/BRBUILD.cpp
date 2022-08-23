#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,m,cnt = 0;
int s[maxn],d[maxn],p[maxn],e[maxn];
int head[maxn],heavy[maxn],pos[maxn],rpos[maxn];
int val[4*maxn];
vector<int> a[maxn];

void dfs(int u,int parent)
{
    s[u] = 1;
    int scmax = 0;
    for(int v : a[u])
    {
        if(v == parent) continue;
        p[v] = u;
        d[v] = d[u] + 1;
        e[v] = 1;
        dfs(v,u);
        s[u] += s[v];
        if(s[v] > scmax)
            heavy[u] = v,scmax = s[v];
    }
}

void hld(int u,int cur_head)
{
    head[u] = cur_head;
    pos[u] = ++cnt;
    if(heavy[u])
        hld(heavy[u],cur_head);
    for(int v : a[u])
        if(v != p[u] && v != heavy[u]) hld(v,v);
}

void init(int node,int l,int r)
{
    if(l == r)
    {
        val[node] = 1;
        return;
    }
    int c = (l+r)/2;
    init(2*node,l,c);
    init(2*node+1,c+1,r);
    val[node] = val[2*node] + val[2*node+1];
}

void update(int node,int l,int r,int i)
{
    if(l > i || r < i) return;
    if(l == i && r == i)
    {
        val[node] = 0;
        return;
    }
    int c = (l+r)/2;
    update(2*node,l,c,i);
    update(2*node+1,c+1,r,i);
    val[node] = val[2*node] + val[2*node + 1];
}

int get(int node,int l,int r,int i,int j)
{
    if(i > j) return 0;
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return val[node];
    int c = (l+r)/2;
    return get(2*node,l,c,i,j) + get(2*node+1,c+1,r,i,j);
}

int get_sum(int u,int v)
{
    int ans = 0;
    for(; head[u] != head[v];u = p[head[u]])
    {
        if(d[head[u]] < d[head[v]]) swap(u,v);
        ans += get(1,1,n,pos[head[u]],pos[u]);
    }
    if(pos[u] > pos[v]) swap(u,v);
    ans += get(1,1,n,pos[u] + 1,pos[v]);
    return ans;
}

int main()
{
    freopen("BRBUILD.inp","r",stdin);
    freopen("BRBUILD.out","w",stdout);
    scanf("%d",&n);
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
    scanf("%d",&m);
    For(i,1,m+n-1)
    {
        char type;
        int u,v;
        scanf(" %c",&type);
        if(type == 'A')
        {
            scanf("%d%d",&u,&v);
            int id = (u == p[v]) ? v : u;
            update(1,1,n,pos[id]);
        }
        else
        {
            scanf("%d",&u);
            printf("%d\n",get_sum(1,u));
        }
    }
}
