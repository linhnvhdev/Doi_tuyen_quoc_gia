#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n;
ll a[maxn],r;

int main()
{
    scanf("%d%lld",&n,&r);
    For(i,1,n) scanf("%lld",&a[i]);
    ll ans = 0;
    For(i,1,n){
        int vt = upper_bound(a+i,a+1+n,a[i] + r) - a;
        ans += n - vt + 1;
    }
    cout << ans << endl;
    return 0;
}
