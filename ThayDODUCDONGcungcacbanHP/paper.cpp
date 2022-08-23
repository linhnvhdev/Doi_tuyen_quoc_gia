/*
    Bản chất: Chọn C đoạn sao cho giao của C đoạn -> 1 đoạn >= k
    Giả sử đó là đoạn l,r => r - l + 1 >= k
    (L^c - (L-1)^c)*((n-R+1)^c-(n-R)^c)
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define Bit(x,i) ((x >> i)&1)
#define fi first
#define se second
#define ll long long
using namespace std;

const int mod = 1e9+7;
int t,c,n,m,k;
ll a[maxn],b[maxn];

ll luythua(ll a,int hs)
{
    ll p = a,test = 1;
    while(hs > 0){
        if(hs % 2 == 1) test = (test * p)%mod;
        p = (p*p)%mod;
        hs /= 2;
    }
    return test % mod;
}

int main()
{
    freopen("paper.inp","r",stdin);
    freopen("paper.out","w",stdout);
    scanf("%d",&t);
    //cerr << luythua(2,8) << endl;
    while(t--){
        scanf("%d%d%d%d",&c,&n,&m,&k);
        ll k1 = 0;
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        For(l,1,m)
            For(r,l,m){
                //cerr << l << ' ' << r << endl;
                ll ans1 = (luythua(l,c) - luythua(l-1,c) + mod)%mod;
                ll ans2 = (luythua(m - r + 1,c) - luythua(m - r,c) + mod)%mod;
                a[r-l+1] = (a[r-l+1] + ans1*ans2%mod )%mod;
            }
        For(l,1,n)
            For(r,l,n){
                //cerr << l << ' ' << r << endl;
                ll ans1 = (luythua(l,c) - luythua(l-1,c) + mod)%mod;
                ll ans2 = (luythua(n - r + 1,c) - luythua(n - r,c) + mod)%mod;
                b[r-l+1] = (b[r-l+1] + ans1*ans2%mod )%mod;
            }
        ll ans = 0;
        For(i,1,m)
            For(j,1,n)
                if(i*j >= k) ans = (ans + a[i]*b[j]%mod)%mod;
        printf("%lld\n",ans);
    }
}
