#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 1000005
#define INF 1e9
#define fi first
#define se second
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,k;
pair<ll,ll> a[maxn];

bool check(ll time)
{
    ll vt = a[1].fi + time/(2*a[1].se),cnt = 1;
    For(i,1,n){
        if(a[i].fi + time/(2*a[i].se) < vt) vt = a[i].fi + time/(2*a[i].se);
        if(a[i].fi - vt > time/(2*a[i].se)){
            cnt++;
            if(cnt > k) return false;
            vt = a[i].fi + time/(2*a[i].se);
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ANTS.inp", "r", stdin);
    freopen("ANTS.out", "w", stdout);
    cin >> n >> k;
    For(i,1,n) cin >> a[i].fi;
    For(i,1,n) cin >> a[i].se;
    sort(a+1,a+1+n);
    ll l = 0,r = 1e15;
    while(r - l > 1){
        ll mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(check(l)) cout << l << endl;
    else cout << r << endl;
}
