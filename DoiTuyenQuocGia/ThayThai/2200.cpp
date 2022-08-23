/**
    Bài toán phát biểu như sau : Đếm số nguyên i (1 <= i <= n) sao cho
    (1 + 2 + 3 + ... + i) chia hết cho m
    <=> i*(i+1) chia hết cho 2m
    Do i & i + 1 nguyên tố cùng nhau nên ta sẽ phân tích 2m thành tích của 2 số nguyên tố cùng nhau
    (Xét tât cả các cách)
    Giả sử 2*m = a*b với gcd(a,b) = 1;
    Khi đó:
        i*(i+1) chia hết cho 2m <=> i chia hết cho a và i + 1 chia hết cho b
    <=> i === 0 (mod a)
    <=> i === b-1 (mod b)
    <=> x === Xichma(ai*Mi*yi) (mod m1*m2*...*mn)
    ai*yi === 1(mod mi)
    => i === (b-1)*a*y (mod(a*b) = 2*m) với (b-1)*y === 1(mod b)
    Tính y = Ơ cờ lít mở rộng
    Gọi r = (b-1)*a*y mod 2*m và cnt là số các số nguyên i (1 <= i <= n) cần đếm trong th này
    cnt = {
            (r == 0) : [n/2m]
            (r > 0) 0
            (0 < r <= n) [(n - r)/2m]+1
          }
    + Kq của bài toán là tổng tất cả các cnt với mọi a,b
**/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define INF 1e18
#define maxn 200005
#define Bit(x,i) ((x >> i)&1)
#define ll long long
#define fi first
#define se second
using namespace std;

ll m,n;

void ext_gcd(ll a,ll b,ll &d, ll &x,ll &y)
{
    if(b == 0){
        d = a;
        x = 1;
        y = 0;
    }
    else{
        ll x1,y1;
        ext_gcd(b,a%b,d,x1,y1);
        x = y1;
        y = x1 - (a/b)*y1;
    }
}

ll mod_inverse(ll a,ll m)
{
    ll x,y,d;
    ext_gcd(a,m,d,x,y);
    return (x%m + m)%m;
}

ll Dem(ll a,ll b)
{
    if(__gcd(a,b) != 1) return 0;
    ll y = mod_inverse(a,b);
    ll r = ((b-1)*a*y)%m;
    if(r > n) return 0;
    if(r == 0) return n/m;
    return (n - r)/m + 1;
}

int main()
{
    cin >> n >> m;
    m *= 2;
    ll ans = 0;
    For(i,1,sqrt(m))
        if(m % i == 0) ans += Dem(i,m/i) + Dem(m/i,i);
    cout << ans << endl;
    return 0;
}
