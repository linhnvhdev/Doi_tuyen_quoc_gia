#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 125
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

int m,n,k;
ll p;

ll s[maxn],r[maxn],t[maxn];
ll f[maxn],d[maxn];

bool Notok[maxn][maxn];

int main()
{
    fast_read;
    freopen("BUDGET2.inp","r",stdin);
    freopen("BUDGET2.out","w",stdout);
    cin >> m >> n >> p;
    For(i,1,m) cin >> s[i];
    sort(s+1,s+1+m);
    For(i,1,m) t[i] = ceil(1.0*p/s[i]);
    For(i,1,n) cin >> r[i];
    sort(r+1,r+1+n);
    cin >> k;
    For(i,1,k)
    {
        int u,v;
        cin >> u >> v;
        Notok[u][v] = true;
    }
    For(i,1,m) f[i] = -INF;
    Forr(i,n,1)
    {
        pair<ll,int> best = {INF,0};
        Forr(j,m,1)
        {
            ///if(Notok[j][i]) continue;
            ll Day = max(f[j],r[i] + (d[j]+1)*t[j] - 1);
            if(Day < best.fi) best = {Day,j};
        }
        d[best.se]++;
        f[best.se] = max(f[best.se],r[i] + d[best.se]*t[best.se] - 1);
    }
    ll ans = 0;
    For(i,1,m) ans = max(ans,f[i]);
    cout << ans << endl;
}
