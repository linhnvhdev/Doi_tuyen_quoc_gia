/**
    Gọi T = cái mình cần tìm :)
    T = x^((x1-1*n)+j) + ...
    Đặt k = (x1-1)*n+y1,ta có
    T = x^k(1+x+x^2+...+x^(y2-y1)) + x^(k+n) * (1+x+...x^(y2-y1))+...x^(k+(x2-x1)*n) *(...);
      = x^k(1+x+...+x^(y2-y1))(1+x^n+x^(2*n)+...+x^(x2-x1)*n);
      =  a *        b         *                 c;
    Câu trả lời của mỗi truy vấn là T % p = a
**/

#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 10005
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

ll m,n,x,p;
int q;

ll luythua(ll a,ll n)
{
    ll tmp = 1;
    while(n > 0){
        if(n % 2 == 1) tmp = (tmp*a)%p;
        a = (a*a)%p;
        n /= 2;
    }
    return tmp%p;
}

ll sum_mod(ll a,ll n,ll mod)
{
    if(n == 0) return 1;
    if(n == 1) return (1+a)%mod;
    ll tmp = 1;
    if(n % 2 == 1) return (1+a)*sum_mod(a*a%mod,(n-1)/2,mod)%mod;
    return (1+a*(sum_mod(a,n-1,mod)))%mod;
}

int main()
{
    cin >> m >> n >> x >> q;
    For(i,1,q){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d%lld",&x1,&x2,&y1,&y2,&p);
        ll a = luythua(x,(x1-1)*n+y1);
        ll b = sum_mod(x,y2-y1,p);
        ll c = sum_mod(luythua(x,n),x2-x1,p);
        //cout << a << ' ' << b << ' ' << c << endl;
        ll ans = ((a*b)%p)*c%p;
        printf("%lld\n",ans);
    }
}
