#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(long long i = a; i <= b; ++i)
#define maxn 300005
#define INF 1e18
#define fi first
#define se second
using namespace std;

int n,a,b;
pair<ll,int> d[maxn];

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >> a >> b;
    For(i,1,n)
    {
        scanf("%lld%d",&d[i].fi,&d[i].se);
    }
    sort(d+1,d+1+n);
    //For(i,1,n) cerr << d[i].fi << ' ' << d[i].se << endl;
    ll ans = INF;
    d[0] = {0,0};
    ll st = 0;
    int t1 = 0,t2 = 0;
    For(i,1,n)
    {
        //cerr << "### " << i << endl;
        if(d[i].se == 1) t1++;
        else t2++;
        if(t1 >= a && t2 >= b)
        {
            //cerr << t1 << ' ' << t2 << ' ' << st << ' ' << ans << endl;
            ans = min(ans,d[i].fi - d[st].fi);
            while(st <= i && t1 >= a && t2 >= b)
            {
                if(d[st].se == 1) t1--;
                if(d[st].se == 2) t2--;
                st++;
                if(t1 >= a && t2 >= b) ans = min(ans,d[i].fi - d[st].fi);
                //cerr << t1 << ' ' << t2 << ' ' << st << ' ' << ans << endl;
            }
        }
    }
    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;
}
