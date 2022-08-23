#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define INF 1e9
using namespace std;

int n,m,k,q,p[maxn],h[maxn];
int d[maxn];

vector<int> g[maxn],f[maxn];

void make_set(int i)
{
    p[i] = i;
    h[i] = 0;
    g[i].push_back(i);
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

bool Union(int a,int b)
{
    int x = Find(a);
    int y = Find(b);
    if(x == y) return false;
    if(h[x] < h[y])
    {
        for(int u : g[x])
        {
            for(int v : f[u])
                if(Find(v) == y) d[u]++,d[v]++;
            g[y].push_back(u);
        }
        p[x] = y;
    }
    else
    {
        for(int u : g[y])
        {
            for(int v : f[u])
                if(Find(v) == x) d[u]++,d[v]++;
            g[x].push_back(u);
        }
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

int main()
{
    fast_read;
    cin >> n >> m >> k;
    For(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        f[u].push_back(v);
        f[v].push_back(u);
    }
    For(i,1,n) make_set(i);
    For(i,1,k)
    {
        int u,v;
        cin >> u >> v;
        Union(u,v);
    }
    cin >> q;
    For(i,1,q)
    {
        char type;
        int u,v;
        cin >> type;
        if(type == '?')
        {
            cin >> u;
            cout << d[u] << endl;
        }
        if(type == 'T')
        {
            cin >> u >> v;
            Union(u,v);
        }
        if(type == 'F')
        {
            cin >> u >> v;
            if(Find(u) == Find(v)) d[u]++,d[v]++;
            else f[u].push_back(v), f[v].push_back(u);
        }
    }
}
