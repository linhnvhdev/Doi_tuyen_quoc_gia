#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
#define x fi
#define y second
#define lf double
using namespace std;

int n,k;

ll a[maxn],sum[maxn],maxs[maxn],maxs2[maxn];

ll get_sum(int i,int j)
{
    return sum[j] - sum[i-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GIFTS.inp","r",stdin);
    freopen("GIFTS.out","w",stdout);
    cin >> n >> k;
    For(i,0,n+1) maxs[i] = maxs2[i] = -INF;
    For(i,1,n)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    maxs[k] = sum[k];
    For(i,k+1,n) maxs[i] = max(maxs[i-1],get_sum(i-k+1,i));
    maxs2[n-k+1] = get_sum(n-k+1,n);
    Forr(i,n-k,1) maxs2[i] = max(maxs2[i+1],get_sum(i,i+k-1));
    ll ans = INF;
    For(i,1,n-k+1)
    {
        ll t = get_sum(i,i+k-1);
        ll c = max(maxs[i-1],maxs2[i+k]);
        ans = min(ans,c);
        //cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
}
