#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 100005
#define fi first
#define se second
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

const int mod = 1e9+7;
ll n,k;

ll cs[maxn],f[maxn];


int main()
{
    freopen("LUCKYNUM.inp","r",stdin);
    freopen("LUCKYNUM.out","w",stdout);
    cin >> n >> k;
    cs[1] = 9;
    For(i,2,n) cs[i] = (cs[i-1]*10)%mod;
    if(k > n)
    {
        cout << 0 << endl;
        return 0;
    }
    if(n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    For(i,1,n)
    {
        if(i <= k)
        {
            f[i] = cs[i];
            if(i == k) f[i] = (f[i] - 1 + mod) % mod;
        }
        else
        {
            ll t = (i == k+1) ? 8ll : (f[i-k-1]*9)%mod;
            f[i] = ((f[i-1]*10 - t) % mod + mod)%mod;
        }
    }
    cout << ((cs[n] - f[n])%mod + mod)%mod << endl;
}
