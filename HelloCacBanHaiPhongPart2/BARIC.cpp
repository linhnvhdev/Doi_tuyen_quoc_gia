#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 105
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n;
ll a[maxn],s[maxn][maxn],f[maxn][maxn];
ll E;

int main()
{
    freopen("BARIC.inp","r",stdin);
    freopen("BARIC.out","w",stdout);
    scanf("%d%lld",&n,&E);
    For(i,1,n) scanf("%lld",&a[i]);
    For(i,0,n)
        For(j,i+1,n+1)
            For(k,i+1,j-1){
                int l = a[i];
                int r = a[j];
                if(i == 0) l = r;
                if(j == n+1) r = l;
                s[i][j] += abs(2*a[k] - l - r);
            }
    For(i,0,n+1)
        For(j,0,n+1)
            f[i][j] = INF;
    For(i,1,n+1) f[i][0] = s[0][i];
    For(k,1,n)
        For(i,1,n+1)
            For(j,1,i-1)
                f[i][k] = min(f[i][k],f[j][k-1] + s[j][i]);
    For(i,1,n)
        if(f[n+1][i] <= E){
            printf("%d %lld\n",i,f[n+1][i]);
            return 0;
        }
}
