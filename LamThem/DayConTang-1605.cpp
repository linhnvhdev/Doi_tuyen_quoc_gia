#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
using namespace std;

const int mod = 1e9 + 7;
int n,k,a[maxn];
ll bit[maxn],f[15][maxn];

void update(int vt,ll v)
{
    for(int i = vt;i <= n;i += (i & (-i)))
        bit[i] = (bit[i] + v)%mod;
}

ll get(int vt)
{
    ll temp = 0;
    for(int i = vt;i > 0; i -= (i & (-i)))
        temp = (temp + bit[i]) % mod;
    return temp;
}

int main()
{
    cin >> n >> k;
    For(i,1,n) cin >> a[i];
    For(i,1,n) f[1][i] = 1;
    For(K,2,k+1){
        memset(bit,0,sizeof(bit));
        For(i,1,n){
            f[K][i] = get(a[i]);
            update(a[i],f[K-1][i]);
        }
    }
    ll ans = 0;
//    For(i,1,k+1)
//        For(j,1,n)
//            cout << "F " << i << ' ' << j << " : "  << f[i][j] << endl;
    For(i,1,n) ans =  (ans + f[k+1][i]) % mod;
    cout << ans << endl;
}
