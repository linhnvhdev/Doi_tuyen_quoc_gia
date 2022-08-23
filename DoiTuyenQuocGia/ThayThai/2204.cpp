#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 200005
using namespace std;

int n;
ll a[maxn],l[maxn],r[maxn],nl = 0,nr = 0;

ll check(ll mid, ll b[],ll nb)
{
    ll tmp = 0;
    For(i,1,nb) tmp += min(abs(b[i]),abs(mid - b[i]));
    return tmp;
}

ll Solve(ll a[],ll na,ll b[],ll nb)
{
    ll tmp = 0;
    For(i,1,na) tmp += abs(a[i]);
    ll L = 1, R = nb;
    while(R - L > 1)
    {
        ll mid = (L + R)/2;
        ll m1 = check(b[mid-1],b,nb);
        ll m2 = check(b[mid],b,nb);
        ll m3 = check(b[mid+1],b,nb);
        if(m1 <= m2 && m2 <= m3) R = mid;
        else if(m1 >= m2 && m2 >= m3) L = mid;
        else if(m2 < m1 && m2 < m3) return tmp + m2;
    }
    ll m1 = check(b[L-1],b,nb);
    ll m2 = check(b[L],b,nb);
    ll m3 = check(b[L+1],b,nb);
    ll ans = 1e18;
    for(ll mid = max(L-10,1ll);mid <= min(L+10,1ll*nb);mid++)
        ans = min(ans,check(b[mid],b,nb));
    return tmp + ans;
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n)
    {
        scanf("%lld",&a[i]);
        if(a[i] < 0) l[++nl] = -a[i];
        if(a[i] > 0) r[++nr] = a[i];
    }
    sort(l+1,l+1+nl);
    sort(r+1,r+1+nr);
    ll ans1 = Solve(l,nl,r,nr);
    ll ans2 = Solve(r,nr,l,nl);
    ///cout << ans1 << ' ' << ans2 << endl;
    cout << min(ans1,ans2) << endl;
    return 0;
}
