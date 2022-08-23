#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxN 100005
#define pii pair<long long,int>
#define fi first
#define se second
#define ll long long
using namespace std;
int n, m, q, cnt = 0, s, t, k, id = 0, pv[maxN], pe[maxN], M[maxN];
ll d[maxN], Find[maxN];
pii p[maxN];
struct Road{
    int x, y;
    ll val;
}road[maxN];
struct edge{
    int to;
    ll cap, cost, flow;
    int rev;
};
vector<edge>g[maxN];
bool cmp(pii u, pii v){
    return u.fi > v.fi;
}
void Add_edge(int u, int v, ll c, ll val){
    edge e1 = {v, c, val, 0, (int)g[v].size()};
    edge e2 = {u, 0, -val, 0, (int)g[u].size()};
    g[u].push_back(e1);
    g[v].push_back(e2);
}
void shortest_paths(int s){
    For(i,1,n){
        d[i] = 1e15;
        pv[i] = s;
        M[i] = 2;
    }
    d[s] = 0;
    deque<int>dq;
    dq.push_back(s);
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        M[u] = 0;
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i].to;
            ll c = g[u][i].cap, f = g[u][i].flow, w = g[u][i].cost;
            if(c > f && d[u] + w < d[v]){
                d[v] = d[u] + w;
                pv[v] = u;
                pe[v] = i;
                if(M[v] == 2)dq.push_back(v);
                else
                    if(M[v] == 0)dq.push_front(v);
                M[v] = 1;
            }
        }
    }
}
int min_cost(int s, int t)
{
    ll total_flow = 0, total_cost = 0;
    while(total_flow < k){
        shortest_paths(s);
        if(d[t] == 1e15)return 0;
        ll path_cap = 1ll * k - total_flow;
        for(int v = t; v != s; v = pv[v]){
            int u = pv[v], i = pe[v];
            path_cap = min(path_cap, g[u][i].cap - g[u][i].flow);
        }
        for(int v = t; v != s; v = pv[v]){
            int u = pv[v], i = pe[v], r = g[u][i].rev;
            g[u][i].flow += path_cap;
            g[u][r].flow -= path_cap;
        }
        total_flow += path_cap;
        total_cost += path_cap * d[t];
    }
    return total_cost;
}
int main()
{
    freopen("2159.inp", "r", stdin);
    freopen("2159.out", "w", stdout);
    scanf("%d%d", &n, &m);
    For(i,1,m){
        scanf("%d%d%d", &road[i].x, &road[i].y, &road[i].val);
        p[++cnt] = {road[i].val, i};
    }
    sort(p + 1, p + 1 + cnt, cmp);
    p[0].fi = 0;
    For(i,1,cnt){
        if(p[i].fi != p[i - 1].fi)Find[++id] = p[i].fi;
        road[p[i].se].val = id;
    }
    scanf("%d", &q);
    while(q--){
        scanf("%d%d%d", &s, &t, &k);
        For(i,1,n)g[i].clear();
        For(i,1,m){
            int u = road[i].x, v = road[i].y;
            ll w = road[i].val;
            Add_edge(u, v, w, 0);Add_edge(v, u, w, 0);
            Add_edge(u, v, 1e9, 1);Add_edge(v, u, 1e9, 1);
        }
        printf("%d\n", min_cost(s, t));
    }
}
