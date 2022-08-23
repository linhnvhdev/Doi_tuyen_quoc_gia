#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 50005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int t,n;

ll a[maxn];

bool sub2 = true;

void Sub1()
{
    ll ans = 0;
    for(int i = 1;i < (1<<n)-1;i++)
    {
        ll hd[2] = {0,0};
        For(j,0,n-1)
            hd[Bit(i,j)] = __gcd(hd[Bit(i,j)],a[j+1]);
        //cerr << hd[0] << ' ' << hd[1] << endl;
        if(hd[0] > hd[1]) swap(hd[0],hd[1]);
        ans = max(ans,hd[0]);
    }
    cout << ans << endl;
    //exit(0);
}

void Sub2()
{
    ll maxa = 0;
    For(i,1,n) maxa = max(maxa,a[i]);
    ll ans = 0;
    For(g,1,maxa)
    {
        ll hd1 = 0,hd2 = 0;
        For(i,1,n)
        {
            if(a[i] % g == 0) hd1 = __gcd(hd1,a[i]);
            else hd2 = __gcd(hd2,a[i]);
        }
        if(hd1 == g)
        {
            if(hd2 == 0 || hd2 >= hd1)
                ans = g;
        }
    }
    //cout << " < ";
    cout << ans << endl;
}

pair<ll,ll> dp[maxn][2];

void Sub3()
{
    dp[1][0] = {a[1],0};
    dp[1][1] = {0,a[1]};
    For(i,2,n)
    {
        pll pre1 = dp[i-1][0];
        pll pre2 = dp[i-1][1];
        pre1.fi = __gcd(pre1.fi,a[i]);
        pre2.fi = __gcd(pre2.fi,a[i]);
        dp[i][0] = (min(pre1.fi,pre1.se) < min(pre2.fi,pre2.se)) ? pre2 : pre1;

        pre1 = dp[i-1][0];
        pre2 = dp[i-1][1];
        pre1.se = __gcd(pre1.se,a[i]);
        pre2.se = __gcd(pre2.se,a[i]);
        dp[i][1] = (min(pre1.fi,pre1.se) < min(pre2.fi,pre2.se)) ? pre2 : pre1;
    }
    cout << max(min(dp[n][0].fi,dp[n][0].se),min(dp[n][1].fi,dp[n][1].se)) << endl;
}

int main()
{
    fast_read;
    freopen("LAN.inp","r",stdin);
    freopen("LAN.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        For(i,1,n) cin >> a[i];
        if(n <= 15) Sub1();
        else if(n <= 100) Sub2();
        else Sub3();
    }
}
