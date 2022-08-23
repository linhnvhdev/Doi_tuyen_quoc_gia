#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100006
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

const int mod = 1e9+7;

ll m,a[maxn];
int n;

ll lt(ll a,ll n)
{
    ll tmp = 1;
    while(n > 0)
    {
        if(n % 2 == 1) tmp = (tmp*a)%mod;
        a = a*a%mod;
        n /= 2;
    }
    return tmp;
}

ll C(ll k,ll n)
{
    ll A = 1,B = 1;
    For(i,n-k+1,n) A = A*i%mod;
    For(i,1,k) B = B*i%mod;
    return A*lt(B,mod-2)%mod;
}

int main()
{
    fast_read;
    freopen("EQUATION.inp","r",stdin);
    freopen("EQUATION.out","w",stdout);
    cin >> m >> n;
    //cout << C(12,20) << endl;
    For(i,1,n) cin >> a[i];
    For(i,1,n) m -= a[i] - 1;
    if(m < n) cout << 0 << endl;
    else cout << C(n-1,m-1) << endl;
}
