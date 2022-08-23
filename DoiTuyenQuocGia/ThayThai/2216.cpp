#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define INF 1e18
using namespace std;

int m,n,q;
ll a[2*maxn][2*maxn],sum[2*maxn][2*maxn];

void copyto(int i,int j,int u,int v)
{
    For(p,1,m)
        For(q,1,n)
            a[i+p-1][u+q-1] = a[p][q];
}

ll getsum(int i,int j,int u,int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

int main()
{
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
    cin >> m >> n;
    For(i,1,m)
        For(j,1,n)
            cin >> a[i][j];
    copyto(m+1,2*m,1,n);
    copyto(1,m,n+1,2*n);
    copyto(m+1,2*m,n+1,2*n);
    int curx = 0,cury = 0;
    For(i,1,2*m)
        For(j,1,2*n)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
    cin >> q;
    while(q--)
    {
        int type,x,y,u,v,s,t;
        scanf("%d",&type);
        if(type == 0)
        {
            scanf("%d%d",&x,&y);
            curx = (curx + y)%m;
            cury = (cury + x)%n;
        }
        else
        {
            scanf("%d%d%d%d",&u,&v,&s,&t);
            printf("%lld\n",getsum(u+curx,v+cury,s+curx,t+cury));
        }
    }
}
