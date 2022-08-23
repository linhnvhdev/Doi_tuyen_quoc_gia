#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 30005
#define ll long long
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n;
ll a[maxn][12];
ll dp[4][2049];
int cnt[2049];
int bt1[2049][12];

int main()
{
    freopen("ACM.inp","r",stdin);
    freopen("ACM.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n)
    {
        For(j,1,11)
        {
            scanf("%lld",&a[i][j]);
        }
    }
    For(i,0,2047)
        For(j,0,10)
            if(Bit(i,j)) bt1[i][++cnt[i]] = j;
    ll cur;
    For(i,1,n)
        For(mask,0,2047)
        {
            cur = 0;
            For(j,1,cnt[mask])
                cur += a[i][bt1[mask][j]+1];
            dp[1][mask] = max(dp[1][mask],cur);
        }
    For(k,2,3)
        For(mask1,0,2047)
            For(mask2,0,2047)
            {
                if((mask1 & mask2) == 0)
                    dp[k][mask1^mask2] = max(dp[k][mask1^mask2],dp[k-1][mask1] + dp[1][mask2]);
            }
    cout << dp[3][2047];
}

