#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
using namespace std;

typedef long long ll;

const int mod = 998244353;

ll gt[maxn];
ll f[maxn];
ll ngt[maxn];

void Init()
{
     gt[0] = f[0] = ngt[0] = 1;
     gt[1] = f[1] = ngt[1] = 1;
     for(int i = 2; i < maxn; ++i)
     {
         gt[i] = gt[i - 1] * i % mod;
         f[i] = f[mod % i] * (mod - mod / i) % mod;
         ngt[i] = ngt[i - 1] * f[i] % mod;
     }
}

ll calc(ll n, ll m)
{
     if(m > n || m < 0 || n < 0) return 0;
     return gt[n] * ngt[m] % mod * ngt[n - m] % mod;
}

int n, m , k;

int main()
{
     Init();
     int t;
     scanf("%d",&t);
     while(t--)
     {
         scanf("%d%d%d", &n, &m, &k);
         ll ans = 0;
         For(i,0,m)
         {
             ll d = k - 1ll * i * n + m - 1;
             if(d < 0) break;
             if(i % 2 == 1) ans = (ans - calc(m, i) * calc(d, m - 1) % mod + mod) % mod;
             else ans = (ans + calc(m, i) * calc(d, m - 1) % mod) % mod;
         //    cout << i << " " << m << " " << calc(m, i);
         //    cout << d << " " << m - 1 << " " << calc(d, m - 1) << endl;
         }
         printf("%lld\n", ans);
     }
     return 0;
}
