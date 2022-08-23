#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 505
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

int n,k,r,p;
ll a[maxn][maxn],sum[maxn][maxn],x[100005][6],y[100005][6];

ll get(int i,int j,int u,int v)
{
    if(i > u || j > v) return 0;
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

ll Solve(ll x[],ll y[])
{
    //cerr << ":)\n";
    //For(j,1,p) cerr << x[j] << ' ' << y[j] << endl;
    ll tmp = 0;
    for(int i = 1;i < (1 << p); i++)
    {
        int d = 0;
        ll X = -INF,Y = -INF,U = INF,V = INF;
        For(j,0,p-1)
            if(Bit(i,j))
            {
                d++;
                X = max(X,x[j+1]);
                Y = max(Y,y[j+1]);
                U = min(U,x[j+1] + r - 1);
                V = min(V,y[j+1] + r - 1);
            }
        ll t = get(X,Y,U,V);
        //cerr << i << ' ' << X << ' ' << Y << ' ' << U << ' ' << V << ' ' << t << endl;
        tmp += (d % 2 == 1) ? t : -t;
    }
    return tmp;
}

int main()
{
    freopen("BONUS.inp","r",stdin);
    freopen("BONUS.out","w",stdout);
    scanf("%d%d%d%d",&n,&k,&r,&p);
    For(i,1,n)
        For(j,1,n)
        {
            scanf("%lld",&a[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + a[i][j] - sum[i-1][j-1];
        }
    ll ans = 0;
    For(i,1,k)
    {
        ll tmp = 0;
        For(j,1,p)
        {
            scanf("%lld%lld",&x[i][j],&y[i][j]);
        }
        ans = max(ans,Solve(x[i],y[i]));
    }
    cout << ans << endl;
}
