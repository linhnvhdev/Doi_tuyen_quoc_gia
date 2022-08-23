#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define fi first
#define se second
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,m,X;

ll h[maxn],d[maxn],dh[maxn];

vector<pair<int,ll> > a[maxn];

//typedef mottickssr pair<pair<ll,ll>,int>;

void dijkstra(int st,int ed)
{
    For(i,1,n) d[i] = INF;
    d[st] = 0;
    `priority_queue<pair<pair<ll,ll>,int> > pq;
    ///priority_queue<mottickssr, vector<mottickssr>, greater<ahihi> > pq;
    pq.push({{-d[st],X},st});
    while(!pq.empty())
    {
        ll cur_d = -pq.top().fi.fi;
        ll cur_h = pq.top().fi.se;
        int u = pq.top().se;
        pq.pop();
        if(cur_d > d[u]) continue;
        Forv(i,a[u])
        {
            int v = a[u][i].fi;
            ll w = a[u][i].se;
            ll new_h = cur_h - w;
            ll add = w;
            if(new_h < 0)
            {
                if(cur_h - new_h > h[u]) continue;
                else add -= new_h;
                new_h = 0;
            }
            if(new_h > h[v])
            {
                add += cur_h - h[v] - w;
                new_h = h[v];
            }
            if(v == n)
            {
                add += h[n] - new_h;
                new_h = h[n];
            }
            if(d[u] + add < d[v])
            {
                d[v] = d[u] + add;
                pq.push({{-d[v],new_h},v});
            }
        }
    }
}

int main()
{
    freopen("ROBOT.inp","r",stdin);
    freopen("ROBOT.out","w",stdout);
    scanf("%d%d%d",&n,&m,&X);
    For(i,1,n)
    {
        scanf("%d",&h[i]);
    }
    For(i,1,m)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    dijkstra(1,n);
    if(d[n] != INF) cout << d[n] << endl;
    else cout << -1 << endl;
}
