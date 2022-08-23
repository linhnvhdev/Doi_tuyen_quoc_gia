#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

int n;
ll a[maxn];

ll d[305][1205];
pii trc[305][1205];

bool Sub2 = true;

void truyvet(int i,int j)
{
    if(i == 0) return;
    truyvet(i-1,trc[i][j].se);
    printf("%d ",j - 600);
}

void sub2()
{
    For(i,1,n) a[i] += 600;
    For(i,1,n)
        For(j,0,1200) d[i][j] = INF;
    For(j,0,1200) d[1][j] = abs(a[1] - j);
    For(i,2,n)
        For(j,1,1200)
            For(k,0,j-1)
            {
                if(d[i][j] > d[i-1][k] + abs(a[i] - j))
                {
                    d[i][j] = d[i-1][k] + abs(a[i] - j);
                    trc[i][j] = {i-1,k};
                }
            }
    pair<ll,int>  best = {INF,0};
    For(j,0,1200)
    {
        if(best.fi > d[n][j])
        {
            best = {d[n][j],j};
        }
    }
    cout << best.fi << endl;
    //cerr << trc[n][305].fi << ' ' << trc[n][305].se << ' ' << d[n][305] << endl;
    truyvet(n,best.se);
}

void Sub1()
{
    pair<pair<ll,ll>,ll> ans;
    if(a[1] < a[2] && a[2] < a[3])
        ans = {{a[1],a[2]},a[3]};
    else if(a[1] >= a[2] && a[2] >= a[3])
            ans = {{a[2] - 1,a[2]},a[2] + 1};
    else if(a[1] >= a[2] && a[2] <= a[3])
            ans = {{a[2] - 1,a[2]},a[3]};
    else if(a[1] <= a[2] && a[2] >= a[3])
    {
        if(a[3] <= a[1] + 2) ans = {{a[1],a[1] + 1},a[1] + 2};
        else ans = {{a[1],a[3] - 1},a[3]};
    }
    cout << abs(ans.fi.fi - a[1]) + abs(ans.fi.se - a[2]) + abs(ans.se - a[3]) << endl;
    cout << ans.fi.fi << ' ' << ans.fi.se << ' ' << ans.se << endl;
    exit(0);
}

int main()
{
    freopen("SEQUENCE.inp","r",stdin);
    freopen("SEQUENCE.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n)
    {
        scanf("%lld",&a[i]);
        if(a[i] > 300) Sub2 = false;
    }
    if(n == 3) Sub1();
    if(n <= 300 && Sub2) sub2();
}
