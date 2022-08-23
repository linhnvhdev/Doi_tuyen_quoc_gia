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
int st[maxn],ed[maxn],d[maxn],nhan[maxn],p[maxn];
int val[4*maxn],add[4*maxn];
vector<int> a[maxn];

void dfs(int u,int parent)
{
    st[u] = ++cnt;
    nhan[cnt] = u;
    for(int v : a[u])
    {
        if(v == parent) continue;
        d[v] = d[u] + 1;
        p[v] = u;
        dfs(v,u);
    }
    ed[u] = cnt;
}
void init(int node,int l,int r)
{
    if(l == r)
    {
        val[node] = d[nhan[l]];
        return;
    }
    int c = (l+r)/2;
    init(2*node,l,c);
    init(2*node+1,c+1,r);
    val[node] = val[2*node] + val[2*node+1];
}

void down(int node,int d1,int d2)
{
    val[2*node] += add[node]*d1;
    val[2*node+1] += add[node]*d2;
    add[2*node] += add[node];
    add[2*node+1] += add[node];
    add[node] = 0;
}

void update(int node,int l,int r,int i,int j,int v)
{
    if(l > j || r < i) return;
    if(i <= l && r <= j)
    {
        val[node] += v*(r - l + 1);
        add[node] += v;
        return;
    }
    int c = (l+r)/2;
    down(node,c - l + 1,r - c);
    update(2*node,l,c,i,j,v);
    update(2*node+1,c+1,r,i,j,v);
    val[node] = val[2*node] + val[2*node + 1];
}

int get(int node,int l,int r,int i,int j)
{
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return val[node];
    int c = (l+r)/2;
    down(node,c - l + 1,r - c);
    return get(2*node,l,c,i,j) + get(2*node+1,c+1,r,i,j);
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
            update(1,1,n,st[id],ed[id],-1);
        }
        else
        {
            scanf("%d",&u);
            printf("%d\n",get(1,1,n,st[u],st[u]));
        }
    }
}
