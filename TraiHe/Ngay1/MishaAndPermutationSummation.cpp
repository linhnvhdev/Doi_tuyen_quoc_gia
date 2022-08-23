#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >=b;i--)
#define maxn 100005
#define ll long long
using namespace std;

int n,q;
int a[5005][5005],sum[5005][5005];

ll Get(int i,int j,int u,int v)
{
    //if(u < i || j < v) return 0;
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

ll Rnum(int t)
{
    return 1ll*t*(t-1)/2;
}

int main()
{
    scanf("%d%d",&n,&q);
    For(i,1,n){
        int x;
        scanf("%d",&x);
        a[i][x]++;
    }
    For(i,1,n)
        For(j,1,n) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + a[i][j];
    ll S = 1ll*n*(n-1)/2;
    For(i,1,q){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        ll t1 = Get(1,1,x1-1,n);
        ll t2 = Get(1,1,n,y1-1);
        ll t3 = Get(x2+1,1,n,n);
        ll t4 = Get(1,y2+1,n,n);
        ll t5 = Get(1,1,x1-1,y1-1);
        ll t6 = Get(1,y2+1,x1-1,n);
        ll t7 = Get(x2+1,1,n,y1-1);
        ll t8 = Get(x2+1,y2+1,n,n);
        ll ans = Rnum(t1) + Rnum(t2) + Rnum(t3) + Rnum(t4) - Rnum(t5) - Rnum(t6) - Rnum(t7) - Rnum(t8);
        cout << S - ans << endl;
    }
}
