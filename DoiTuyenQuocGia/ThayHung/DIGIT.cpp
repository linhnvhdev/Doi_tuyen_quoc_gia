#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 1005
#define ll unsigned long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

ll a,b,k;

ll mul(ll a,ll b,ll mod)
{
    if(b == 0) return 0;
    ll tmp = mul(a,b/5,mod);
    return (5*tmp + (a*(b%5) % mod))%mod;
}

ll luythua(ll a,ll n, ll mod)
{
    ll tmp = 1;
    while(n > 0){
        if(n % 2 == 1) tmp = mul(tmp,a,mod);
        a = mul(a,a,mod);
        n /= 2;
    }
    return tmp;
}

int main()
{
    freopen("DIGIT.inp","r",stdin);
    freopen("DIGIT.out","w",stdout);
    cin >> a >> b >> k;
    cout << mul(a,luythua(10,k-1,b),b) * 10/b;
}
