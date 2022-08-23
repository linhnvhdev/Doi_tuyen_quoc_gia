#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e9
using namespace std;

int n,s,a[maxn],sum[maxn];
int f[maxn][55];

int tong(int i,int j)
{
    return (sum[j] - sum[i-1]);
}

int main()
{
    //freopen("SPSEQ.inp","r",stdin);
    //freopen("SPSEQ.out","w",stdout);
    scanf("%d%d",&n,&s);
    For(i,1,n){
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    s = s + 1;
    For(i,0,n)
        For(j,0,s) f[i][j] = INF;
    For(i,1,n) f[i][1] = sum[i];
    For(i,2,n)
        For(k,2,min(s,i))
            For(j,1,i-1)
                f[i][k] = min(f[i][k],max(f[j][k-1],tong(j+1,i)));
    cout << f[n][s] << endl;
}
