#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

const int mod = 1e9+7;
int n,k;
int a[maxn],bit[maxn];
ll gt[maxn];

void update(int pos,int v)
{
    for(int i = pos; i <= n;i += (i&(-i)))
        bit[i] += v;
}

int get(int pos)
{
    int tmp = 0;
    for(int i = pos;i > 0;i -= (i&(-i)))
        tmp += bit[i];
    return tmp;
}

void Sub1()
{
    gt[0] = gt[1] = 1;
    For(i,2,n) gt[i] = gt[i-1]*i%mod;
    while(k--)
    {
        memset(bit,0,sizeof(bit));
        int u,v;
        scanf("%d%d",&u,&v);
        swap(a[u],a[v]);
        ll Rank = 1;
        For(i,1,n) update(i,1);
        For(i,1,n)
        {
            Rank += get(a[i]-1) * gt[n-i];
            Rank %= mod;
            update(a[i],-1);
            //cout << Rank << endl;
        }
        swap(a[u],a[v]);
        printf("%lld\n",Rank);
    }
}

int main()
{
    freopen("ASISTENT.inp","r",stdin);
    freopen("ASISTENT.out","w",stdout);
    scanf("%d%d",&n,&k);
    For(i,1,n) scanf("%d",&a[i]);
    if(k <= 10) Sub1();
}
