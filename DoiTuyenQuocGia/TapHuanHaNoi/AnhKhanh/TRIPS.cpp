#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

pii event[maxn];
int n,m,k;
int degree[maxn];
set<pii> s;
int ans[maxn];

vector<int> a[maxn];

bool del[maxn];
map<pii,bool> used;

set<pii>::iterator it;

void dfs(int u,int p)
{
    for(int v : a[u])
    {
        if(v == p || used[{u,v}]) continue;
        it = s.find({degree[v],v});
        if(it == s.end()) continue;
        s.erase(it);
        degree[v]--;
        used[{u,v}] = used[{v,u}] = true;
        if(degree[v] < k) dfs(v,u);
        else s.insert({degree[v],v});
    }
}

void Del(int u,int v)
{
    if(used[{u,v}]) return;
    used[{u,v}] = true;
    it = s.find({degree[u],u});
    if(it != s.end())
    {
        s.erase(it);
        degree[u]--;
        if(degree[u] >= k)
            s.insert({degree[u],u});
        else dfs(u,0);
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    For(i,1,m)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        event[i] = {u,v};
        a[u].push_back(v);
        a[v].push_back(u);
        degree[u]++;
        degree[v]++;
    }
    For(i,1,n) s.insert({degree[i],i});
    Forr(i,m,1)
    {
        while(!s.empty() && (s.begin())->fi < k)
        {
            int u = (s.begin())->se;
            s.erase(s.begin());
            dfs(u,0);
        }
        ans[i] = s.size();
        int u = event[i].fi,v = event[i].se;
        Del(u,v);
        Del(v,u);
    }
    For(i,1,m)
        printf("%d\n",ans[i]);
}
