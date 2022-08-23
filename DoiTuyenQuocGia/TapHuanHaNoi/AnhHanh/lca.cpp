/// Code nay duoc sinh ra chi de quay xo so :)
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 70005
#define ll long long
#define INF 1e9
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n,q,p[maxn][25],cnt = 0,st[maxn],ed[maxn];
int val[4*maxn];

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
    return (st[u] <= st[v] && ed[u] >= ed[v]);
}

int lca(int u,int v)
{
    if(u == -INF) return v;
    if(v == -INF) return u;
    if(chklca(u,v)) return u;
    Forr(i,19,0) if(p[u][i] && !chklca(p[u][i],v)) u = p[u][i];
    return p[u][0];
}

void build(int s,int l,int r)
{
    if(l == r)
    {
        val[s] = l;
        return;
    }
    int c = (l+r)/2;
    build(2*s,l,c);
    build(2*s+1,c+1,r);
    val[s] = lca(val[2*s],val[2*s+1]);
}

int get(int s,int l,int r,int i,int j)
{
    if(l > j || r < i) return -INF;
    if(i <= l && r <= j) return val[s];
    int c = (l+r)/2;
    return lca(get(2*s,l,c,i,j),get(2*s+1,c+1,r,i,j));
}

int main()
{
    fast_read;
    freopen("lca.inp","r",stdin);
    freopen("lca.out","w",stdout);
    cin >> n >> q;
    For(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1);
    build(1,1,n);
    For(i,1,q)
    {
        int u,v;
        cin >> u >> v;
        cout << get(1,1,n,u,v) << '\n';
    }
}
