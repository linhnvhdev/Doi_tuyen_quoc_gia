/*
    Sub2: F(n,p) (chèn min) -> F(n+1,p)
                            -> F(n+1,p+1)
    F[0][0] = 1;
    For(i,0,n-1)
        For(j,0,min(p,i)){
            f[i+1][j+1] += f[i][j];
            f[i+1][j] += f[i][j]*i
        }
    => F[n][p];
    Sub cuối :
    Đặt cái cao nhất ở vị trí i
    => = nửa trái * nửa phải
*/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define ll long long
using namespace std;

int mod = 1e9+7;
int n,p,q,a[maxn];
ll f[maxn][maxn],C[maxn][maxn];

void CountC()
{
    //C[k][n] = C[k-1][n-1] + C[k][n-1]
    C[0][0] = C[0][1] = 1;
    For(i,1,n) C[0][i] = 1;
    For(j,1,n){
        For(i,1,n){
            C[i][j] = (C[i-1][j-1] + C[i][j-1])%mod;
         //   cerr << i << ' ' << j << ' ' << C[i][j] << endl;
        }
    }
    //cerr << C[2][4] << endl;
}

int main()
{
    //freopen("queue.inp","r",stdin);
    //freopen("queue.out","w",stdout);
    scanf("%d%d%d",&n,&p,&q);
    For(i,1,n) scanf("%d",&a[i]);
    f[0][0] = 1;
    For(i,0,n-1)
        For(j,0,min(i,max(p,q))){
            f[i+1][j+1] = (f[i+1][j+1] + f[i][j])%mod;
            f[i+1][j] = (f[i+1][j] + f[i][j]*i)%mod;
        }
    CountC();
    //cout << f[n-1][p-1] << endl;
    ll ans = 0;
    For(i,1,n){
        ans = ans + ((f[i-1][p-1]*f[n-i][q-1])%mod)*C[i-1][n-1];
        ans %= mod;
    }
    //cerr << C[5][9] << endl;
    cout << ans << endl;
}
