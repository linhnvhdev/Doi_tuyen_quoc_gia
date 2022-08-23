#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
using namespace std;

int m,n,k;
ll a[maxn][maxn],b[maxn][maxn],sum[maxn][maxn];
ll d[maxn][maxn];
ll r[maxn],c[maxn],f[maxn],r2[maxn][maxn];
ll ans = 0;

ll get_sum(int i,int j,int u,int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

void Solve1()
{
    memset(r,0,sizeof(r));
    For(i,1,m)
        For(j,1,n)
            r[i] = max(r[i],b[i][j]);
    ll max1 = r[1];
    f[m] = r[m];
    Forr(i,m-1,1)
        f[i] = max(f[i+1],r[i]);
    For(i,k+1,m-k)
    {
        ans = max(ans,max1 + r[i] + f[i+k]);
        max1 = max(max1,r[i-k+1]);
    }
}

void Solve2()
{
    memset(r2,0,sizeof(r));
    memset(c,0,sizeof(c));
    For(i,1,m)
        For(j,1,n) c[j] = max(c[j],b[i][j]);
    For(i,1,m)
        Forr(j,n,1)
            r2[i][j] = max(r2[i][j+1],b[i][j]);
    ll maxc = c[1];
    For(j,k+1,n)
    {
        f[1] = r2[1][j];
        For(i,2,m) f[i] = max(f[i-1],r2[i][j]);
        For(i,k+1,m)
            ans = max(ans,maxc + r2[i][j] + f[i-k]);
        maxc = max(maxc,c[j-k+1]);
    }
}

void Xoay()
{
    For(i,1,m)
        For(j,1,n) d[i][j] = b[i][j];
    For(i,1,m)
        For(j,1,n)
            b[n-j+1][i] = d[i][j];
    swap(m,n);
}

int main()
{
    freopen("OIL.inp","r",stdin);
    freopen("OIL.out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    For(i,1,m)
        For(j,1,n)
        {
            scanf("%lld",&a[i][j]);
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
        }
    For(i,1,m-k+1)
        For(j,1,n-k+1)
            b[i][j] = get_sum(i,j,i+k-1,j+k-1);
    m = m - k + 1;
    n = n - k + 1;
    For(i,1,4)
    {
        Solve1();
        Solve2();
        Xoay();
    }
    cout << ans << endl;
}
