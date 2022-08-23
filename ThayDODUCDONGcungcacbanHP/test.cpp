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
