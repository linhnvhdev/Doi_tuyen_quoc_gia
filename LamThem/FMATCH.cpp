#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 50005
#define INF 1e9
using namespace std;

int n,m,p,q = 0;
int pairU[maxn],pairV[maxn],dist[maxn];
vector<int> a[maxn];

bool bfs()
{
    queue<int> q;
    For(u,1,n)
        if(pairU[u] == 0)
        {
            dist[u] = 0;
            q.push(u);
        }
        else dist[u] = INF;
    dist[0] = INF;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        if(dist[u] >= dist[0]) continue;
        Forv(i,a[u])
        {
            int v = a[u][i];
            if(dist[pairV[v]] == INF)
            {
                dist[pairV[v]]  = dist[u] + 1;
                q.push(pairV[v]);
            }
        }
    }
    return (dist[0] != INF);
}

bool dfs(int u)
{
    if(u == 0) return true;
    Forv(i,a[u])
    {
        int v = a[u][i];
        if(dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))
        {
            pairU[u] = v;
            pairV[v] = u;
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> n >> m >> p;
    For(i,1,p){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
    }
    int matching = 0;
    while(bfs())
        For(i,1,n) if(!pairU[i] && dfs(i)) matching++;
    cout << matching << endl;
}
