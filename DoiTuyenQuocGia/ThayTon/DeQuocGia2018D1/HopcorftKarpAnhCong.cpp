#include <bits/stdc++.h>
#define endl '\n'
#define ft(vt,i) for(__typeof((vt).begin()) i = (vt).begin() ; i != (vt).end() ; ++i)
using namespace std;
const int maxN = 5* 1e4 + 190;
const int inf = 0x3c3c3c3c;
typedef struct pair<int,int> ii;
typedef struct vector<int> vi;
typedef struct vector<vi> vii;

int n , m , p , match[maxN * 2] , dist[maxN * 2];
vii adj;
bool bfs()
{
	queue<int> Q;
	for(int i = 1 ; i <= n ; ++i)
	{
		if(match[i] == 0)
		{
			dist[i] = 0;
			Q.push(i);
		}
		else dist[i] = inf;
	}
	dist[0] = inf;

	while(!Q.empty())
	{
		int u = Q.front(); Q.pop();
        if(u != 0)
		{
            ft(adj[u] ,it)
            {
            	int v = *it;
            	if(dist[match[v]] == inf)
				{
					dist[match[v]] = dist[u] + 1;
					Q.push(match[v]);
				}
            }
		}
	}

	return (dist[0] != inf);
}
bool dfs(int u)
{
	if(u != 0)
	{
        ft(adj[u], it)
        {
        	int v = *it;
            if(dist[match[v]] == dist[u] + 1)
			{
                if(dfs(match[v]))
				{
					match[u] = v;
					match[v] = u;
					return true;
				}
			}
        }
        return false;
	}
	return true;
}
void hopcroft_karp()
{
	int matching = 0;
	while(bfs())
		for(int i = 1 ; i <= n ; ++i) if(!match[i] && dfs(i)) matching++;
	printf("%d",matching);
}
int main()
{
	scanf("%d%d%d",&n , &m , &p);
	adj.assign(n + m + 1, vi());
	int u , v;
	for(int i = 0 ; i < p ; ++i)
	{
		scanf("%d%d",&u,&v);
		v += n;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	hopcroft_karp();
	return 0;
}
