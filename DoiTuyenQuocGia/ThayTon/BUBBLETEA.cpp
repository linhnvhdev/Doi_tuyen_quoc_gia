#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 50005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
#define x fi
#define y second
#define lf double
using namespace std;

int n,k,cnt = 0,c[maxn],p[maxn][25],st[maxn],ed[maxn];
ll d[maxn];

vector<pair<int,ll> >a[maxn];

void dfs(int u,int parent)
{
    st[u] = ++cnt;
    For(i,1,19) p[u][i] = p[p[u][i-1]][i-1];
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        if(v == parent) continue;
        p[v][0] = u;
        d[v] = d[u] + w;
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

ll dist(int u,int v)
{
    return d[u] + d[v] - 2*d[lca(u,v)];
}

int x[maxn],g[maxn],dem = 0;
bool used[maxn];
ll ans = INF;

void dfscheck(int u,int parent)
{
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        if(v == parent) continue;
        dfscheck(v,u);
        g[u] += g[v];
    }
}


bool check()
{
    For(i,1,n) g[i] = 0;
    For(i,1,k)
        For(j,i+1,k)
        {
            if(x[i] == x[j])
            {
                int u = c[i],v = c[j];
                g[u]++;
                g[v]++;
                g[lca(u,v)] -= 2;
            }
        }
    dfscheck(1,0);
    For(i,1,n)
        if(g[i] > 1) return false;
    return true;
}

void duyet(int i)
{
    //if(dem > 2000 && ans != INF) return;
    if(i > k)
    {
        //dem++;
        ll cur = 0;
        For(i,1,k)
            For(j,i+1,k)
                if(x[i] == x[j])
                    cur = max(cur,dist(c[i],c[j]));
        if(cur < ans && check()) ans = cur;
        return;
    }
    if(used[i])
    {
        duyet(i+1);
        return;
    }
    For(j,i+1,k)
        if(!used[j])
        {
            //cerr << i << ' ' << j << endl;
            x[i] = i;
            x[j] = i;
            used[i] = true;
            used[j] = true;
            duyet(i+1);
            used[i] = false;
            used[j] = false;
        }
}

void Sub1()
{
    dem = 0;
    dfs(1,0);
    duyet(1);
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BUBBLETEA.inp","r",stdin);
    freopen("BUBBLETEA.out","w",stdout);
    cin >> n >> k;
    For(i,1,k) cin >> c[i];
    For(i,1,n-1)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    Sub1();
}
