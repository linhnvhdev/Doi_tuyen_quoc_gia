/*
    f[d][p](ngay d xep p ng) -> f[d+1][p] += f[d][p]*p
                             -> f[d+1][p+1] += f[d][p]
    -> g[n][k] = f[n][k] * k!
*/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 105
#define ll long long
using namespace std;

const int maxnum = 200;
typedef int bignum[maxnum+1];
int k,n;
bignum f[maxn][maxn],ans;

void cong(bignum a,bignum b,bignum c)
{
    int nho = 0;
    Forr(i,maxnum,1){
        c[i] = a[i] + b[i] + nho;
        nho = c[i]/10;
        c[i] %= 10;
    }
}

void gan(bignum a,bignum b)
{
    For(i,1,maxnum) b[i] = a[i];
}

void nhan(bignum a,ll b,bignum c)
{
    int nho = 0;
    Forr(i,maxnum,1){
        c[i] = a[i]*b + nho;
        nho = c[i] / 10;
        c[i] %= 10;
    }
}

int main()
{
    //freopen("dinner.inp","r",stdin);
    //freopen("dinner.out","w",stdout);
    cin >> k >> n;
    f[0][0][maxnum] = 1;
    For(i,0,n-1)
        For(j,0,min(k,i)){
            bignum t;
            memset(t,0,sizeof(t));
            t[maxnum] = 1;
            nhan(f[i][j],j,t);
            cong(f[i+1][j],t,f[i+1][j]);
            cong(f[i+1][j+1],f[i][j],f[i+1][j+1]);
        }
    gan(f[n][k],ans);
    For(i,1,k) nhan(ans,i,ans);
    int i = 1;
    for(;i < maxnum;i++) if(ans[i] != 0) break;
    for(;i <= maxnum;i++) printf("%d",ans[i]);
}

/*
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 105
#define ll long long
using namespace std;

int k,n;
ll f[maxn][maxn];

int main()
{
    freopen("dinner.inp","r",stdin);
    freopen("dinner.out","w",stdout);
    cin >> k >> n;
    f[0][0] = 1;
    For(i,0,n-1)
        For(j,0,min(k,i)){
            f[i+1][j] += f[i][j]*j;
            f[i+1][j+1] += f[i][j];
        }
    ll ans = f[n][k];
    For(i,1,k) ans *= i;
    cout << ans << endl;
}
*/
