#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n;
ll f[maxn],s[maxn],mind;
int ans[maxn],m = 0;

vector<pair<int,ll> > adj[maxn];

void dfs(int u,int p)
{
    s[u] = 1;
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i].fi;
        ll w = adj[u][i].se;
        if(v == p) continue;
        dfs(v,u);
        s[u] += s[v];
        f[u] += f[v] + w*s[v];
    }
}

void DFS(int u,int p)
{
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i].fi;
        ll w = adj[u][i].se;
        if(v == p) continue;
        ///f[v] = f[v] + (f[u] - f[v] - w*s[v]) + w*(s[1] - s[v]);
        f[v] = f[u] - 2*w*s[v] + w*s[1];
        if(f[v] < mind)
        {
            m = 1;
            ans[m] = v;
        }
        if(f[v] == mind) ans[++m] = v;
        mind = min(mind,f[v]);
        DFS(v,u);
    }
}

int main()
{
    cin >> n;
    For(i,1,n-1)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    dfs(1,0);
    mind = f[1];
    ans[++m] = 1;
    DFS(1,0);
    cout << m << endl;
    sort(ans+1,ans+1+m);
    For(i,1,m-1) printf("%d ",ans[i]);
    printf("%d",ans[m]);
}
