#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define maxn 1005
#define ll long long
using namespace std;

int m,n,q;
ll a[maxn][maxn],bit[maxn][maxn],add[maxn][maxn];
ll diffr[maxn][maxn], diffc[maxn][maxn];

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
            if(u == 1) For(i,v,n) a[1][i] += val;
            else For(i,v,n) diffr[u-1][i] += val;
            if(v == 1) For(i,u,m) a[i][1] += val;
            else For(i,u,m) diffc[i][v-1] += val;
        }
        else
        {
            ll val;
            scanf("%lld",&val);
            int curx = 1,cury = n;
            ll cur = a[1][n];
            while(curx <= m && cury >= 1)
            {
                if(cur == val) break;
                if(cur < val)
                {
                    cur = cur + diffr[curx][cury];
                    curx++;
                }
                else
                {
                    cur = cur - diffc[curx][cury-1];
                    cury--;
                }
            }
            if(cur == val) printf("Y\n");
            else printf("N\n");
        }
    }
}
