#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n,m;
ll c[maxn],d[maxn],g[maxn];

vector<pair<int,ll> > a[maxn];

void dijkstra()
{
    For(i,1,n) d[i] = INF;
    d[1] = 0;
    g[1] = c[1];
    priority_queue<pair<pair<ll,ll>,int> > pq;
    pq.push({{0,g[1]},1});
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cur_d = -pq.top().fi.fi;
        ll cur_g = pq.top().fi.se;
        pq.pop();
        if(cur_d > d[u] || cur_g < g[u]) continue;
        for(int i = 0;i < a[u].size();i++)
        {
            int v = a[u][i].fi; ll w = a[u][i].se;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                g[v] = g[u] + c[v];
                pq.push({{-d[v],g[v]},v});
            }
            else if(d[u] + w == d[v] && g[u] + c[v] > g[v])
            {
                g[v] = g[u] + c[v];
                pq.push({{-d[v],g[v]},v});
            }
        }
    }
}

int main()
{
    fast_read;
    freopen("PHD.inp","r",stdin);
    freopen("PHD.out","w",stdout);
    cin >> n ;
    For(i,1,n) cin >> c[i];
    cin >> m;
    For(i,1,m)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    dijkstra();
    if(d[n] == INF) cout << "impossible\n";
    else cout << d[n] << ' ' << g[n] << endl;
}
