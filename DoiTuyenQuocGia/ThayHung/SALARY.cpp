#include <bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define fi first
#define se second
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,m,st[maxn],ed[maxn],cnt = 0,p[maxn];

ll val[4*maxn],add[4*maxn],d[maxn];

vector<int> a[maxn];

void dfs(int u)
{
    st[u] = ++cnt;
    for(int v : a[u]) dfs(v);
    ed[u] = cnt;
}

void down(int node)
{
    val[2*node] += add[node];
    val[2*node+1] += add[node];
    add[2*node] += add[node];
    add[2*node+1] += add[node];
    add[node] = 0;
}

void update(int node,int l,int r,int i,int j,ll v)
{
    if(i > j) return;
    if(l > j || r < i) return;
    if(i <= l && r <= j)
    {
        val[node] += v;
        add[node] += v;
        return;
    }
    down(node);
    int c = (l+r)/2;
    update(2*node,l,c,i,j,v);
    update(2*node+1,c+1,r,i,j,v);
}

ll get(int node,int l,int r,int i)
{
    if(l > i || r < i) return 0ll;
    if(l == r) return val[node];
    down(node);
    int c = (l+r)/2;
    return get(2*node,l,c,i) + get(2*node+1,c+1,r,i);
}

int main()
{
    fast_read;
    freopen("SALARY.inp","r",stdin);
    freopen("SALARY.out","w",stdout);
    cin >> n >> m;
    cin >> d[1];
    For(i,2,n)
    {
        cin >> d[i] >> p[i];
        a[p[i]].push_back(i);
    }
    dfs(1);
    char type;
    int A;
    ll x;
    For(i,1,n)
        update(1,1,n,st[i],st[i],d[i]);
    For(i,1,m)
    {
        cin >> type;
        if(type == 'p')
        {
            cin >> A >> x;
            update(1,1,n,st[A]+1,ed[A],x);
        }
        else
        {
            cin >> A;
            cout << get(1,1,n,st[A]) << '\n';
        }
    }
}
