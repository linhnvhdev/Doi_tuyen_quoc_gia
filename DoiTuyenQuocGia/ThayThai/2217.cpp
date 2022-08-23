#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a; i >= b; --i)
#define maxN 100005
#define ll long long
#define pill pair<int, ll>
#define pii pair<int, int>
#define fi first
#define se second
#define INF 1e18
#define Bit(x, i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n, m, k, in[maxN], A, B;
vector<pill> adj[maxN];
vector<pii> hard, easy;
ll d1[maxN], d2[maxN], D[11][maxN], D2[11][maxN], D3[11][maxN], D4[11][maxN], ans = 0, dp[maxN][33][6];
queue<int> q;

void dijkstra(int st, ll d[])
{
    For(i,1,n) d[i] = INF;
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

bool CheckEasy(int i, int u, int v, ll w)
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
            if(!CheckNam(u, v, w)) continue;
            ll add = 0;
            for(int i = 0; i < hard.size(); i++)
                if(CheckHard(i, u, v, w))
                {
                    add = 1;
                    break;
                }
            For(mask,0, (1 << cnt) - 1)
                For(cur,0,cnt)
                {
                    ll sum = dp[u][mask][cur];
                    if(sum == -INF)continue;
                    int new_mask = (cur == cnt ? mask : (mask | (1 << cur)));
                    dp[v][new_mask][cnt] = max(dp[v][new_mask][cnt], sum + w * add);

                    For(i,0,cnt - 1)
                    {
                        if(i == cur)
                        {
                            if(CheckEasy(cur, u, v, w))
                                dp[v][mask][cur] = max(dp[v][mask][cur], sum + w);
                            else
                                dp[v][new_mask][cnt] = max(dp[v][new_mask][cnt], sum + w * add);
                        }
                        else
                        {
                            if(CheckEasy(i, u, v, w))
                            {
                                if(Bit(mask, i))continue;
                                dp[v][new_mask][i] = max(dp[v][new_mask][i], sum + w);
                            }
                            else
                                dp[v][new_mask][cnt] = max(dp[v][new_mask][cnt], sum + w * add);
                        }
                    }
                }
            in[v]--;
            if(in[v] == 0)q.push(v);
        }
    }
    For(mask,0,(1 << cnt)-1)
        For(cur,0,cnt)
            ans = max(ans, dp[B][mask][cur]);
    printf("%lld", ans);
}


/**

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define INF 1e18
using namespace std;

int m,n,k;

vector<pair<int,ll> > adj[maxn];

int p[maxn],a[maxn],b[maxn],trc[maxn];

ll d1[maxn],d2[maxn],d3[maxn],d4[maxn];
ll dist[505][505];

void dijkstra(ll d[maxn],int st)
{
    For(i,1,n) d[i] = INF;
    d[st] = 0;
    priority_queue<pair<ll,int> > pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > d[u]) continue;
        for(int i = 0;i < adj[u].size();i++)
        {
            int v = adj[u][i].fi;
            ll w = adj[u][i].se;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                trc[v] = u;
                pq.push({-d[v],v});
            }
        }
    }
    return;
}

bool used[maxn];

ll ans = 0;

void truyvet(int u)
{
    if(d1[u] + d2[u] == d1[b[2]])
        ans = max(ans,d1[u]);
    if(u == a[1]) return;
    for(int i = 0; i < adj[u].size();i++)
    {
        int v = adj[u][i].fi;
        ll w = adj[u][i].se;
        if(d1[u] == d1[v] + w) truyvet(v);
    }
}

void Sub1()
{
    dijkstra(d1,a[1]);
    dijkstra(d2,b[2]);
    //For(i,1,n) cout << i << ' ' <<d1[i] << endl;
    truyvet(b[1]);
    cout << ans << endl;
}

bool check(int u)
{
    if(dist[a[1]][u] + dist[u][b[1]] != dist[a[1]][b[1]]) return false;
    if(dist[a[2]][u] + dist[u][b[2]] != dist[a[2]][b[2]]) return false;
    if(p[2] == 0 && dist[a[1]][u] != dist[a[2]][u]) return false;
    return true;
}

void Sub2()
{
    For(i,1,n) dist[i][i] = 0;
    For(k,1,n)
        For(i,1,n)
            For(j,1,n)
                if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
    ans = 0;
    //For(i,1,n) if(check(i)) cout << i << endl;
    For(u,1,n)
        For(v,1,n)
            if(u != v && check(u) && check(v))
            {
                if(dist[a[1]][u] + dist[u][v] == dist[a[1]][v])
                    ans = max(ans,dist[u][v]);
            }
    cout << ans << endl;
}

pair<ll,int> t[maxn];
ll N = 0;


bool checksub3(int u)
{
    if(d1[u] + d2[u] != d1[b[1]]) return false;
    if(d3[u] + d4[u] != d3[b[2]]) return false;
    if(p[2] == 0 && d1[u] != d3[u]) return false;
    return true;
}

void Sub3()
{
    dijkstra(d1,a[1]);
    dijkstra(d2,b[1]);
    dijkstra(d3,a[2]);
    dijkstra(d4,b[2]);
    For(u,1,n) if(checksub3(u)) t[++N] = {d1[u],u};
    sort(t+1,t+1+N);
    cout << t[N].fi - t[1].fi << endl;
}

ll D[11][maxn],D2[11][maxn];

bool checkNam(int u,int v,ll w)
{
    return(D[1][u] + w + D2[1][v] == D[1][b[1]]);
}

int in[maxn];

ll dp[maxn];

bool checkHard(int i,int u,int v,ll w)
{
    return(D[i][u] + w + D2[i][v] == D[i][b[i]] && D[1][u] == D[i][u]);
}

void Sub4()
{
    For(i,1,k)
    {
        //cerr << i << endl;
        dijkstra(D[i],a[i]);
        dijkstra(D2[i],b[i]);
    }
    memset(in,0,sizeof(in));
//    For(i,1,n)
//        cout << i << ' ' << D[2][i] << ' ' << D2[2][i] << endl;
    For(u,1,n)
        for(int i = 0;i < adj[u].size();i++)
        {
            int v = adj[u][i].fi;
            ll w = adj[u][i].se;
            if(checkNam(u,v,w)) in[v]++;
        }
    //For(i,1,n) if(in[i] != 0) cerr << i << ' ' << in[i] << ' ' << endl;
    queue<int> q;
    memset(dp,0,sizeof(dp));
    q.push(a[1]);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0;i < adj[u].size();i++)
        {
            int v = adj[u][i].fi;
            ll w = adj[u][i].se;
            if(!checkNam(u,v,w)) continue;
            ll add = 0;
            For(j,2,k) if(checkHard(j,u,v,w)) {add = w; break;}
            dp[v] = max(dp[v],dp[u] + add);
            in[v]--;
            if(in[v] == 0) q.push(v);
        }
    }
    ans = 0;
    For(i,1,n) ans = max(ans,dp[i]);
    cout << ans << endl;
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >> m >> k;
    if(n <= 300)
        For(u,1,n)
            For(v,1,n) dist[u][v] = INF;
    For(i,1,m)
    {
        int u,v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        if(n <= 300) dist[u][v] = dist[v][u] = min(dist[u][v],w);
    }
    cin >> a[1] >> b[1];
    For(i,2,k) cin >> p[i] >> a[i] >> b[i];
    if(k == 2)
    {
        if(a[1] == a[2]) Sub1();
        else
            if(n <= 100) Sub2();
        else
            Sub3();
    }
    else
        Sub4();
}
**/
