#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 505
#define INF 1e9
#define ll long long
using namespace std;

struct edge{
    int to,cap,cost,flow,rev;
};

int n,m,num[maxn],d[maxn],pv[maxn],pe[maxn];

vector<edge> g[maxn];

void AddEdge(int u,int v,int c,int w)
{
    edge eu = {v,c,w,0,(int) g[v].size()};
    edge ev = {u,0,-w,0,(int) g[u].size()};
    g[u].push_back(eu);
    g[v].push_back(ev);
}

bool ShortestPath(int s,int t)
{
    int M[maxn];
    For(i,0,n+1){
        M[i] = 2; d[i] = INF; pv[i] = s;
    }
    d[s] = 0;
    int dq[1000],fr = 500,bk = 499;
    dq[++bk] = s;
    while(fr <= bk){
        int u = dq[fr++];
        //cerr << fr << ' ' << bk << ' ' << u << endl;
        M[u] = 0;
        int Size = g[u].size();
        for(int i = 0;i < Size;i++){
            int v = g[u][i].to,c = g[u][i].cap,f = g[u][i].flow,w = g[u][i].cost;
            if(c > f && d[u] + w < d[v]){
                d[v] = d[u] + w;
                pv[v] = u;
                pe[v] = i;
                if(M[v] == 2) dq[++bk] = v;
                else if(M[v] == 0) dq[--fr] = v;
                M[v] = 1;
            }
        }
    }
    /*deque<int> dq;
    dq.push_back(s);
    while(!dq.empty()){
        int u = dq.front();
        dq.pop_front();
        M[u] = 0;
        for(int i = 0;i < g[u].size();i++){
            int v = g[u][i].to,c = g[u][i].cap,f = g[u][i].flow,w = g[u][i].cost;
            if(c > f && d[u] + w < d[v]){
                d[v] = d[u] + w;
                pv[v] = u;
                pe[v] = i;
                if(M[v] == 2) dq.push_back(v);
                else if(M[v] == 0) dq.push_back(v);
                M[v] = 1;
            }
        }
    }*/
    return (d[t] != INF);
}

int min_cost_flow(int s,int t)
{
    int total_flow = 0, total_cost = 0;
    while(total_flow < n){
        //cout << ":)\n";
        if(!ShortestPath(s,t)) return -1;
        int path_cap = n - total_flow;
        //cout << d[t] << endl;
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
        total_cost += d[t]*path_cap;
    }
    return total_cost;
}

int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n){
        int x;
        scanf("%d",&x);
        num[x]++;
    }
    scanf("%d",&m);
    For(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        AddEdge(u,v,INF,1);
        AddEdge(v,u,INF,1);
    }
    For(i,1,n){
        if(num[i]) AddEdge(0,i,num[i],0);
        AddEdge(i,n+1,1,0);
    }
    cout << min_cost_flow(0,n+1) << endl;
}
