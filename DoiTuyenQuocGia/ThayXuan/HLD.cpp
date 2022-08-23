#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n;
int p[maxn],s[maxn],scmax[maxn],cnt = 0;
int d[maxn],heavy[maxn],pos[maxn],head[maxn];

vector<int> a[maxn];

void dfs(int u)
{
    s[u] = 1;
    for(int v : a[u])
    {
        if(v == p[u]) continue;
        p[v] = u;
        d[v] = d[u] + 1;
        dfs(v);
        s[u] += s[v];
        if(s[v] > scmax[u])
            scmax[u] = s[v], heavy[u] = v;
    }
}

void hld(int u,int cur_head)
{
    head[u] = cur_head;
    pos[u] = ++cnt;
    if(heavy[u])
        hld(heavy[u],cur_head);
    for(int v : a[u])
        if(v != p[u] && v != heavy[u])
            hld(v,v);
}

int lca(int u,int v)
{
    for(;head[u] != head[v]; u = p[head[u]])
        if(d[head[u]] < d[head[v]]) swap(u,v);
    return (pos[u] < pos[v]) ? u : v;
}

int main()
{
    freopen("test.inp","r",stdin);
    scanf("%d",&n);
    For(i,1,n-1)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        a[u].push_back(v);
        a[v].push_back(u);
    }

    dfs(1);
    hld(1,1);
}
/**
18
3 6
1 7
1 3
1 2
2 5
2 4
7 8
8 9
9 10
5 11
5 12
4 13
13 14
13 15
15 16
8 17
3 18
**/
