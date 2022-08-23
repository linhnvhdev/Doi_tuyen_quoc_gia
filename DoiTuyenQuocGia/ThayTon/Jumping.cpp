#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,root,k;
ll ans = 0,ans2 = 0;
ll dp[maxn][25],s[maxn];

vector<int> a[maxn];

void DFS(int u,int p)
{
    s[u] = 1;
    for(int v : a[u]){
        if(v == p) continue;
        DFS(v,u);
        s[u] += s[v];
    }
}

void dfs(int u,int p)
{
    dp[u][0] = 1;
    //cerr << "##### " << u << endl;
    for(int v : a[u]){
        if(v == p) continue;
        dfs(v,u);
        //cerr << "%%% " << v << endl;
        For(x,1,k-1){
            int sum = k - x;
            For(i,0,sum){
                int j = sum - i;
                ans2 += x * dp[u][i] * dp[v][j-1];
            }
            sum = 2*k - x;
            For(i,0,sum){
                int j = sum - i;
                ans2 += x * dp[u][i] * dp[v][j-1];
            }
        }
        For(i,1,k-1) dp[u][i] += dp[v][i-1];
        dp[u][0] += dp[v][k-1];
        ///For(i,0,k-1) cerr << "dp" << u << ' ' << i << ' ' <<  dp[u][i] << endl;
        ///For(i,0,k-1) cerr << "dp" << v << ' ' << i << ' ' <<  dp[v][i] << endl;
        ans += s[v]*(n - s[v]);
    }
}

int main()
{
    freopen("Jumping.inp","r",stdin);
    freopen("Jumping.out","w",stdout);
    scanf("%d%d",&n,&k);
    For(i,1,n){
        int p;
        scanf("%d",&p);
        if(p == 0) root = i;
        if(p == 0) continue;
        a[i].push_back(p);
        a[p].push_back(i);
    }
    DFS(root,0);
    dfs(root,0);
    //cout << ans << ' ' << ans2 << ' ' << (ans + ans2)/k << endl;
    cout << (ans + ans2)/k;
    return 0;
}
