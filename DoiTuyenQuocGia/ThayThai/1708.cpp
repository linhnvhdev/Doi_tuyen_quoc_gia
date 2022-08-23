#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 305
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,k;
ll d[maxn][maxn],tong = 0,ans = 0,tmpd[maxn][maxn];

void Solve(int a,int b,int c)
{
    For(i,1,n)
        For(j,1,n) tmpd[i][j] = d[i][j];
    For(i,1,n)
        For(j,i+1,n){
            if(d[i][a] + c + d[b][j] <= d[i][j]){
                ans += d[i][a] + c + d[b][j] - d[i][j];
                tmpd[i][j] = tmpd[j][i] = min(tmpd[i][j],d[i][a] + c + d[b][j]);
            }
            else if(d[i][b] + c + d[a][j] <= d[i][j]){
                ans += d[i][b] + c + d[a][j] - d[i][j];
                tmpd[i][j] = tmpd[j][i] = min(tmpd[i][j],d[i][b] + c + d[a][j]);
            }
        }
    For(i,1,n)
        For(j,i+1,n)
            d[i][j] = d[j][i] = tmpd[i][j];
}

int main()
{
    scanf("%d",&n);
    For(u,1,n){
        int v,w;
        For(v,1,n){
            scanf("%d",&w);
            d[u][v] = d[v][u] = w;
            if(u < v) ans += w;
        }
    }
    //cout << ans << endl;
    scanf("%d",&k);
    For(i,1,k){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        Solve(u,v,w);
        printf("%lld",ans);
        if(i < k) printf(" ");
    }
}
/**
10
0 1 2 3 3 5 10 8 6 7
1 0 3 4 2 6 11 9 5 6
2 3 0 4 5 6 11 9 8 9
3 4 4 0 3 2 7 5 9 10
3 2 5 3 0 5 10 8 7 8
5 6 6 2 5 0 5 3 11 12
10 11 11 7 10 5 0 8 16 17
8 9 9 5 8 3 8 0 14 15
6 5 8 9 7 11 16 14 0 11
7 6 9 10 8 12 17 15 11 0
3
1 9 4
5 6 1
3 6 3
**/
