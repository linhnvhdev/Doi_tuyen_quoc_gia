#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Ford(i,a,b) for(int i = a; i >= b; --i)
#define pii pair<int, int>
#define maxN 200005
#define fi first
#define se second
using namespace std;
int n, m, k, ans[maxN], degree[maxN];
pii query[maxN];
vector<int>edge[maxN];
map<pii, bool>used;
set<pii>s;
set<pii>::iterator it;
void dfs(int u, int p)
{
    for(int v : edge[u])
    {
        if(v == p || used[{u, v}])continue;
        it = s.find({degree[v], v});
        if(it == s.end())continue;
        s.erase(it);
        degree[v]--;
        used[{u, v}] = used[{v, u}] = true;
        if(degree[v] < k)dfs(v, u);
        else
            s.insert({degree[v], v});
    }
}
void Upd(int u, int v)
{
    if(used[{u, v}])return;
    used[{u, v}] = true;
    it = s.find({degree[u], u});
    if(it == s.end())return;
    s.erase(it);
    degree[u]--;
    if(degree[u] >= k)s.insert({degree[u], u});
    else
        dfs(u, u);
}
int main()
{
//    freopen("trips.inp", "r", stdin);
//    freopen("trips.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &k);
    For(i,1,m)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        degree[u]++;
        degree[v]++;
        edge[u].push_back(v);
        edge[v].push_back(u);
        query[i] = {u, v};
    }
    For(i,1,n)
        s.insert({degree[i], i});
    Ford(i,m,1)
    {
        while(!s.empty() && s.begin()->fi < k)
        {
            int u = s.begin()->se;
            s.erase(s.begin());
            dfs(u, u);
        }
        ans[i] = s.size();
        int u = query[i].fi, v = query[i].se;
        Upd(u, v);
        Upd(v, u);
    }
    For(i,1,m - 1)
        printf("%d\n", ans[i]);
    printf("%d", ans[m]);
}
