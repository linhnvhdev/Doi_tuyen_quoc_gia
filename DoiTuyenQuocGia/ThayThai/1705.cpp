#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,m;
double w,d[maxn];

pair<int,int> p[maxn];

double len(int x,int y,int u,int v)
{
    return sqrt(1.0*(x-u)*(x-u) + 1.0*(y-v)*(y-v));
}

double c[maxn][maxn];

vector<pair<int,double> > a[maxn];

void dijkstra(int s)
{
    For(i,1,n) d[i] = 1e15;
    d[s] = 0;
    priority_queue<pair<double,int> > pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u = pq.top().se;
        double cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > d[u]) continue;
        for(int i = 0;i < a[u].size();i++){
            int v = a[u][i].fi; double W = a[u][i].se;
            if(d[u] + W < d[v]){
                d[v] = d[u] + W;
                pq.push({-d[v],v});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    cin >> w;
    For(i,1,n)
        scanf("%d%d",&p[i].fi,&p[i].se);
    For(i,1,n)
        For(j,i+1,n){
            double W = len(p[i].fi,p[i].se,p[j].fi,p[j].se);
            if(W <= w) c[i][j] = c[j][i] = W;
        }
    For(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        c[u][v] = c[v][u] = 0;
        a[u].push_back({v,0});
        a[v].push_back({u,0});
    }
    For(u,1,n)
        For(v,u+1,n){
            if(c[u][v] != 0){
                a[u].push_back({v,c[u][v]});
                a[v].push_back({u,c[u][v]});
            }
        }
    dijkstra(n);
    if(d[1] == 1e15) cout << -1 << endl;
    else cout << (ll) (d[1]*1000) << endl;
}
