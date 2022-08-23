#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

const int mod = 1e9+7;

int n;
ll a[maxn],C;

int f[1000005];

void Sang()
{
    For(i,1,1000000) f[i] = i;
    For(i,2,1000000)
        if(f[i] == i)
            For(j,2,1000000/i) f[i*j] = i;
}

ll lt(ll a,ll n)
{
    ll tmp = 1;
    while(n > 0)
    {
        if(n % 2 == 1) tmp = (tmp*a)%mod;
        a = (a*a)%mod;
        n /= 2;
    }
    return tmp;
}

int Cnt(ll x)
{
    int tmp = 0;
    //cerr << "## " << x << endl;
    while(x != 1)
    {
        int t = f[x];
        int cur = 0;
        //cerr << x << ' ' << t << endl;
        while(x % t == 0) x /= t;
        tmp++;
    }
    return tmp;
}

void Sub2()
{
    ll ans = 0;
    for(int i = 1;i < (1<<n);i++)
    {
        ll tmp = 0;
        For(j,0,n-1)
            if(Bit(i,j))
                tmp = __gcd(tmp,a[j+1]);
        ans = (ans + lt(C,Cnt(tmp)))%mod;
    }
    cout << ans << endl;
    //exit(0);
}

ll dp[1005][1005];

void Sub3()
{
    dp[0][0] = 1;
    For(i,1,n)
    {
        For(j,0,1000)
        {
            dp[i][j] += dp[i-1][j];
            int g = __gcd(1ll*j,a[i]);
            dp[i][g] = (dp[i][g] + dp[i-1][j]) % mod;
        }
        //For(j,0,30) cout << i << ' '<< j << ' ' << dp[i][j] << endl;
    }
    ll ans = 0;
    For(i,1,1000)
        if(dp[n][i] != 0)
            ans = (ans + lt(C,Cnt(i))*dp[n][i]%mod)%mod;
    cout << ans << endl;
}

ll maxa;

ll g[1000005],g2[1000005];

ll uoc[1000005];

void Sub4()
{
    ll ans = 0;
    For(i,1,n) g[a[i]]++;
    For(i,1,maxa)
        For(j,1,maxa/i)
            g2[i] += g[i*j];
    Forr(i,maxa,1)
    {
        if(g2[i] == 0) continue;
        uoc[i] = ((lt(2,g2[i]) - 1)%mod + mod)%mod;
        For(j,2,maxa/i)
            uoc[i] = ((uoc[i] - uoc[i*j])%mod + mod)%mod;
    }
    For(i,1,maxa) ans = (ans + uoc[i]*(lt(C,Cnt(i)))%mod)%mod;
    cout << ans << endl;
}

int main()
{
    fast_read;
    freopen("XXX.inp","r",stdin);
    freopen("XXX.out","w",stdout);
    cin >> n >> C;
    Sang();
    For(i,1,n)
    {
        cin >> a[i];
        maxa = max(maxa,a[i]);
    }
    if(C == 1)
    {
        cout << lt(2,n) - 1 << endl;
        return 0;
    }
    if(n <= 17) Sub2();
    else if(n <= 1000 && maxa <= 1000) Sub3();
    else Sub4();
}
