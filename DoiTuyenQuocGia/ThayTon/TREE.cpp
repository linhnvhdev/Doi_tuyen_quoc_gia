#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 5005
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

int n,s[maxn],d[maxn],c[maxn];

vector<int> a[maxn];

int leaf[maxn],id[maxn],m = 0;

ll f[maxn][maxn];

int con[maxn][3];

void check(int u,int p)
{
    for(int v : a[u])
    {
        if(v == p) continue;
        check(v,u);
        con[u][++s[u]] = v;
    }
    if(s[u] == 0)
    {
        leaf[++m] = u;
        id[u] = m;
    }
}

void dfs(int u,int p)
{
    if(s[u] == 0)
    {
        f[u][0] = d[u];
        f[u][1] = abs(d[u] - 1);
        return;
    }
    for(int v : a[u])
    {
        if(v == p) continue;
        dfs(v,u);
    }
    For(i,0,m)
    {
        ll add = abs(d[u] - i);
        int v = con[u][1],v2 = con[u][2];
        if(s[u] == 1)
        {
            f[u][i] = f[v][i] + add;
            continue;
        }
        For(j,0,i)
            f[u][i] = min(f[u][i],f[v][j] + f[v2][i-j] + add);
        //cout << u << ' ' << i << ' ' << f[u][i] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("TREE.inp","r",stdin);
    freopen("TREE.out","w",stdout);
    cin >> n;
    For(i,1,n) cin >> d[i];
    For(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    check(1,0);
    For(i,1,n)
        For(j,0,m) f[i][j] = INF;
    ll ans = INF;
    dfs(1,0);
    For(i,0,m)
        ans = min(ans,f[1][i]);
    cout << ans << endl;
}
