#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 5005
#define ll long long
#define INF 1e9
using namespace std;

int m,n;
ll a[maxn],b[maxn];
int f[maxn][maxn],g[maxn][maxn],ans[maxn];

int main()
{
    fast_read;
    freopen("LCIS.inp","r",stdin);
    freopen("LCIS.out","w",stdout);
    cin >> m >> n;
    For(i,1,m) cin >> a[i];
    For(i,1,n) cin >> b[i];
    b[n+1] = INF+1;
    For(i,1,m)
    {
        int k = a[i];
        int v = 0;
        For(j,1,n+1)
        {
            f[i][j] = f[i-1][j];
            if(b[j] > k && v > 0)
                f[i][j] = max(f[i][j],f[i-1][v] + 1);
            if(b[j] == k) v = j;
        }
    }
    cout << f[m][n+1] << endl;
    int i = m,j = n+1,cnt = 0;
    while(i > 0)
    {
        if(f[i][j] == f[i-1][j]) i--;
        else
        {
            Forr(k,j,1)
            {
                if(b[k] == a[i] && f[i][j] == f[i-1][k] + 1)
                {
                    ans[++cnt] = a[i];
                    i--;
                    j = k;
                    break;
                }
            }
        }
    }
    Forr(i,f[m][n+1],1) cout << ans[i] << ' ';
}
