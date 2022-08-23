/// Code nay duoc sinh ra chi de quay xo so :)
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 100005
#define ll long long
#define INF 1e18
using namespace std;

int n,m;
ll p[maxn],d[maxn];
ll f[maxn];

vector<pair<int,ll> > a[maxn];

void dijkstra()
{
    For(i,1,n) d[i] = INF;
    For(i,1,n) f[i] = -INF;
    f[1] = p[1];
    d[1] = 0;
    priority_queue<pair<ll,int> > pq;
    pq.push({0,1});
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > d[u]) continue;
        for(int i = 0;i < a[u].size();i++)
        {
            int v = a[u][i].fi;
            ll w = a[u][i].se;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                f[v] = f[u] + p[v];
                pq.push({-d[v],v});
            }
            else if(d[u] + w == d[v])
                    f[v] = max(f[v],f[u] + p[v]);
        }
    }
}

int main()
{
    fast_read;
    freopen("quanho.inp","r",stdin);
    freopen("quanho.out","w",stdout);
    cin >> n ;
    For(i,1,n) cin >> p[i];
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
    else cout << d[n] << ' ' << f[n] << endl;
}
