#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define ll long long
#define fi first
#define se second
using namespace std;

ll f[1005][10005],s[10005];
ll n,c;
const ll mod = 1e9+7;
ll get(int i,int j){
    if(i == 0) return s[j] % mod;
    return (s[j] - s[i-1] + mod) % mod;
}
int main()
{
    freopen("conf.inp","r",stdin);
    freopen("conf.out","w",stdout);
    cin >> n >> c;
    f[1][0] = 1;
    f[2][0] = 1;
    f[2][1] = 1;
    s[0] = 1;
    s[1] = 2;
    For(i,2,10000)
        s[i] = 2;
    For(i,3,n){
        f[i][0] = 1;
        For(j,1,c){
            f[i][j] = (f[i][j] + get(max(0,j - i + 1),j)) % mod;
        }
        s[0] = 1;
        For(j,1,c) s[j] = (s[j-1] + f[i][j]) %mod;
    }
    cout << f[n][c];
}
