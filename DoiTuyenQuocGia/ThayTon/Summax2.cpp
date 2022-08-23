#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n;
ll d[maxn], c[maxn];
ll f[maxn],g[maxn];

int root;

vector<pair<int,ll> > a[maxn];

void dfs(int u,int p)
{
    f[u] = c[u];
    g[u] = 0;
    ll maxf = 0,maxg = 0;
    for(int i = 0;i < a[u].size();i++){
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        if(v == p) continue;
        dfs(v,u);
        f[u] += g[v];
        g[u] += max(f[v],g[v]);
    }
}

int main()
{
    freopen("Summax2.inp","r",stdin);
    freopen("Summax2.out","w",stdout);
    cin >> n;
    For(i,1,n) scanf("%lld",&c[i]);
    For(i,1,n){
        int p;
        scanf("%d",&p);
        if(p == 0) root = i;
        a[i].push_back({p,c[p]});
        a[p].push_back({i,c[i]});
    }
    dfs(root,0);
    cout << max(f[root],g[root]) << endl;
    return 0;
}
