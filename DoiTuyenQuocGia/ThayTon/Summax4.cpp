#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,root;
ll ans = 0,t[maxn];
ll f[maxn],s[maxn],d[maxn],tong = 0;

vector<int> a[maxn];

void dfs(int u,int p)
{
    s[u] = d[u];
    t[u] = 0;
    for(int v : a[u]){
        if(v == p) continue;
        dfs(v,u);
        s[u] += s[v];
        t[u] += t[v] + s[v];
    }
    //if(a[u].size() > 1) t[u] += s[u];
}

void DFS(int u,int p)
{
    if(u == root) ans = t[u];
    else{
        t[u] = t[p] - 2*s[u] + tong;
        ans = max(ans,t[u]);
    }
    for(int v : a[u])
        if(v != p) DFS(v,u);
}

int main()
{
    freopen("Summax4.inp","r",stdin);
    freopen("Summax4.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n){
        scanf("%d",&d[i]);
        tong += d[i];
    }
    For(i,1,n){
        int p;
        scanf("%d",&p);
        if(p == 0) root = i;
        if(p == 0) continue;
        a[i].push_back(p);
        a[p].push_back(i);
    }
    dfs(root,0);
    //For(i,1,n) cerr << i << ' ' << t[i] << endl;
    DFS(root,0);
    cout << ans << endl;
    return 0;
}
