#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 15
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n,M;
ll a[maxn];

ll f[maxn][10005];

int main()
{
    fast_read;
    freopen("TILECHNG.inp","r",stdin);
    freopen("TILECHNG.out","w",stdout);
    cin >> n >> M;
    For(i,1,n) cin >> a[i];
    For(i,0,n)
        For(j,0,M) f[i][j] = INF;
    f[0][0] = 0;
    For(i,1,n)
    {
        For(j,0,M)
        {
            For(k,1,100)
                if(j >= k*k) f[i][j] = min(f[i][j],f[i-1][j-k*k] + 1ll*(a[i] - k)*(a[i] - k));
            //cout << i << ' ' << j << ' ' << f[i][j] << '\n';
        }
    }
    if(f[n][M] != INF) cout << f[n][M] << endl;
    else cout << -1 << endl;
}
