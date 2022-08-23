#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define maxn 1005
#define ll long long
using namespace std;

int m,n,q;
ll a[maxn][maxn],bit[maxn][maxn],add[maxn][maxn];
ll diffr[maxn][maxn];
ll diffc[maxn][maxn];

void update(int posx,int posy,ll val)
{
    for(int i = posx;i <= m;i += (i&(-i)))
        for(int j = posy;j <= n;j += (j&(-j)))
            bit[i][j] += val;
}

ll get(int posx,int posy)
{
    ll tmp = 0;
    for(int i = posx;i > 0; i -= (i&(-i)))
        for(int j = posy;j > 0; j -= (j&(-j)))
            tmp += bit[i][j];
    return tmp;
}

bool check(ll val)
{
    int maxr = n;
    For(i,1,m)
    {
        ll dau = a[i][1] + get(i,1);
        ll cuoi = a[i][n] + get(i,n);
        if(dau > val) return false;
        if(cuoi < val) continue;
        int l = 1,r = maxr;
        while(r - l > 1)
        {
            int mid = (l+r)/2;
            if(a[i][mid] + get(i,mid) <= val) l = mid;
            else r = mid;
        }
        ll t1 = a[i][r] + get(i,r);
        ll t2 = a[i][l] + get(i,l);
        if(t1 == val || t2 == val) return true;
        maxr = (t1 > val) ? l : r;
    }
    return false;
}

int main()
{
    freopen("MATRIXSEARCH.inp","r",stdin);
    freopen("MATRIXSEARCH.out","w",stdout);
    scanf("%d%d",&m,&n);
    For(i,1,m)
        For(j,1,n) scanf("%lld",&a[i][j]);
    scanf("%d",&q);
    For(i,1,m-1)
        For(j,1,n)
            diffr[i][j] = a[i+1][j] - a[i][j];
    For(i,1,m)
        For(j,1,n-1)
            diffc[i][j] = a[i][j+1] - a[i][j];
    while(q--)
    {
        int type;
        scanf("%d",&type);
        if(type == 2)
        {
            int u,v;
            ll val;
            scanf("%d%d%lld",&u,&v,&val);
            update(u,v,val);
        }
        else
        {
            ll val;
            scanf("%lld",&val);
            if(check(val)) printf("Y\n");
            else printf("N\n");
        }
    }
}
