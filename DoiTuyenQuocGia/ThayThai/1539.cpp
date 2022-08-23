#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
#define x first
#define y second
#define INF 1e18
#define Bit(x,i) ((x>>i)&1)
using namespace std;

typedef pair<ll,ll> point;

point operator - (point a,point b)
{
    return {a.x - b.x,a.y - b.y};
}

ll operator * (point a,point b)
{
    return a.x*b.y - a.y*b.x;
}

struct dagiac
{
    int n,color;
    ll S;
} a[maxn];

int m,k;
point p[maxn][maxn];

ll S(point d[maxn],int n)
{
    ll tmp = 0;
    For(i,1,n)
        tmp += d[i]*d[i+1];
    return abs(tmp);
}

bool cmp(dagiac x,dagiac y)
{
    return x.S < y.S;
}

ll dp[maxn];

int main()
{
    cin >> m >> k;
    For(i,1,m)
    {
        scanf("%d%d",&a[i].n,&a[i].color);
        For(j,1,a[i].n)
        {
            scanf("%lld%lld",&p[i][j].x,&p[i][j].y);
        }
        p[i][a[i].n+1] = p[i][1];
        a[i].S = S(p[i],a[i].n);
    }
    sort(a+1,a+1+m,cmp);
    ll ans = 0;
    For(mau,1,m)
    {
        For(i,1,m) dp[i] = dp[i-1] + (a[i].color != mau);
        int j = 1;
        ll sum = 0;
        For(i,1,m)
        {
            sum += (a[i].S - a[i-1].S);
            while(dp[i] - dp[j-1] > k)
            {
                sum -= (a[j].S - a[j-1].S);
                j++;
            }
            ans = max(ans,sum);
        }
    }
    if(ans % 2 == 0) cout << ans/2 << ".0\n";
    else cout << ans/2 << ".5\n";
    return 0;
}
