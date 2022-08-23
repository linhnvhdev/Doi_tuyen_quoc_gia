#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000006
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

ll n,m,a[maxn];

void Sub1()
{
    a[0] = 1; a[1] = 6;
    For(i,2,n)
        a[i] = ((a[i-1]*6 - 9*a[i-2])%m + m)%m;
    cout << a[n] << endl;
}

ll mul_mod(ll a,ll b,ll mod)
{
    if(b == 0) return 0;
    if(b == 1) return a % mod;
    return (5*mul_mod(a,b/5,mod) + a*(b%5)) % mod;
}

ll lt(ll a,ll n)
{
    ll tmp = 1;
    while(n > 0)
    {
        if(n % 2 == 1) tmp = mul_mod(tmp,a,m);
        a = mul_mod(a,a,m);
        n /= 2;
    }
    return tmp;
}

void Sub2()
{
    cout << mul_mod(1+n,lt(3ll,n),m) << endl;
}

int main()
{
    fast_read;
    freopen("SEQ.inp","r",stdin);
    freopen("SEQ.out","w",stdout);
    cin >> n >> m;
    if(n <= 1000000) Sub1();
    else Sub2();
}
