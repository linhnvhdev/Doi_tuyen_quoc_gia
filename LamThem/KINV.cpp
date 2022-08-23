//http://vnoi.info/problems/KINV/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 10005
#define x first.first
#define h first.second
#define id second
using namespace std;

int n,k;
const int mod = 1e9;

ll a[maxn],dp[maxn],bit[maxn],f[maxn],MaxA,g[maxn];

void compress()
{
    int cnt = 0;
    ll cp[maxn];
    For(i,1,n) cp[i] = a[i];
    sort(cp+1,cp+1+n);
    MaxA = unique(cp+1,cp+1+n) - cp - 1;
    For(i,1,n)
        a[i] = lower_bound(cp+1,cp+1+MaxA,a[i]) - cp;
    //cout << MaxA << endl; For(i,1,n) cout << a[i] << endl;
}

void update(int vt,ll v)
{
    for(int i = vt;i <= MaxA;i += (i & (-i)))
        bit[i] = (bit[i] + v)%mod;
}

ll get(int vt)
{
    ll test = 0;
    for(int i = vt;i > 0;i -= (i & (-i)))
        test = (test + bit[i])%mod;
    return test%mod;
}

int main()
{
    scanf("%d%d",&n,&k);
    For(i,1,n) scanf("%lld",&a[i]);
    compress();
    For(i,1,n){
        update(a[i],1);
        g[i] = 1;
    }
    For(i,2,k){
        memset(bit,0,sizeof(bit));
        For(j,1,n){
            f[j] = (get(a[j]-1))%mod;
            update(a[j],g[j]);
        }
        For(j,1,n) swap(f[j],g[j]);
        For(j,1,n) cout << f[i] << ' ' << g[i]
    }
    ll ans = 0;
    For(i,1,n) ans = (ans + g[i])%mod;
    cout << ans << endl;
}
