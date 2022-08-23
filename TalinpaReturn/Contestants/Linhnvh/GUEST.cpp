#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define INF 1e18
#define ll long long
#define fi first
#define se second
using namespace std;

int n;
ll c[maxn][maxn],d[maxn][maxn],f[maxn][maxn];

ll solve(int i,int j)
{
    if(f[i][j] != -1) return f[i][j];
    if(i == j) return f[i][j] = d[i][j];
    if(j - i == 1) return f[i][j] = min(min(d[i][j] + d[i][i],d[i][j] + d[j][j]),d[i][i] + d[j][j]);
    ll cur = INF;
    ll t1 = solve(i+1,j),t2 = solve(i,j-1);
    cur = min(cur,min(d[i][i],d[i][j]) + t1);
    cur = min(cur,min(d[i][j],d[j][j]) + t2);
    f[i][j] = cur;
    //cerr << i << ' ' << j << ' ' << f[i][j] << endl;
    return f[i][j];
}

int main()
{
    freopen("GUEST.inp","r",stdin);
    freopen("GUEST.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n)
        For(j,i,n){
            scanf("%lld",&c[i][j]);
            c[j][i] = c[i][j];
            d[i][j] = d[j][i] = c[i][j];
        }
    For(i,1,n)
        For(j,1,n) f[i][j] = -1;
    if(n <= 250)
        For(k,1,n)
            For(i,1,n)
                For(j,1,n)
                    d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
    cout << solve(1,n) << endl;
}
