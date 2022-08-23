#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,K,ans = -1e9;
int a[maxn][maxn],ii,jj;
int dp[maxn][maxn],tdp[maxn][maxn];

void Solve()
{
    For(i,1,n)
        For(j,1,n)
            dp[i][j] = -1e9;
    dp[1][1] = a[1][1];
    For(k,0,K){
        For(i,1,n)
            For(j,1,n)
                tdp[i][j] = -1e9;
        For(i,1,n)
            For(j,1,n){
                if(i + 1 <= n && dp[i][j] + a[i+1][j] > dp[i+1][j])
                    dp[i+1][j] = dp[i][j] + a[i+1][j];
                if(j + 1 <= n && dp[i][j] + a[i][j+1] > dp[i][j+1])
                    dp[i][j+1] = dp[i][j] + a[i][j+1];

                if(i > 1 && dp[i][j] + a[i-1][j] > tdp[i-1][j])
                    tdp[i-1][j] = dp[i][j] + a[i-1][j];
                if(j > 1 && dp[i][j] + a[i][j-1] > tdp[i][j-1])
                    tdp[i][j-1] = dp[i][j] + a[i][j-1];
            }
        if(dp[n][n] > ans) ans = dp[n][n];
        if(k < K)
            For(i,1,n)
                For(j,1,n) dp[i][j] = tdp[i][j];
    }
    cout << ans << endl;
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d%d",&n,&K);
    For(i,1,n)
        For(j,1,n) scanf("%d",&a[i][j]);
    Solve();
}
