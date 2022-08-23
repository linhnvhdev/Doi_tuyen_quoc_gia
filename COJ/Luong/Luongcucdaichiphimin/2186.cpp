#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 105
#define INF 1e9
#define ll long long
using namespace std;

int n,m,k,S,T,d[maxn],pe[maxn],pv[maxn];

struct edge{
    int to,cap,cost,flow,rev;
};

vector<edge> g[maxn];

void AddEdge(int u,int v,int c,int w)
{
    edge eu = {v,c,w,0,(int) g[v].size()};
    edge ev = {u,0,-w,0,(int) g[u].size()};
    g[u].push_back(eu);
    g[v].push_back(ev);
}

void ShortestPath(int s,int t)
{
    int M[maxn];
    For(i,1,n){
        M[i] = 2;
        d[i] = INF;
        pv[i] = s;
    }
    d[s] = 0;
    deque<int> dq;
    dq.push_back(s);
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        M[u] = 0;
        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i].to,c = g[u][i].cap,w = g[u][i].cost,f = g[u][i].flow;
            if(c > f && d[u] + w < d[v]){
                d[v] = d[u] + w;
                pv[v] = u;
                pe[v] = i;
                if(M[v] == 2) dq.push_back(v);
                else if(M[v] == 0) dq.push_front(v);
                M[v] = 1;
            }
        }
    }
}

ll MinCostFlow(int s,int t)
{
    ll total_flow = 0,total_cost = 0;
    while(total_flow < k){
        ShortestPath(s,t);
        if(d[t] == INF) return -1;
        int path_cap = k - total_flow;
        for(int v = t;v != s;v = pv[v]){
            int u = pv[v],i = pe[v];
            path_cap = min(path_cap,g[u][i].cap - g[u][i].flow);
        }

        for(int v = t;v != s;v = pv[v]){
            int u = pv[v],i = pe[v],r = g[u][i].rev;
            g[u][i].flow += path_cap;
            g[v][r].flow -= path_cap;
        }

        total_flow += path_cap;
        total_cost += 1ll*path_cap*d[t];
    }
    return total_cost;
}

int main()
{
    scanf("%d%d%d%d%d",&n,&m,&k,&S,&T);
    For(i,1,m){
        int u,v,c,w;
        scanf("%d%d%d%d",&u,&v,&c,&w);
        AddEdge(u,v,c,w);
        AddEdge(v,u,c,w);
    }
    printf("%lld\n",MinCostFlow(S,T));
}
