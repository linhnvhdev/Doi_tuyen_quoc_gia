#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 100005
#define ll long long
#define INF 1e18
using namespace std;

int n,m,cnt = 0;
ll x,y;
pair<ll,int> a[maxn],b[maxn];
pair<int,int> ans[maxn];

int main()
{
    fast_read;
    cin >> n >> m >> x >> y;
    For(i,1,n)
    {
        cin >> a[i].fi;
        a[i].se = i;
    }
    For(i,1,m)
    {
        cin >> b[i].fi;
        b[i].se = i;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    int j = 1;
    For(i,1,n)
    {
        int u = a[i].fi - x;
        int v = a[i].fi + y;
        while(j <= m && b[j].fi < u) j++;
        if(j > m) break;
        if(b[j].fi >= u && b[j].fi <= v)
        {
            ans[++cnt] = {a[i].se,b[j].se};
            j++;
        }
    }
    cout << cnt << endl;
    For(i,1,cnt) cout << ans[i].fi  << ' ' << ans[i].se << '\n';
}
