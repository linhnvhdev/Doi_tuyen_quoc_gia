#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define INF 1e18
#define maxn 100005
#define Bit(x,i) ((x >> i)&1)
#define ll long long
#define fi first
#define se second
using namespace std;

int n;
ll a[maxn],sum[maxn],child[32*maxn][3],x;
ll cnt = 0;
ll d[32*maxn];

void Add(ll s)
{
    ll u = 0;
    Forr(i,30,0)
    {
        int k = Bit(s,i);
        if(child[u][k] == 0) child[u][k] = ++cnt;
        u = child[u][k];
        d[u]++;
    }
}

ll get(ll s)
{
    ll u = 0,tmp = 0;
    Forr(i,30,0)
    {
        int k = Bit(s,i);
        int t = Bit(x,i);
        if(t == 0)
        {
            tmp += d[child[u][1-k]];
            u = child[u][k];
        }
        else u = child[u][1-k];
        if(u == 0) return tmp;
    }
    if(u != 0) tmp += d[u];
    return tmp;
}

int main()
{
    //freopen("1775.inp","r",stdin);
    //freopen("1775.out","w",stdout);
    scanf("%d%lld",&n,&x);
    For(i,1,n) scanf("%lld",&a[i]);
    Add(0);
    ll ans = 0;
    For(i,1,n){
        sum[i] = sum[i-1]^a[i];
        ans += get(sum[i]);
        Add(sum[i]);
    }
    cout << ans << endl;
}
