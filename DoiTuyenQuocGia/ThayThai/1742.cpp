#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define INF 1e18
#define maxn 200005
#define Bit(x,i) ((x >> i)&1)
#define ll long long
#define fi first
#define se second
using namespace std;

int p[maxn],h[maxn];

int n;

vector<pair<int,ll> > a[maxn];

ll d[maxn],ans = 0;

void dfs(int u,int p)
{
    //cout << u << ' ' << d[u] <<  endl;
    d[u] = 0;
    ll cur = 0;
    Forv(i,a[u])
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        if(v == p) continue;
        dfs(v,u);
        if(d[v] + w > 0) d[u] += d[v] + w;
    }
    ans = max(ans,d[u]);
}

int main()
{
    scanf("%d",&n);
    int cur = 1;
    For(i,1,n)
    {
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        if(i == 1) cur = u;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    dfs(cur,0);
    cout << ans << endl;
}
