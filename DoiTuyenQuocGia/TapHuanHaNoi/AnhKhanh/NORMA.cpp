#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 500005
#define ll long long
using namespace std;

const int mod = 1e9;
int n;
ll ans = 0,a[maxn];
ll rmin[maxn][25],rmax[maxn][25];

ll get_min(int l,int r)
{
    int lg = log2(r - l + 1);
    return min(rmin[l][lg],rmin[r-(1<<lg)+1][lg]);
}

ll get_max(int l,int r)
{
    int lg = log2(r - l + 1);
    return max(rmax[l][lg],rmax[r-(1<<lg)+1][lg]);
}

int main()
{
    scanf("%d",&n);
    For(i,1,n) scanf("%lld",&a[i]);
    For(i,1,n) rmin[i][0] = rmax[i][0] = a[i];
    For(j,1,19)
        For(i,1,n)
        {
            if(i+(1<<j)-1 <= n) rmin[i][j] = min(rmin[i][j-1],rmin[i + (1<<(j-1))][j-1]);
            if(i+(1<<j)-1 <= n) rmax[i][j] = max(rmax[i][j-1],rmax[i + (1<<(j-1))][j-1]);
        }
    ll ans = 0;
    For(l,1,n)
        For(r,l,n)
        {
            ans += (get_min(l,r)*get_max(l,r)%mod)*(r - l + 1)%mod;
            ans %= mod;
        }
    cout << ans << endl;
}
