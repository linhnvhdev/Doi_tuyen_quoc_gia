/**
    Thứ tự của dữ liệu đầu vào không làm thay đổi kết quả bài toán => sort tăng dần

**/


#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 5005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

const int mod = 1e9+7;

int n;
ll a[maxn];

ll f[maxn][maxn];

int used[maxn];

void Sub1()
{
    ll ans = 0;
    for(int i = 0; i < (1<<n);i++)
    {
        ll curmax = 0,sum = 0;
        int d = 0;
        For(j,0,n-1)
            if(Bit(i,j))
            {
                curmax = max(curmax,a[j+1]);
                sum += a[j+1];
                d++;
            }
        if(d <= 2) continue;
        sum = sum - curmax;
        if(curmax < sum) ans++;
    }
    cout << ans % mod << '\n';
    exit(0);
}


int main()
{
    freopen("POLYGON.inp","r",stdin);
    freopen("POLYGON.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> a[i];
        used[a[i]]++;
    }
    if(n <= 10) Sub1();
    f[1][a[1]] = 1;
    For(i,1,n) f[i][0] = 1;
    For(i,2,n)
    {
        For(j,1,4000)
        {
            if(j >= a[i]) f[i][j] = (f[i-1][j] + f[i-1][j-a[i]])%mod;
            else f[i][j] = f[i-1][j];
        }
    }
    ll thua = 0;
    For(i,1,n)
        For(j,1,a[i])
            if(f[n][j] != 0) thua = ((thua + f[n][j] - used[j]) % mod + mod)%mod;
    ll ans = 1;
    For(i,1,n) ans = ans*2%mod;
    cout << ((ans - 1 - n - 1ll*n*(n-1)/2 - thua) % mod + mod)%mod << endl;
}
