/*
    dijkstra
    Xét 1 con đường sắt 1 -> s[i]
        Con đường sắt bị đóng <=> Tồn tại đỉnh u kề với s[i] sao cho d[s[i]] = d[u] + w(u,s[i])
*/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 200005
#define INF 1e18
using namespace std;

int n,m,k;
ll d[maxn],d2[maxn],ds[maxn];
vector<pair<int,ll> > b[maxn];
bool used[maxn];
pair<pair<int,int>,ll> edge[2*maxn];

void dijkstra(int start)
{
    For(i,1,n) d[i] = INF;
    d[1] = 0;
    priority_queue<pair<ll,int> > pq;
    pq.push({0,1});
    while(!pq.empty()){
        int u = pq.top().se;
        ll cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > d[u]) continue;
        for(int i = 0;i < b[u].size();i++){
            int v = b[u][i].fi;
            ll w = b[u][i].se;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                pq.push({-d[v],v});
            }
        }
    }
}

int main()
{
    //freopen("1624.inp","r",stdin);
    //freopen("1624.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    For(i,1,m){
        int u,v,x;
        scanf("%d%d%d",&u,&v,&x);
        b[u].push_back({v,x});
        b[v].push_back({u,x});
        edge[i] = {{u,v},x};
    }
    For(i,1,n) ds[i] = INF;
    int cnt = 0;
    For(i,1,k){
        int s,y;
        scanf("%d%d",&s,&y);
        b[1].push_back({s,y});
        b[s].push_back({1,y});
        ds[s] = min(ds[s],1ll*y);
        if(used[s]) cnt++;
        used[s] = true;
    }
    dijkstra(1);
    int ans = k;
    For(i,1,m){
        int u = edge[i].fi.fi,v = edge[i].fi.se;
        ll w = edge[i].se;
        if(d[u] + w == d[v])
            used[v] = false;
        if(d[v] + w == d[u])
            used[u] = false;
    }
    For(i,1,n) if(ds[i] != INF && !used[i]) cnt++;
    cout << cnt << endl;
}
