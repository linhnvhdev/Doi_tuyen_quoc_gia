#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 100005
#define fi first
#define se second
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

const int mod = 1e9+7;
const int base = 128;

int n;
ll h[maxn],p[maxn];

ll get_hash(int i,int j)
{
    return ((h[j] - h[i-1]*p[j-i+1]) % mod + mod)%mod;
}

bool check(int t)
{
    h[0] = 0;
    For(j,0,n-1)
    {
        h[j+1] = (h[j]*base + Bit(t,j)) % mod;
        if(j > 0 && Bit(t,j) == Bit(t,j-1) && Bit(t,j) == 1) return false;
    }
    For(i,1,n)
    {
        For(j,1,n/3)
        {
            if(i + j*3 - 1 > n) break;
            ll m1 = get_hash(i,i+j-1);
            ll m2 = get_hash(i+j,i+2*j-1);
            ll m3 = get_hash(i+2*j,i+3*j-1);
            if(m1 == m2 && m2 == m3) return false;
        }
    }
    return true;
}

int main()
{
    freopen("STR.inp","r",stdin);
    freopen("STR.out","w",stdout);
    scanf("%d",&n);
    if(n > 16)
    {
        cout << 0 << endl;
        return 0;
    }
    p[0] = 1;
    For(i,1,n) p[i] = p[i-1]*base % mod;
    int ans = 0;
    for(int i = 0;i < (1<<n);i++)
    {
        ans += check(i);
    }
    cout << ans << endl;
}
