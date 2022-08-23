#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define ll long long
#define maxN 105
const int INF = 1e9 ;

struct edge {
    int to, cap , cost , flow , rev;
};
int n,m, k, s, t , d[maxN] , pv [maxN] ,pe[maxN];
vector <edge> g[maxN];
void add_edge(int u, int v, int c ,int w) {
    edge e1 = {v , c , w , 0, (int) g[v].size()} ;
    edge e2 = {u , 0 , -w , 0, (int) g[u].size()} ;
    g[u].push_back(e1);
    g[v].push_back(e2);
}
void shortest_path(int s) {
    int M[maxN];
    FOR(i,1,n) {
        d[i] = INF; pv[i] = s; M[i] = 2;
    }
    d[s] = 0 ;
    deque<int>  q;
    q.push_back(s);
    while(!q.empty()) {
        int u= q.front();
        q.pop_front();
        M[u] = 0;
        for( int i = 0; i < g[u].size() ;i++) {
            int v = g[u][i].to, c=g[u][i].cap , w = g[u][i].cost  , f = g[u][i].flow;
            if(c > f && d[v] > d[u] + w) {
                d[v] = d[u] + w;
                pv[v] = u;
                pe[v] = i;
                if( M[v] == 2) q.push_back(v);
                else
                    if(M[v] == 0) q.push_back(v);
                M[v] = 1;
            }
        }
    }
}
ll min_flow(int s,int t) {
    ll total_flow = 0, total_cost = 0 ;
    while (total_flow < k ) {
          //  cout<< " RUn " <<endl;
        shortest_path(s);
        if(d[t] == INF ) return -1;
        int path_cap = k - total_flow;
        for(int v = t; v != s; v = pv[v]){
            int u = pv[v], i = pe[v];
            path_cap = min (path_cap,g[u][i].cap - g[u][i].flow);
        }
        for(int v = t ; v!= s; v = pv[v]) {
            int u = pv[v]   , i = pe[v] , r = g[u][i].rev;
            g[u][i].flow += path_cap;
            g[v][r].flow -= path_cap;
        }
        total_flow += path_cap;
        total_cost += 1ll*path_cap*d[t];
    }
   // cout<< " toa " <<total_cost <<endl;
    return total_cost;
}
int main () {
    cin>>n>>m>>k>>s>>t;
    FOR(i,1,m) {
        int u,v,c,w;
        scanf("%d%d%d%d",&u,&v,&c,&w);
        add_edge(u,v,c,w);
        add_edge(v,u,c,w);
    }
    cout<<min_flow(s,t)<<'\n';
}
