#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxN 505
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
int n, m, t, st, en, d[maxN * maxN];
char a[maxN][maxN];
vector<pii>magic;
vector<pii>edge[maxN * maxN];
int id(int i, int j)
{
    return i * m + j;
}
bool Check(int u, int v)
{
    if(u < 0 || u >= n || v < 0 || v >= m || a[u][v] == '#')return false;
    return true;
}
void dijkstra(int s)
{
    For(i,0, m * n - 1)
        d[i] = 1e9;
    d[s] = 0;
    priority_queue<pii>pq;
    pq.push({0, s});
    while(!pq.empty())
    {
        int u = pq.top().se;
        int cur_d = -pq.top().first;
        pq.pop();
        if(cur_d > d[u])continue;
        for(int i = 0; i < edge[u].size(); i++)
        {
            int v = edge[u][i].fi, w = edge[u][i].se;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.push({-d[v], v});
            }
        }
    }
}
int main()
{
    //freopen("wall.inp", "r", stdin);
    //freopen("wall.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &t);
    For(i,0,n - 1)
        scanf("%s", &a[i]);
    For(i,0,n - 1)
        For(j,0, m - 1)
        {
            if(a[i][j] == 'W')st = id(i, j);
            if(a[i][j] == 'E')en = id(i, j);
            int add = a[i][j] == '+' ? t : 0;
            if(a[i][j] == 'P')magic.push_back({i, j});
            else
            {
                For(k,0,3)
                {
                    int u = i + dx[k], v = j + dy[k];
                    if(Check(u, v))
                        edge[id(i, j)].push_back({id(u, v), 1 + add});
                }
            }
        }
    for(pii x : magic)
        for(pii y : magic)
        {
            int i = x.fi, j = x.se, u = y.fi, v = y.se;
            if(i == u && j == v)continue;
            For(k,0,3)
            {
                int uu = u + dx[k], vv = v + dy[k];
                if(Check(uu, vv))
                    edge[id(i, j)].push_back({id(uu, vv), 1});
            }
        }

    dijkstra(st);
    if(d[en] == 1e9)printf("-1");
    else
        printf("%d", d[en]);
}
