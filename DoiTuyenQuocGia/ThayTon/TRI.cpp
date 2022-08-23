#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int m,n,k;
ll a[maxn][maxn],sum[maxn][maxn];

ll get_sum(int i,int j,int u,int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

ll f[maxn][maxn];

void Sub2()
{
    ll ans = -INF;
    For(i,1,m-k+1)
        For(j,1,n-k+1)
        {
            ll cur = 0;
            int curx = i,cury = j;
            //cout << "###### " << i << ' ' << j << endl;
            For(t,1,k)
            {
                //cout << curx << ' ' << cury << ' ' << curx << ' ' << cury + t - 1 << endl;
                cur += get_sum(curx,cury,curx,cury + t - 1);
                curx++;
            }
            ans = max(ans,cur);
        }
    cout << ans << endl;
}

void AC()
{
    ll ans = -INF;
    For(j,1,n-k+1)
    {
        ll cur = 0;
        int curx = 1, cury = j;
        For(t,1,k)
        {
            cur += get_sum(curx,cury,curx,cury + t - 1);
            f[1][j] += get_sum(curx,1,curx,cury + t - 1);
            curx++;
        }
        //cout << 1 << ' '<< j << ' ' << f[1][j] << endl;
        ans = max(ans,cur);
    }
    For(i,2,m-k+1)
    {
        ll cur = 0;
        int curx = i, cury = 1;
        For(t,1,k)
        {
            cur += get_sum(curx,cury,curx,cury + t - 1);
            f[i][1] += get_sum(curx,1,curx,cury + t - 1);
            curx++;
        }
        ans = max(ans,cur);
    }
    For(i,2,m-k+1)
    {
        For(j,2,n-k+1)
        {
            ll cur = f[i-1][j-1] - get_sum(i-1,1,i-1,j-1) + get_sum(i + k - 1,1,i + k - 1,j + k - 1);
            f[i][j] = cur;
            ans = max(ans,cur - get_sum(i,1,i + k - 1,j - 1));
        }
    }
    cout << ans << endl;
}

int main()
{
    fast_read;
    freopen("TRI.inp","r",stdin);
    freopen("TRI.out","w",stdout);
    cin >> m >> n >> k;
    For(i,1,m)
        For(j,1,n)
        {
            cin >> a[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    if(m <= 500 && n <= 500) Sub2();
    else AC();
}
