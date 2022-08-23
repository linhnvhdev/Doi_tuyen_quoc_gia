#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1000005
#define ll long long
#define INF 1e9
using namespace std;

int n,m;
ll a[maxn],b[maxn],sum[maxn],h[maxn],s[maxn],k;
int maxgiao = 0;

int main()
{
    fast_read;
    cin >> n >> m >> k;
    For(i,1,n)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    ll ans = 0;
    For(i,1,m)
    {
        int l,r;
        cin >> l >> r;
        ans += sum[r] - sum[l-1];
        h[l]++;
        h[r+1]--;
    }
    int cur = 0;
    For(i,1,n)
    {
        cur = cur + h[i];
        //cout << i << ' ' << cur << endl;
        s[cur] += a[i];
        maxgiao = max(maxgiao,cur);
    }
    Forr(i,maxgiao,1)
    {
        if(k == 0) break;
        if(s[i] == 0) continue;
        ans -= 1ll*min(s[i],k)*i;
        k -= min(k,s[i]);
    }
    cout << ans << endl;
}
