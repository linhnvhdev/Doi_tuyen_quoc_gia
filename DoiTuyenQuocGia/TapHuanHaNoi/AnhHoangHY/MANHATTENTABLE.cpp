#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1000005
#define ll long long
#define INF 1e18
using namespace std;

ll n,a,b,d;
ll ans = 0;

ll tinh(ll x,ll y,ll k)
{
    if(x > y) swap(x,y);
    if(k <= x && k <= y) return k-1;
    ll t1 = k - x;
    ll t2 = k - y;
    ll K1 = min(x,y - t1 + 1);
    ll K2 = min(y,x - t2 + 1);
    if(t2 < 0) return max(K1,0ll);
    else return max(0ll,min(K1,K2));
}

int main()
{
    fast_read;
    ll ans = 0;
    cin >> n >> a >> b >> d;
    ll maxl = a - 1; if(maxl >= d) ans++;
    ll maxr = n - a; if(maxr >= d) ans++;
    ll maxt = b - 1; if(maxt >= d) ans++;
    ll maxd = n - b; if(maxd >= d) ans++;
    ans += tinh(maxl,maxd,d);
    ans += tinh(maxl,maxt,d);
    ans += tinh(maxr,maxt,d);
    ans += tinh(maxr,maxd,d);
    cout << ans << endl;
}
