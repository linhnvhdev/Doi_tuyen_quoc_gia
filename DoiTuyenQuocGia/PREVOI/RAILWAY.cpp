#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n,m,s;
ll t[maxn];

bool sub1 = true;

vector<pair<int,ll> > a[maxn];
vector<pair<int,int> > b[maxn];
ll d[maxn],g[maxn];
int trc[maxn];

vector<int> ans;

void truyvet(int u)
{
    for(int i = 0;i < b[u].size();i++)
    {
        int v = b[u][i].fi;
        int id = b[u][i].se;
        if(trc[u] == v)
        {
            truyvet(v);
            ans.push_back(id);
        }
    }
}

void Sub1()
{
    For(i,1,n) d[i] = g[maxn] = INF;
    d[s] = 0;
    g[s] = t[s];
    priority_queue<pair<pair<ll,ll>,int> > pq;
    pq.push({{0,-t[1]},1});
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cur_d = -pq.top().fi.fi;
        ll cur_t = -pq.top().se;
        pq.pop();
        if(cur_d + cur_t > d[u] + g[u]) continue;
        for(int i = 0;i < a[u].size();i++)
        {
            int v = a[u][i].fi; ll w = a[u][i].se;
            if(d[u] + w + min(g[u],t[v]) < d[v] + g[v])
            {
                d[v] = d[u] + w;
                g[v] = min(g[u],t[v]);
                trc[v] = u;
                pq.push({{-d[v],-g[v]},v});
            }
        }
    }
    //For(i,1,n) cout << i << ' ' << d[i] << ' ' << g[i] << endl;
    pair<ll,int> best = {-INF,0};
    For(u,1,n) if(d[u] != INF && d[u] + g[u] > best.fi) best = {d[u] + g[u],u};
    cout << best.fi << ' ' << best.se << '\n';
    truyvet(best.se);
    cout << ans.size() << '\n';
    for(int id : ans) cout << id << ' ';
}

int main()
{
    fast_read;
    freopen("RAILWAY.inp","r",stdin);
    freopen("RAILWAY.out","w",stdout);
    cin >> n >> m >> s;
    For(i,1,n)
    {
        cin >> t[i];
        //if(t[i] < 0 || t[i] > 10) sub1 = false;
    }
    For(i,1,m)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        b[v].push_back({u,i});
    }
    if(sub1) Sub1();
}
