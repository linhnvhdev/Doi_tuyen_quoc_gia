#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define ll long long
#define INF 1e9
#define fi first
#define se second
using namespace std;

int n;
ll c[maxn],k[maxn],val[maxn],a[maxn][maxn];
int parent[maxn];
pair<ll,ll> p[maxn];


bool used[maxn];

ll dist(int i,int j)
{
    return (k[i] + k[j])*(abs(p[i].fi - p[j].fi) + abs(p[i].se - p[j].se));
}


int Find()
{
    int v = -1;
    For(i,1,n)
        if(!used[i] && (v == -1 || val[i] < val[v])) v = i;
    return v;
}

int main()
{
    scanf("%d",&n);
    For(i,1,n) scanf("%lld%lld",&p[i].fi,&p[i].se);
    For(i,1,n) scanf("%lld",&c[i]);
    For(i,1,n) scanf("%lld",&k[i]);

    ll ans = 0;
    For(i,1,n)
        a[0][i] = c[i];
    For(i,1,n)
        For(j,1,n)
            a[i][j] = dist(i,j);
    For(i,1,n) val[i] = a[0][i];
    used[0] = true;
    parent[0] = -1;
    For(N,1,n)
    {
        int u = Find();
        if(u == -1) break;
        used[u] = true;
        ans += val[u];
        For(v,1,n)
            if(!used[v] && a[u][v] < val[v])
            {
                parent[v] = u;
                val[v] = a[u][v];
            }
    }
    vector<int> power;
    vector<pair<int,int> > edge;
    For(i,1,n)
        if(parent[i] == 0) power.push_back(i);
        else edge.push_back({min(i,parent[i]),max(i,parent[i])});
    cout << ans << endl;
    cout << power.size() << endl;
    for(int u : power) cout << u << ' ';
    cout << endl;
    cout << edge.size() << endl;
    for(pair<int,int> e : edge) cout << e.fi << ' ' << e.se << '\n';
}
