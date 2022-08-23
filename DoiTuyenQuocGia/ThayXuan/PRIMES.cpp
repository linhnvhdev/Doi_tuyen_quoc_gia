#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 10000005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

const int mod = 1e9+7;

vector<ll> uoc;

ll x,n;

ll lt(ll a,ll n)
{
    ll tmp = 1;
    while(n > 0)
    {
        if(n % 2 == 1) tmp = (tmp*a)%mod;
        a = (a*a)%mod;
        n /= 2;
    }
    return tmp%mod;
}

int main()
{
    fast_read;
    freopen("PRIMES.inp","r",stdin);
    freopen("PRIMES.out","w",stdout);
    cin >> x >> n;
    for(int i = 2;i <= sqrt(x);i++)
    {
        if(x % i == 0)
        {
            uoc.push_back(i);
            while(x % i == 0) x /= i;
        }
    }
    if(x != 1)
        uoc.push_back(x);
    ll ans = 1;
    for(ll u : uoc)
    {
        ll v = u;
        while(v <= n)
        {
            ans = (ans*lt(u,n/v))%mod;
            if(v > n/u) break;
            v = v*u;
        }
    }
    cout << ans << endl;
}

