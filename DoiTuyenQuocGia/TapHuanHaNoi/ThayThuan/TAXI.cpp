#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 40
#define ll long long
#define fi first
#define se second
#define INF 1e9+1
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n;
int a[maxn][maxn],f[25][(1<<21)];

int main()
{
    scanf("%d",&n);
    int N = n/2;
    For(i,0,n)
        For(j,0,n)
            scanf("%d",&a[i][j]);
    For(i,0,n)
        For(j,0,(1<<n)) f[i][j] = INF;
    For(i,1,N) f[i][1<<(i-1)] = a[0][i];
    For(mask,1,(1<<n)-1)
        For(i,0,n-1)
        {
            if(!Bit(mask,i)) continue;
            if(i+1 > N && !Bit(mask,i - N)) break;
            For(j,0,n-1)
            {
                if(!Bit(mask,j) || i == j) continue;
                if(j+1 > N && !Bit(mask,j - N)) break;
                ll val = f[j+1][(mask^(1<<i))] + a[j+1][i+1];
                if(f[i+1][mask] > val) f[i+1][mask] = val;
            }
        }
    int ans = INF;
    For(i,N+1,n)
        ans = min(ans,f[i][(1<<n)-1] + a[i][0]);
    cout << ans << endl;
}
