/// https://codeforces.com/gym/102192/problem/G
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define INF 1e18
using namespace std;

int n,m,q,st[maxn],ed[maxn],p[maxn],h[maxn];
int P[maxn][25],cnt = 0;
ll D[maxn],d[maxn];

struct edge{
    int u,v;
    ll w;
    bool operator < (const edge &other) const{
        return w < other.w;
    }
} e[maxn];

void make_set(int i){p[i] = i; h[i] = 0;}

int Find(int i){while(i != p[i]) i = p[i]; return i;}

bool Union(int u,int v){
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    if(h[x] < h[y]) p[x] = y;
    else
    {
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

vector<edge> out;
vector<pair<int,ll> > a[maxn],adj[maxn];
vector<ll> mind[maxn];

void dfs(int u,int parent){
    st[u] = ++cnt;
    For(i,1,19) P[u][i] = P[P[u][i-1]][i-1];
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        if(v == parent) continue;
        d[v] = d[u] + w;
        P[v][0] = u;
        dfs(v,u);
    }
    ed[u] = cnt;
}

bool chklca(int u,int v){
    return st[u] <= st[v] && ed[u] >= ed[v];
}

int lca(int u,int v){
    if(chklca(u,v)) return u;
    Forr(i,19,0) if(P[u][i] && !chklca(P[u][i],v)) u = P[u][i];
    return P[u][0];
}

ll Dist(int u,int v){
    return d[u] + d[v] - 2*d[lca(u,v)];
}

void dijkstra(int start)
{
    if(mind[start].size() != 0) return;
    For(i,1,n) D[i] = INF;
    D[start] = 0;
    priority_queue<pair<ll,int> > pq;
    pq.push({0,start});
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > D[u]) continue;
        for(int i = 0;i < adj[u].size();i++)
        {
            int v = adj[u][i].fi;
            ll w = adj[u][i].se;
            if(D[u] + w < D[v])
            {
                D[v] = D[u] + w;
                pq.push({-D[v],v});
            }
        }
    }
    mind[start].push_back(0);
    For(i,1,n)
        mind[start].push_back(D[i]);
}

int main()
{
    fast_read;
    cin >> n >> m;
    For(i,1,m)
    {
        cin >> e[i].u >> e[i].v >> e[i].w;
        adj[e[i].u].push_back({e[i].v,e[i].w});
        adj[e[i].v].push_back({e[i].u,e[i].w});
    }
    sort(e+1,e+1+m);
    For(i,1,n) make_set(i);
    For(i,1,m)
    {
        if(Union(e[i].u,e[i].v))
       {
            a[e[i].u].push_back({e[i].v,e[i].w});
            a[e[i].v].push_back({e[i].u,e[i].w});
       }
       else out.push_back(e[i]);
    }
    dfs(1,0);
    for(edge t : out)
        dijkstra(t.u), dijkstra(t.v);
    cin >> q;
    For(i,1,q)
    {
        int u,v;
        cin >> u >> v;
        ll ans = Dist(u,v);
        for(edge t : out)
        {
            ans = min(ans,mind[t.u][u] + t.w + mind[t.v][v]);
            ans = min(ans,mind[t.u][v] + t.w + mind[t.v][u]);
        }
        cout << ans << endl;
    }
}
