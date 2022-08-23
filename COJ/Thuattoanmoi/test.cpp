#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxN 10000001
#define ll long long
using namespace std;
const int m_num = 10000000;
int T, num[maxN], prime[maxN];
ll ans, N, n;
int main()
{
    For(i,1, m_num)prime[i] = num[i] = 1;
    For(i,2, m_num)
        if(prime[i])
        {
            num[i] = -1;
            for(int j = 2; i * j <= m_num; j++)
            {
                prime[i * j] = 0;
                if(j % i == 0)num[i * j] = 0;
                else
                    num[i * j] *= -1;
            }
        }
    For(i,1,20) cout << i << ' ' << num[i] << endl;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%lld", &N);
        ans = 0;
        n = sqrt(N);
        for(ll i = 1; i <= n; i++)
            ans += 1ll * num[i] * N /(i * i);
        printf("%lld\n", ans);
    }
}
