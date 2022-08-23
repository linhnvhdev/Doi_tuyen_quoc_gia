#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(long long i = a; i <= b; ++i)
#define maxn 1506
#define INF 1e18
#define fi first
#define se second
using namespace std;

int t,m,n;
ll a[maxn],b[maxn];

ll f[maxn][maxn];

void Sub12()
{
    For(i,0,m)
        For(j,0,n) f[i][j] = 0;
    b[n+1] = INF;
    For(i,1,m)
    {
        int vt = -1;
        For(j,1,n+1)
        {
            f[i][j] = f[i-1][j]; /// ko chon
            if(b[j] >= 2*a[i])
                if(vt != -1) f[i][j] = max(f[i][j],f[i-1][vt] + 1);
            if(b[j] == a[i]) vt = j;
        }
    }
    cout << f[m][n+1] << endl;
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&m,&n);
        For(i,1,m) scanf("%lld",&a[i]);
        For(i,1,n) scanf("%lld",&b[i]);
        Sub12();
    }
}
