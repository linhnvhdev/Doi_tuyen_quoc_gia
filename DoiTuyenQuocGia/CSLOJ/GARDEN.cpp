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

int n,m;

int a[maxn][maxn],sum[maxn][maxn];

int getsum(int i,int j,int u,int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

bool check(int i,int j,int u,int v)
{
    return (getsum(i,j,u,v) == (u-i+1)*(v-j+1));
}

ll dem1(int x,int y)
{
    ll tmp = 0;
    For(i,1,x)
    For(j,1,y)
    For(u,x,m)
    For(v,y,n)
        tmp += check(i,j,u,v);
    return tmp;
}

void Sub1()
{
    ll ans = 0;
    For(i,1,m)
        For(j,1,n)
        {
            ans += dem1(i,j);
        }
    cout << ans << endl;
    exit(0);
}

void Sub2()
{
    ll ans = 0;
    For(i,1,m)
        For(j,1,n)
        {
            ll demij = 0;
            For(k,j,n)
            {
                if(!check(i,j,i,k)) break;
                int l = i,r = m;
                while(r - l > 1)
                {
                    int mid = (l+r)/2;
                    if(check(i,j,mid,k)) l = mid;
                    else r = mid;
                }
                int cur = (check(i,j,r,k)) ? r : l;
                ll add = 1ll*(k-j+1)* 1ll*(cur-i+1)*(cur-i+2)/2;
                ans += add;
            }
        }
    cout << ans << endl;
}

string s;

int main()
{
    freopen("GARDEN.inp","r",stdin);
    freopen("GARDEN.out","w",stdout);
    fast_read;
    cin >> m >> n;
    For(i,1,m)
    {
        cin >> s;
        For(j,1,n)
        {
            a[i][j] = (s[j-1] == '.') ? 1 : 0;
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    }
    if(m <= 10 && n <= 10) Sub1();
    if(m <= 300 && n <= 300) Sub2();
}
