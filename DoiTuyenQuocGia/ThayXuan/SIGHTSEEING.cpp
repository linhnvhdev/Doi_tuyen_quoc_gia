#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 500005
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define pii pair<int,int>
using namespace std;

int n,m,q,d[maxn];

vector<pii> a[maxn];

void dijkstra()
{
    For(i,1,n) d[i] = -INF;
    d[1] = INF;
    priority_queue<pii> pq;
    pq.push({INF,1});
    int u,v,w,cur_d,c;
    while(!pq.empty())
    {
        u = pq.top().se;
        cur_d = pq.top().fi;
        pq.pop();
        if(cur_d < d[u]) continue;
        Forv(i,a[u])
        {
            v = a[u][i].fi;
            w = a[u][i].se;
            c = (d[u] < w) ? d[u] : w;
            if(c > d[v])
            {
                d[v] = c;
                pq.push({d[v],v});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SIGHTSEEING.inp","r",stdin);
    freopen("SIGHTSEEING.out","w",stdout);
    cin >> n >> m >> q;
    int u,v,w;
    For(i,1,m)
    {
        cin >> u >> v >> w;
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    dijkstra();
    For(i,1,q)
    {
        cin >> u;
        cout << d[u] << '\n';
    }
}
