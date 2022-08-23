#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,a[maxn],b[maxn];
int f[maxn][maxn];

int main()
{
    freopen("STAIRCASE.inp","r",stdin);
    freopen("STAIRCASE.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n)
        scanf("%d",&a[i]);
    f[1][1] = 1;
    f[2][1] = 2;
    f[2][2] = 1;
    For(i,3,n){
        f[i][1] = i;
        For(j,2,i)
            f[i][j] = f[i-1][f[i-1][j-1]];
    }
    For(i,1,n) b[f[n][i]] = a[i];
    For(i,1,n) printf("%d ",b[i]);
}
