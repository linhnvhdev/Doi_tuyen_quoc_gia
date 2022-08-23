#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n;
ll d[maxn], c[maxn];

vector<pair<int,ll> > a[maxn];

void dijkstra(int s)
{
    For(i,1,n) d[i] = -1e9;
    d[s] = c[s];
    priority_queue<pair<ll,pair<int,int> > > pq;
    pq.push({d[1],{s,0}});
    while(!pq.empty()){
        int u = pq.top().se.fi;
        int p = pq.top().se.se;
        ll cur_d = pq.top().fi;
        //cerr << u << ' ' << cur_d << endl;
        pq.pop();
        if(cur_d < d[u]) continue;
        for(int i = 0;i < a[u].size();i++){
            int v = a[u][i].fi; ll w = a[u][i].se;
            if(v == p) continue;
            if(d[u] + w > d[v]){
                d[v] = d[u] + w;
                pq.push({d[v],{v,u}});
            }
        }
    }
}

int main()
{
    freopen("Summax1.inp","r",stdin);
    freopen("Summax1.out","w",stdout);
    cin >> n;
    For(i,1,n) cin >> c[i];
    For(i,1,n){
        int p;
        cin >> p;
        if(p == 0) continue;
        a[i].push_back({p,c[p]});
        a[p].push_back({i,c[i]});
    }
    dijkstra(1);
    ll ans = -INF;
    For(i,1,n) ans = max(ans,d[i]);
    cout << ans << endl;
}
