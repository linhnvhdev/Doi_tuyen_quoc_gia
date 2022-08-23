#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,root;
ll ans1 = -INF,ans2 = INF,t[maxn];
ll f[maxn],s[maxn],d[maxn],tong = 0;

vector<pair<int,ll> > a[maxn];

void dfs(int u,int p)
{
    s[u] = d[u];
    t[u] = 0;
    for(int i = 0;i < a[u].size();i++){
        int v = a[u][i].fi;
        ll l = a[u][i].se;
        if(v == p) continue;
        dfs(v,u);
        s[u] += s[v];
        t[u] += t[v] + s[v]*l;
    }
    //if(a[u].size() > 1) t[u] += s[u];
}

void DFS(int u,int p)
{
    for(int i = 0;i < a[u].size();i++){
        int v = a[u][i].fi;
        ll l = a[u][i].se;
        if(v == p) continue;
        t[v] = t[u] + tong*l - 2*s[v]*l;
        ans2 = max(ans2,t[v]);
        ans1 = min(ans1,t[v]);
        DFS(v,u);
    }
}

int main()
{
    freopen("ROOTSEL.inp","r",stdin);
    freopen("ROOTSEL.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n-1){
        int u,v;
        ll l;
        scanf("%d%d%lld",&u,&v,&l);
        a[u].push_back({v,l});
        a[v].push_back({u,l});
    }
    For(i,1,n){
        scanf("%lld",&d[i]);
        tong += d[i];
    }
    root = 1;
    dfs(root,0);
    ans2 = t[root];
    ans1 = t[root];
    DFS(root,0);
    cout << ans1 <<' ' << ans2<< endl;
    return 0;
}
