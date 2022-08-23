#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1005
#define ll long long
#define INF 1e9
using namespace std;

ll P,D;

bool check(int a,int b,int c)
{
    if(c < a || c < b) return false;
    if(a + b <= c || a + c <=  b || b + c <= a) return false;
    return true;
}

bool CHECK(int a,int b,int c)
{
    if(!check(a,b,c)) return false;
    ll Sm2 = D*(D-a)*(D-b)*(D-c);
    ll S = sqrt(Sm2);
    if(S*S != Sm2) return false;
    if(S % D != 0) return false;
    ll t = 1ll*a*b*c;
    if(t % (4*S) != 0) return false;
    //cout << a << ' ' << b << ' ' << c << ' ' << S << ' ' <<S/D << ' ' << t/(4*S) << endl;
    return true;
}

int main()
{
    fast_read;
    freopen("TRIANGLE.inp","r",stdin);
    freopen("TRIANGLE.out","w",stdout);
    //cin >> P;
    For(p,1,100)
    {
        P = p;
        D = P/2;
//        if(P % 2 == 1)
//        {
//            cout << 0 << endl;
//            return 0;
//        }
        ll ans = 0;
        For(a,1,P)
            For(b,a,P-a)
            {
                int c = P - a - b;
                if(c < a || c < b) break;
                ans += CHECK(a,b,c);
            }
        cerr << P << ' ' << ans << endl;
    }
}
