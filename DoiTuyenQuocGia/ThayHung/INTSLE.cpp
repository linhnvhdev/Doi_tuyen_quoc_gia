#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

ll a1,b1,c1,a2,b2,c2;
ll x,y;
int test;

bool check(ll a,ll b,ll c)
{
    if(a == 0 && b == 0) return (c == 0);
    ll d = __gcd(a,b);
    return (c % d == 0);
}

int Solve()
{
    ll D = a1*b2 - a2*b1;
    ll Dx = c1*b2 - c2*b1;
    ll Dy = a1*c2 - a2*c1;
    if(D == 0){
        if(Dx == 0 && Dy == 0){
            if(!check(a1,b1,c1) || !check(a2,b2,c2)) return -1;
            return 0;
        }
        else return -1;
    }
    if(Dx % D != 0 || Dy % D != 0) return -1;
    x = Dx/D;
    y = Dy/D;
    return 1;
}

int main()
{
    freopen("INTSLE.inp","r",stdin);
    freopen("INTSLE.out","w",stdout);
    cin >> test;
    while(test--){
        cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
        int kq = Solve();
        //cerr << kq << endl;
        if(kq == -1) cout << "NO SOLUTION\n";
        if(kq == 0) cout << "INFINITE\n";
        if(kq == 1) cout << x << ' ' << y << endl;
    }
}
