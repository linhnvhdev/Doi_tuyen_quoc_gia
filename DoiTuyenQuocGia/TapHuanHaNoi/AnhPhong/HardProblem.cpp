#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 100005
#define ll long long
#define INF 1e18
using namespace std;

int n;
string s[maxn],g[maxn];
ll c[maxn],dp[maxn][2];

bool sosanh(string &s1,string &s2)
{
    return (s1.compare(s2) >= 0);
}

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n) cin >> c[i];
    For(i,1,n)
    {
        cin >> s[i];
        g[i] = s[i];
        reverse(g[i].begin(),g[i].end());
    }
    For(i,1,n)
        For(j,0,1) dp[i][j] = INF;
    dp[1][0] = 0;
    dp[1][1] = c[1];
    For(i,2,n)
    {
        if(sosanh(s[i],s[i-1]))
            dp[i][0] = min(dp[i][0],dp[i-1][0]);
        if(sosanh(s[i],g[i-1]))
            dp[i][0] = min(dp[i][0],dp[i-1][1]);
        if(sosanh(g[i],s[i-1]))
            dp[i][1] = min(dp[i][1],dp[i-1][0] + c[i]);
        if(sosanh(g[i],g[i-1]))
           dp[i][1] = min(dp[i][1],dp[i-1][1] + c[i]);
    }
    ll ans = min(dp[n][0],dp[n][1]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
}
