/**
    For(i,1,k)
        For(d0,0,10)
            For(d1,0,10-d0)
                For(d2,0,10- d0 - d1)
                {
                    int d3 = 10 - d0 - d1- d2;
                    if(d0 > 0) dp[i][d0][d1][d2] += dp[i-1][d0-1][d1+1][d2]*d0;
                    if(d1 > 0) dp[i][d0][d1][d2] += dp[i-1][d0][d1-1][d2+1]*d1;
                    if(d2 > 0) dp[i][d0][d1][d2] += dp[i-1][d0][d1][d2-1]*d2;
                    if(d3 > 0) dp[i][d0][d1][d2] += dp[i-1][d0+1][d1][d2-1]*d3;
                }
    cout << dp[k-1][9][1][0]*9 << endl;
**/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 50005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define INF 1e18
using namespace std;

string P,Q;
ll p,q;
ll lt10[20];

bool sdx[maxn];

int cs[10];

bool check(ll s)
{
    For(i,0,9) cs[i] = 0;
    while(s > 0)
    {
        cs[s%10]++;
        s /= 10;
    }
    int d[4] = {0,0,0,0};
    For(i,0,9) d[cs[i]%4]++;
    For(i,1,3) if(d[i] > 2) return false;
    if(d[3] == 1 && d[2] == 0 && d[1] == 0) return true;
    if(d[3] == 0 && d[2] <= 1 && d[1] <= 1) return true;
    return false;
}

void Solve(ll p,ll q)
{
    ll ans = 0;
    for(ll i = p;i <= q;i++)
    {
        int d = check(i);
        //if(d == 1) cout << "#### " << i << endl;
        ans += d;
    }
    cout << ans << endl;
}

ll lt[maxn];

ll dp[maxn][11][11][11];

const int mod = 1e9+7;

bool sub2 = true;

ll mul_mod(ll a,ll b)
{
    if(b == 0) return 0;
    return (5*mul_mod(a,b/5) + a*(b%5))%mod;
}

ll add_mod(ll a,ll b)
{
    return (a+b)%mod;
}

ll cnt(string s)
{
    int k = s.size();
    if(s == "0") return 0;
    ll ans = 0;
    For(i,1,k-1) ans = add_mod(ans,mul_mod(dp[i-1][9][1][0],9));
    int d[4] = {10,0,0,0};
    int c[10];
    memset(c,0,sizeof(c));
    For(i,0,k-1)
    {
        for(int j = (i == 0 ? 1 : 0); j < s[i] - '0';j++)
        {
            d[c[j]%4]--;
            c[j]++;
            d[c[j]%4]++;
            ans = add_mod(ans,dp[k-i-1][d[0]][d[1]][d[2]]);
            d[c[j]%4]--;
            c[j]--;
            d[c[j]%4]++;
        }
        int j = s[i] - '0';
        d[c[j]%4]--; c[j]++; d[c[j]%4]++;
    }
    ans = add_mod(ans,dp[0][d[0]][d[1]][d[2]]);
    return ans;
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> P >> Q;
    if(P.size() <= 5 && Q.size() <= 5)
    {
        for(int i = 0;i < P.size();i++)
            p = p*10 + (P[i] -'0');
        for(int i = 0;i < Q.size();i++)
            q = q*10 + (Q[i] -'0');
        Solve(p,q);
        exit(0);
    }
    int k = max(P.size(),Q.size());
    dp[0][9][0][0] = 1;
    dp[0][10][0][0] = 1;
    dp[0][9][0][1] = 1;
    dp[0][9][1][0] = 1;
    dp[0][8][1][1] = 1;
    For(i,1,k)
    For(d0,0,10)
    For(d1,0,10 - d0)
    For(d2,0,10 - d0 - d1)
    {
        int d3 = 10 - d0 - d1- d2;
        if(d0 > 0) dp[i][d0][d1][d2] += dp[i-1][d0-1][d1+1][d2]*d0;
        if(d1 > 0) dp[i][d0][d1][d2] += dp[i-1][d0][d1-1][d2+1]*d1;
        if(d2 > 0) dp[i][d0][d1][d2] += dp[i-1][d0][d1][d2-1]*d2;
        if(d3 > 0) dp[i][d0][d1][d2] += dp[i-1][d0+1][d1][d2]*d3;
        dp[i][d0][d1][d2] %= mod;
    }
    int del = 1,cur = P.size()-1;
    while(del != 0)
    {
        int x = P[cur]-'0';
        P[cur] = (x == 0) ? char(9 + '0') : char(x-1 + '0');
        if(x != 0) del = 0;
        if(cur == 0 && P[cur] == '0')
        {
            P.erase(0,1);
            break;
        }
        cur--;
   }
    //cout << P << ' ' << Q << endl;
    cout << ((cnt(Q) - cnt(P))%mod + mod) % mod;
}
