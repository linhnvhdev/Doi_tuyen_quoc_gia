#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1005
#define ll long long
using namespace std;

int m,n,p,q,B;
int b[maxn][maxn],c[maxn][maxn];

int get(int sum[maxn][maxn],int i,int j,int u,int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("RESORT.inp","r",stdin);
    freopen("RESORT.out","w",stdout);
    cin >> m >> n >> p >> q >> B;
    For(i,1,m)
        For(j,1,n)
        {
            int a;
            cin >> a;
            b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + (a < B);
            c[i][j] = c[i-1][j] + c[i][j-1] - c[i-1][j-1] + (a == B);
        }
    int middle = (p*q+1)/2;
    int ans = 0;
    For(i,1,m - p + 1)
        For(j,1,n - q + 1)
        {
            int u = i + p -1;
            int v = j + q - 1;
            int t1 = get(b,i,j,u,v);
            int t2 = get(c,i,j,u,v);
            if(t1 < middle && t1 + t2 >= middle)
                ans++;
        }
    cout << ans << endl;
}
