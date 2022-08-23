#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 500005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int T,n;
ll x,y,a[maxn],b[maxn];
ll ans = INF,maxa;

void dfs(int i,ll cur,int l,int r,ll cost)
{
    //cout << i << ' ' << cur << ' ' << l << ' ' << r << ' ' << cost << endl;
    if(cur == 1) return;
    if(i > n)
    {
        if(cur > 1) ans = min(ans,cost);
        return;
    }
    if(i == l) dfs(r+1,cur,l,r,cost);
    else
    {
        dfs(i+1,__gcd(cur,a[i]),l,r,cost);
        dfs(i+1,__gcd(cur,a[i]-1),l,r,cost + y);
        dfs(i+1,__gcd(cur,a[i]+1),l,r,cost + y);
    }
}

void Sub1()
{
    ans = INF;
    dfs(1,0,0,0,0);
    //cout << ":)";
    For(l,1,n)
        For(r,l+1,n)
        {
            dfs(1,0,l,r,x*(r-l+1));
        }
    cout << ans << endl;
}

ll dp[maxn];

void Sub2()
{
    ans = INF;
    For(g,2,sqrt(maxa))
    {
        //cout << "### " << g << endl;
        ll tmp = 0;
        bool ok = true;
        For(i,1,n)
        {
            ll r = a[i] % g;
            if(r == 0 || r == 1 || r == g-1)
            {
                if(r == 1 || r == g-1) tmp += y;
            }
            else
            {
                ok = false;
                break;
            }
        }
        //cout << ok << ' ' << tmp << endl;
        if(ok) ans = min(ans,tmp);
    }
    cout << ans << endl;
}

int main()
{
    fast_read;
    freopen("HSGS.inp","r",stdin);
    freopen("HSGS.out","w",stdout);
    cin >> T;
    while(T--)
    {
        maxa = 0;
        cin >> n >> x >> y;
        For(i,1,n)
        {
            cin >> a[i];
            maxa = max(maxa,a[i]);
        }
        if(n <= 10) Sub1();
        else
            Sub2();
    }
}
