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

ll fact[2*maxn];

int n;

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

int main()
{
    fast_read;
    freopen("CATALAN.inp","r",stdin);
    freopen("CATALAN.out","w",stdout);
    cin >> n;
    fact[0] = 1;
    For(i,1,2*n) fact[i] = fact[i-1]*i%mod;
    //cout << fact[n] << ' ' << fact[n+1] << ' ' << fact[2*n] << endl;
    ll ans = fact[2*n]*lt(fact[n],mod-2)%mod;
    ans = ans*lt(fact[n+1],mod-2)%mod;
    cout << ans << endl;
}

