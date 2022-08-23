/*
    - đi từ 1 hàng dến 1 ô có cửa
    - đi từ 1 ô có cửa đến 1 ô có cửa(lặp c lần)
    - đi từ từ ô có của về hàng m
        f(i,j) = max(a[i], f(i - 1, j - 1) + a[i], f(i - 1, j) + a[i], f(i - 1, j + 1) + a[i]);

*/
#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxN 1055
#define ll long long
using namespace std;
int m, n, c, door[maxN][maxN];
ll a[maxN][maxN], f[maxN][maxN], dp[maxN][maxN][3], maxtrc = -1e15;
void Sub4()
{
    For(i,1,m)
        For(j,1,n)
            For(time,0,1)
                dp[i][j][time] = -1e15;
    For(j,1,n)
    {
        dp[1][j][0] = a[1][j];
        if(door[1][j] == 1)maxtrc = max(maxtrc, dp[1][j][0]);
    }
    For(time,0,1)
    {
        ll maxcur = -1e15;
        if(time == 0)maxcur = maxtrc;
        For(i,1,m)
            For(j,1,n)
            {
                if(time == 0 && i == 1)continue;
                dp[i][j][time] = max(max(dp[i - 1][j + 1][time], dp[i - 1][j][time]), dp[i - 1][j - 1][time]) + a[i][j];
                if(door[i][j] == 1)maxcur = max(maxcur, dp[i][j][time]);
                if(time == 0 || door[i][j] == 0)continue;
                dp[i][j][time] = max(dp[i][j][time], maxtrc + a[i][j]);
                maxcur = max(maxcur, dp[i][j][time]);
            }
        if(time == 0)maxtrc = maxcur;
        if(time == 1)maxtrc = maxcur - maxtrc;
    }
    For(i,1,m)
        For(j,1,n)
        {
            if(door[i][j] == 1)dp[i][j][1] = max(dp[i][j][1], dp[i][j][1] + maxtrc *(c - 1));
            dp[i][j][1] = max(dp[i][j][1], max(max(dp[i - 1][j][1], dp[i - 1][j - 1][1]), dp[i - 1][j + 1][1]) + a[i][j]);
        }
    ll ans = -1e15;
        For(j,1,n)
            ans = max(ans,dp[m][j][1]);
    cout<<ans<<endl;
}
void Sub2()
{
    For(i,0,m)
        For(j,0,n)f[i][j] = -1e15;
    For(j,1,n)
        f[1][j] = a[1][j];
    For(i,2,m)
        For(j,1,n)
        {
            ll cur = max(f[i - 1][j + 1], f[i - 1][j]);
            cur = max(cur, f[i - 1][j - 1]);
            f[i][j] = cur + a[i][j];
        }
    ll ans = -1e15;
    For(j,1,n)
        ans = max(ans, f[m][j]);
    printf("%lld\n", ans);
}
int main()
{
    //freopen("MDOOR.inp", "r", stdin);
    //freopen("MDOOR.out", "w", stdout);
    scanf("%d%d%d", &m, &n, &c);
    For(i,1,m)
        For(j,1,n)
            scanf("%d", &door[i][j]);
    For(i,1,m)
        For(j,1,n)
            scanf("%lld", &a[i][j]);
    if(c == 0)Sub2();
    else
        Sub4();
}
