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

int n;
ll a[maxn],S,sum[maxn];

pair<ll,int> p[maxn];

int main()
{
    fast_read;
    freopen("ASUM.inp","r",stdin);
    freopen("ASUM.out","w",stdout);
    cin >> n >> S;
    For(i,1,n)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
        p[i] = {sum[i],i};
    }
    sort(p+1,p+1+n);
    ll ans = (p[1].fi > S || p[1].fi < -S);
    int j = 1;
    For(i,2,n)
    {
        if(p[i].fi > S || p[i].fi < -S) ans++;
        while(j < i && (p[i].fi - p[j].fi) > S) j++;
        ans += j - 1;
    }
    cout << ans << endl;
}
