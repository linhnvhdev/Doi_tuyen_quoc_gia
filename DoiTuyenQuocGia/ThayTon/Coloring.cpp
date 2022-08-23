#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,root;
ll ans = 0,t[maxn],t2[maxn];
ll s[maxn];

vector<int> a[maxn];

void dfs(int u,int p)
{
    s[u] = 1;
    t[u] = 0;
    for(int v : a[u]){
        if(v == p) continue;
        dfs(v,u);
        s[u] += s[v];
        t[u] += t[v];
    }
    t[u] += s[u];
}

void DFS(int u,int p)
{
    if(u == root) ans = t[u];
    else{
        t[u] = t[p] + n - 2*s[u];
        ans = max(ans,t[p] + n - 2*s[u]);
    }
    for(int v : a[u])
        if(v != p)
            DFS(v,u);
}

int main()
{
    freopen("Coloring.inp","r",stdin);
    freopen("Coloring.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n){
        int p;
        scanf("%d",&p);
        if(p == 0) root = i;
        if(p == 0) continue;
        a[p].push_back(i);
    }
    dfs(root,0);
    cerr << t[1] << endl;
    DFS(root,0);
    //For(i,1,n) cerr << i << ' ' << t[i] << endl;
    cout << ans << endl;
    return 0;
}
