#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 500005
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define pii pair<int,int>
using namespace std;

int n;
ll v[maxn],w[maxn],r[maxn][5];

ll f[100005][5],g[100005][5];

ll sumv[maxn],sumw[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SUM.inp","r",stdin);
    freopen("SUM.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> v[i] >> w[i];
        sumv[i] = sumv[i-1] + v[i];
        sumw[i] = sumw[i-1] + w[i];
    }
    For(i,1,n)
        For(j,v[i],w[i]) r[i][j%5]++;
    For(i,v[1],w[1])
        f[1][i%5]++;
    For(i,2,n)
    {
        For(j,0,4)
        {
            For(k,0,4)
            {
                int pre = (j - k + 5)%5;
                f[i][j] += f[i-1][pre]*r[i][k];
            }
        }
    }
    ll ans = 0;
    For(i,0,4)
    {
        ll t = ((i*i+1)*(i*i+1) - 1 + 5)%5 + 1;
        ans += t*f[n][i];
    }
    cout << ans << endl;
}
