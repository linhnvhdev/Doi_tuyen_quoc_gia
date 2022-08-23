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

ll f[maxn];

void check(int u,int p)
{
    s[u] = 1;
    for(int v : a[u])
    {
        if(v == p) continue;
        check(v,u);
        s[u] += s[v];
    }
    if(s[u] == 1)
    {
        leaf[++m] = u;
        id[u] = m;
    }
}

void dfs(int u,int p)
{
    if(c[u] != -1) return;
    c[u] = 0;
    for(int v : a[u])
    {
        if(v == p) continue;
        dfs(v,u);
        c[u] += c[v];
        f[u] += f[v];
    }
    f[u] += abs(d[u] - c[u]);
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
    ll ans = INF;
//    cout << m << endl;
//    For(i,1,m) cout << leaf[i] << ' ';
//    cout << endl;
    for(int i = 0;i < (1 << m);i++)
    {
        memset(f,0,sizeof(f));
        memset(c,-1,sizeof(c));
        For(j,0,m-1)
        {
            int u = leaf[j+1];
            c[u] = Bit(i,j);
            f[u] = abs(d[u] - c[u]);
            cout << u << ' ' << c[u] << endl;
        }
        dfs(1,0);
        ans = min(ans,f[1]);
        cout << f[1] << endl;
    }
    cout << ans << endl;
}
