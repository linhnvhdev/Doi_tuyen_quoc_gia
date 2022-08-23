#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a; i >= b; --i)
#define maxN 100005
#define ll long long
#define pill pair<int, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define Bit(x, i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

const ll INF = 1e15;
int n, m, k, in[maxN], A, B;
vector<pill> adj[maxN];
vector<pii> hard, easy;
ll d1[maxN], d2[maxN], D[11][maxN], D2[11][maxN], D3[11][maxN], D4[11][maxN], ans = 0, dp[maxN][33][6];
queue<int>q;

void dijkstra(int st, ll d[])
{
    For(i,1,n)
        d[i] = INF;
    d[st] = 0;
    priority_queue<pair<ll, int> >pq;
    pq.push({0, st});
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > d[u])continue;
        for(pill c : adj[u])
        {
            int v = c.fi;
            ll w = c.se;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.push({-d[v], v});
            }
        }
    }
}

bool CheckNam(int u, int v, ll w)
{
    return (d1[u] + w + d2[v] == d1[B]);
}

bool CheckEz(int i, int u, int v, ll w)
{
    return (D[i][u] + w + D2[i][v] == D[i][easy[i].se]);
}

bool CheckHard(int i, int u, int v, ll w)
{
    return (D3[i][u] + w + D4[i][v] == D3[i][hard[i].se] && D3[i][u] == d1[u]);
}

int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d%d%d", &n, &m, &k);
    For(i,1,m)
    {
        int u, v;
        ll w;
        scanf("%d%d%lld", &u, &v, &w);
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    scanf("%d%d", &A, &B);
    For(i,1,k - 1)
    {
        int p, s, t;
        scanf("%d%d%d", &p, &s, &t);
        if(p == 0)hard.push_back({s, t});
        else
            easy.push_back({s, t});
    }
    dijkstra(A, d1);
    dijkstra(B, d2);
    for(int i = 0; i < easy.size(); i++)
    {
        int u = easy[i].fi, v = easy[i].se;
        dijkstra(u, D[i]);
        dijkstra(v, D2[i]);
    }
    for(int i = 0; i < hard.size(); i++)
    {
        int u = hard[i].fi, v = hard[i].se;
        dijkstra(u, D3[i]);
        dijkstra(v, D4[i]);
    }
    For(u,1,n)
        for(pill c : adj[u])
        {
            int v = c.fi;
            ll w = c.se;
            if(CheckNam(u, v, w))
                in[v]++;
        }
    int cnt = easy.size();
    For(i,1,n)
        For(mask,0, (1 << cnt) - 1)
            For(cur,0,cnt)
                dp[i][mask][cur] = -INF;
    dp[A][0][cnt] = 0;
    q.push(A);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(pill c : adj[u])
        {
            int v = c.fi;
            ll w = c.se;
            if(!CheckNam(u, v, w))continue;
            ll hardcore = 0;
            for(int i = 0; i < hard.size(); i++)
                if(CheckHard(i, u, v, w))
                {
                    hardcore = 1;
                    break;
                }
            For(mask,0, (1 << cnt) - 1)
                For(cur,0,cnt)
                {
                    ll sum = dp[u][mask][cur];
                    if(sum == -INF)continue;
                    int new_mask = (cur == cnt ? mask : (mask | (1 << cur)));
                    dp[v][new_mask][cnt] = max(dp[v][new_mask][cnt], sum + w * hardcore);

                    For(i,0,cnt - 1)
                    {
                        if(i == cur)
                        {
                            if(CheckEz(cur, u, v, w))
                                dp[v][mask][cur] = max(dp[v][mask][cur], sum + w);
                            else
                                dp[v][new_mask][cnt] = max(dp[v][new_mask][cnt], sum + w * hardcore);
                        }
                        else
                        {
                            if(CheckEz(i, u, v, w))
                            {
                                if(Bit(mask, i))continue;
                                dp[v][new_mask][i] = max(dp[v][new_mask][i], sum + w);
                            }
                            else
                                dp[v][new_mask][cnt] = max(dp[v][new_mask][cnt], sum + w * hardcore);
                        }
                    }
                }
            in[v]--;
            if(in[v] == 0)q.push(v);
        }
    }
    For(mask,0,(1 << cnt) - 1)
        For(cur,0,cnt)
            ans = max(ans, dp[B][mask][cur]);
    printf("%lld", ans);
}
