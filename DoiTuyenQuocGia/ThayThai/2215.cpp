#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(long long i = a; i <= b; ++i)
#define maxn 10005
#define INF (ll)1e18
#define fi first
#define se second
#define Bit(x,i) ((x>>i)&1)
using namespace std;

struct cv
{
    ll s,t,s2,c;
    int id;
} a[maxn];

struct edge
{
    int to,cap;
    ll cost;
    int flow, rev,id;
};

int n,K,N,pe[maxn],pv[maxn];
ll d[maxn];
vector<edge> g[maxn];

void AddEdge(int u,int v,int c,ll w,int id)
{
    edge eu = {v,c,w,0,(int) g[v].size(),id};
    edge ev = {u,0,-w,0,(int) g[u].size(),id};
    g[u].push_back(eu);
    g[v].push_back(ev);
}

bool cmp(cv x,cv y)
{
    if(x.s != y.s) return x.s < y.s;
    if(x.s + x.t - 1 != y.s + y.t - 1) return ((x.s + x.t - 1) < (y.s + y.t - 1));
    return x.c < y.c;
}

void compress()
{
    vector<int> b;
    For(i,1,n)
    {
        b.push_back(a[i].s);
        b.push_back(a[i].s2);
    }
    sort(b.begin(),b.end());
    b.resize(unique(b.begin(),b.end()) - b.begin());
    N = b.size();
    For(i,1,n)
    {
        a[i].s = lower_bound(b.begin(),b.end(),a[i].s) - b.begin() + 1;
        a[i].s2 = lower_bound(b.begin(),b.end(),a[i].s2) - b.begin() + 1;
    }
}

void build()
{
    AddEdge(0,1,K,0,-1);
    AddEdge(N,N+1,K,0,-1);
    For(i,1,N-1) AddEdge(i,i+1,K,0,-1);
    For(i,1,n)
        AddEdge(a[i].s,a[i].s2,1,-a[i].c,a[i].id);
}

void ShortestPath(int s,int t)
{
    int M[maxn];
    For(i,1,N+1){
        M[i] = 2;
        d[i] = INF;
        pv[i] = s;
    }
    d[s] = 0;
    deque<int> dq;
    dq.push_back(s);
    while(!dq.empty())
    {
        int u = dq.front();
        dq.pop_front();
        M[u] = 0;
        for(int i = 0;i < g[u].size();i++)
        {
            int v = g[u][i].to,c = g[u][i].cap,w = g[u][i].cost,f = g[u][i].flow;
            if(c > f && d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pv[v] = u;
                pe[v] = i;
                if(M[v] == 2) dq.push_back(v);
                else if(M[v] == 0) dq.push_front(v);
                M[v] = 1;
            }
        }
    }
}

ll MinCostFlow(int s,int t)
{
    ll total_flow = 0,total_cost = 0;
    while(total_flow < K)
    {
        ShortestPath(s,t);
        if(d[t] == INF) return -1;
        int path_cap = K - total_flow;
        for(int v = t;v != s;v = pv[v])
        {
            int u = pv[v],i = pe[v];
            path_cap = min(path_cap,g[u][i].cap - g[u][i].flow);
        }

        for(int v = t;v != s;v = pv[v])
        {
            int u = pv[v],i = pe[v],r = g[u][i].rev;
            g[u][i].flow += path_cap;
            g[v][r].flow -= path_cap;
        }
        total_flow += path_cap;
        total_cost += 1ll*path_cap*d[t];
    }
    return total_cost;
}

int ans[maxn];

int main()
{
    cin >> n >> K;
    For(i,1,n)
    {
        scanf("%lld%lld%lld",&a[i].s,&a[i].t,&a[i].c);
        a[i].id = i;
        a[i].s2 = a[i].s + a[i].t;
    }
    if(K >= n)
    {
        For(i,1,n-1) printf("1 ");
        printf("1\n");
        return 0;
    }
    //sort(a+1,a+1+n,cmp);
    compress();
    build();
    MinCostFlow(0,N+1);
    memset(ans,0,sizeof(ans));
    For(u,1,N)
        for(int i = 0;i < g[u].size();i++)
        {
            //cout <<" << " << g[u][i].to << ' ' << g[u][i].id << ' ' << g[u][i].flow << endl;
            if(g[u][i].id > 0 && g[u][i].flow > 0)
                ans[g[u][i].id] = 1;
        }
    For(i,1,n-1) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}

/**

#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(long long i = a; i <= b; ++i)
#define maxn 1005
#define INF (ll)1e18
#define fi first
#define se second
#define Bit(x,i) ((x>>i)&1)
using namespace std;

struct cv
{
    ll s,t,c;
    int id;
} a[maxn];

int n,K;

bool cmp(cv x,cv y)
{
    if(x.s != y.s) return x.s < y.s;
    if(x.s + x.t - 1 != y.s + y.t - 1) return ((x.s + x.t - 1) < (y.s + y.t - 1));
    return x.c < y.c;
}

int g[maxn];

int ans[maxn];

void truyvet(int i)
{
    if(i == 0) return;
    truyvet(g[i]);
    ans[a[i].id] = 1;
}

void Sub1()
{
    sort(a+1,a+1+n,cmp);
    ll f[maxn];
    For(i,1,n+1)
        f[i] = a[i].c;
    f[0] = f[n+1] = 0;
    a[n+1] = {INF,0,0,n+1};
    For(i,1,n+1)
        For(j,1,i-1)
        {
            if(a[j].s + a[j].t - 1 < a[i].s)
                if(f[i] < f[j] + a[i].c)
                {
                    f[i] = f[j] + a[i].c;
                    g[i] = j;
                }
        }
    truyvet(n+1);
    For(i,1,n-1) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}

void Sub2()
{
    sort(a+1,a+1+n,cmp);
    pair<ll,int> best = {0,-1};
    for(int i = 0;i < (1<<n);i++)
    {
        bool ok = true;
        priority_queue<int> pq;
        ll cur = 0;
        For(j,0,n-1)
        {
            if(!Bit(i,j)) continue;
            cur += a[j+1].c;
            if(!pq.empty() && -pq.top() < a[j+1].s)
                pq.pop();
            pq.push(-(a[j+1].s + a[j+1].t - 1));
            if(pq.size() > K) break;
        }
        if(pq.size() <= K && cur > best.fi)
            best = {cur,i};
    }
    For(j,0,n-1)
        ans[a[j+1].id] = Bit(best.se,j);
    For(i,1,n-1) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}

void Sub3()
{
    pair<ll,int> best = {0,0};
    For(st,1,n)
    {
        ll cur = 0;
        priority_queue<ll> pq;
        For(i,st,n)
        {
            cur += a[i].c;
            if(!pq.empty() && -pq.top() < a[i].s)
                pq.pop();
            if(pq.size() < K) pq.push(-(a[i].s + a[i].t - 1));
            else cur -= a[i].c;
        }
        if(cur > best.fi) best = {cur,st};
    }
    ll cur = 0;
    priority_queue<ll> pq;
    For(i,best.se,n)
    {
        cur += a[i].c;
        if(!pq.empty() && -pq.top() < a[i].s)
            pq.pop();
        if(pq.size() < K)
        {
            pq.push(-(a[i].s + a[i].t - 1));
            ans[a[i].id] = 1;
        }
        else cur -= a[i].c;
    }
    For(i,1,n-1) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >> K;
    For(i,1,n)
    {
        scanf("%lld%lld%lld",&a[i].s,&a[i].t,&a[i].c);
        a[i].id = i;
    }
    if(K >= n)
    {
        For(i,1,n-1) printf("1 ");
        printf("1\n");
        return 0;
    }
    if(K == 1) Sub1();
    else
        if(n <= 20) Sub2();
    else
        Sub3();
}
**/
