#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 55
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

const int mod = 2017;

int m,n,k;
ll ans = 0;

vector<int> a[maxn];
ll f[maxn][1005];

int main()
{
    fast_read;
    freopen("CPATH.inp","r",stdin);
    freopen("CPATH.out","w",stdout);
    cin >> n >> m >> k;
    For(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    f[1][0] = 1;
    For(i,1,k)
        For(u,1,n)
            for(int v : a[u])
                f[v][i] = (f[v][i] + f[u][i-1])%mod;
    cout << f[n][k] << endl;
}
