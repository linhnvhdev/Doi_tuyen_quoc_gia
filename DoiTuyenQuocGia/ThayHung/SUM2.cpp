#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 100005
#define fi first
#define se second
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,L,U;
ll a[maxn],sum[maxn];
ll val[4*maxn];

void update(int s,int l,int r,int i,ll v)
{
    if(l > i || r < i) return;
    if(l == i && r == i)
    {
        val[s] = v;
        return;
    }
    int c = (l+r)/2;
    update(2*s,l,c,i,v);
    update(2*s+1,c+1,r,i,v);
    val[s] = min(val[2*s],val[2*s+1]);
}

ll get(int s,int l,int r,int i,int j)
{
    if(l > j || r < i) return INF;
    if(i <= l && r <= j) return val[s];
    int c = (l+r)/2;
    return min(get(2*s,l,c,i,j),get(2*s+1,c+1,r,i,j));
}

int main()
{
    freopen("SUM2.inp","r",stdin);
    freopen("SUM2.out","w",stdout);
    scanf("%d%d%d",&n,&L,&U);
    For(i,1,n)
    {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = -INF;
    For(i,1,n) if(i >= L && i <= U) ans = max(ans,sum[i]);
    For(i,1,n) update(1,1,n,i,sum[i]);
    For(i,L,n)
    {
        ll summin = get(1,1,n,max(i - U,1),max(i - L,1));
        ans = max(ans,sum[i] - summin);
    }
    cout << ans << endl;
}
