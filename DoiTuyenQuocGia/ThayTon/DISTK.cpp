#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 50005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,k,root;
ll dp[maxn][205],ans = 0;

vector<int> a[maxn];

void dfs(int u,int p)
{
    //cerr << u << ' ' << p << endl;
    for(int v : a[u]){
        if(v == p) continue;
        dfs(v,u);
        For(j,0,k-1) ans += dp[u][j]*dp[v][k-j-1];
        For(j,1,k) dp[u][j] += dp[v][j-1];
    }
}

int main()
{
    freopen("DISTK.inp","r",stdin);
    freopen("DISTK.out","w",stdout);
    scanf("%d%d",&n,&k);
    For(i,1,n){
        int p;
        scanf("%d",&p);
        if(p == 0) root = i;
        a[i].push_back(p);
        a[p].push_back(i);
    }
    For(i,1,n) dp[i][0] = 1;
    dfs(root,0);
    cout << ans << endl;
    return 0;
}
