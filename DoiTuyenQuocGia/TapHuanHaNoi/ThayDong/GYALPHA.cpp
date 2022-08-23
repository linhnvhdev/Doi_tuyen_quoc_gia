#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define pii pair<int,int>
using namespace std;

int n,m;
string s;
int g[maxn],r[maxn],ng = 0,nr = 0;

int ct[maxn],d[maxn];
priority_queue<pii> pq;
vector<pii> a[maxn];

void dijkstra(int st,int cur_ct)
{
    For(i,1,n) d[i] = INF;
    d[st] = 0;
    pq.push({0,st});
    while(!pq.empty())
    {
        int u = pq.top().se;
        int cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > d[u]) continue;
        for(int i = 0;i < a[u].size();i++)
        {
            int v = a[u][i].fi, w = a[u][i].se;
            if(ct[u] == cur_ct && ct[v] != ct[u]) w = 4;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.push({-d[v],v});
            }
        }
    }
}

int main()
{
    fast_read;
    freopen("GYALPHA.inp","r",stdin);
    freopen("GYALPHA.out","w",stdout);
    cin >> n >> m >> s;
    For(i,0,n-1)
    {
        if(s[i] == 'G') g[++ng] = i+1;
        else r[++nr] = i+1;
        ct[i+1] = (s[i] == 'G') ? 1 : 2;
    }
    For(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        int w = 1;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    ll ansg = 0,ansy = 0;
    For(i,1,ng-1)
    {
        //cout << g[i] << endl;
        dijkstra(g[i],1);
        For(j,i+1,ng) ansg += 1ll*d[g[j]];
    }
    For(i,1,nr-1)
    {
        dijkstra(r[i],2);
        For(j,i+1,nr) ansy += 1ll*d[r[j]];
    }
    cout << ansg << ' ' << ansy << endl;
}

