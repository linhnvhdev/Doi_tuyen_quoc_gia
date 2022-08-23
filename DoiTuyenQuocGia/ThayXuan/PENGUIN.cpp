#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 30005
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define pii pair<int,int>
using namespace std;

struct query
{
    int type,u,v;
} q[300005],ans[300005];

int n,m,Q,d[maxn],e[maxn],p[maxn],h[maxn];
int parent[maxn][25],st[maxn],ed[maxn],cnt = 0,root;
ll val[4*maxn],add[4*maxn];

vector<int> a[maxn];

void make_set(int i)
{
    p[i] = i;
    h[i] = 0;
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

bool Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    if(h[x] < h[y]) p[x] = y;
    else
    {
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

void dfs(int u)
{
    st[u] = ++cnt;
    For(i,1,19) parent[u][i] = parent[parent[u][i-1]][i-1];
    for(int v : a[u])
    {
        if(v == parent[u][0]) continue;
        parent[v][0] = u;
        dfs(v);
    }
    ed[u] = cnt;
}

bool chklca(int u,int v)
{
    return(st[u] <= st[v] && ed[u] >= ed[v]);
}

int lca(int u,int v)
{
    if(chklca(u,v)) return u;
    Forr(i,19,0) if(parent[u][i] && !chklca(parent[u][i],v)) u = parent[u][i];
    return parent[u][0];
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
        val[node] += (r - l + 1)*v;
        add[node] += v;
        return;
    }
    int c = (l+r)/2;
    down(node,c-l+1,r-c);
    update(2*node,l,c,i,j,v);
    update(2*node+1,c+1,r,i,j,v);
    val[node] = val[2*node] + val[2*node+1];
}

ll get(int node,int l,int r,int i,int j)
{
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return val[node];
    int c = (l+r)/2;
    down(node,c-l+1,r-c);
    return get(2*node,l,c,i,j) + get(2*node+1,c+1,r,i,j);
}

ll get_path(int u,int v)
{
    int s = lca(u,v);
    return get(1,1,n,st[u],st[u]) + get(1,1,n,st[v],st[v]) - 2*get(1,1,n,st[s],st[s]) + e[s];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PENGUIN.inp","r",stdin);
    freopen("PENGUIN.out","w",stdout);
    cin >> n;
    For(i,1,n) cin >> e[i];
    cin >> Q;
    string S;
    For(i,1,n) make_set(i);
    For(i,1,Q)
    {
        cin >> S >> q[i].u >> q[i].v;
        if(S[0] == 'e')
        {
            q[i].type = 3;
            if(Find(q[i].u) != Find(q[i].v))
                ans[i].u = -1;
            else ans[i].u = 1;
        }
        if(S[0] == 'b') q[i].type = 1;
        if(S[0] == 'p') q[i].type = 2;
        if(S[0] == 'b')
        {
            if(Union(q[i].u,q[i].v))
            {
                root = q[i].u;
                a[q[i].u].push_back(q[i].v);
                a[q[i].v].push_back(q[i].u);
                ans[i].u = 1;
            }
            else ans[i].u = -1;
        }
        ans[i].type = q[i].type;
    }
    For(i,1,n-1)
        if(Union(i,i+1))
        {
            a[i].push_back(i+1);
            a[i+1].push_back(i);
        }
    dfs(1);
    For(i,1,n) update(1,1,n,st[i],ed[i],e[i]);
    //For(i,1,n) cerr << i << ' ' << st[i] << ' ' << ed[i] << ' ' << get(1,1,n,st[i],st[i]) << endl;
    For(i,1,Q)
    {
        if(q[i].type == 1)
        {
            if(ans[i].u == 1) cout << "yes\n";
            else cout << "no\n";
        }
        if(q[i].type == 2)
        {
            int u = q[i].u;
            int c = q[i].v;
            update(1,1,n,st[u],ed[u],c - e[u]);
            e[u] = c;
        }
        if(q[i].type == 3)
        {
            if(ans[i].u == -1)
                cout << "impossible\n";
            else
                cout << get_path(q[i].u,q[i].v) << '\n';
        }
    }
}
