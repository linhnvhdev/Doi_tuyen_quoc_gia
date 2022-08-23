#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 301
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,jj,vv,tmp,a[maxn][maxn];
int dp[2*maxn][maxn][maxn];

int main()
{
    scanf("%d",&n);
    For(i,1,n)
        For(j,1,n)
            scanf("%d",&a[i][j]);
    For(i,0,n)
        For(j,0,n)
            dp[0][i][j] = dp[1][i][j] = -INF;
    dp[1][1][1] = a[1][1];
    For(k,2,2*n-1)
        For(i,max(k-n+1,0),n)
            For(u,max(k-n+1,0),n){
                tmp = dp[k-1][i][u];
                if(i > 1 && tmp < dp[k-1][i-1][u])
                    tmp = dp[k-1][i-1][u];
                if(u > 1 && tmp < dp[k-1][i][u-1])
                    tmp = dp[k-1][i][u-1];
                if(i > 1 && u > 1 && tmp < dp[k-1][i-1][u-1])
                    tmp = dp[k-1][i-1][u-1];
                dp[k][i][u] = (i == u) ? tmp + a[i][k-i+1] : tmp + a[i][k-i+1] + a[u][k-u+1];
            }
    printf("%d\n",dp[2*n-1][n][n]);
}
