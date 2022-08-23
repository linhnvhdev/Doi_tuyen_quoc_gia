/**
    int f[1001][101];
    For(i,1,n)
        For(j,0,cmin)
            f[i][j] = -1;
void tinh(int u,int c)
{
    if(u == t) return 1;
    if(f[u][c] != -1) return f[u][c];
    f[u][c] = 0;
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        int c1 = d[u] + c - w - d[v];
        if(c1 < 0) return;
        f[u][c] = min(f[u][c] + cnt(v,c1),k);
    }
    return f[u][c];
}
    int s = cnt(1,cmin);
    if(s < k) cout << -1 << endl;
**/

#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(long long i = a; i <= b; ++i)
#define maxn 1005
#define INF (ll)1e18
#define fi first
#define se second
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n,m,t;
ll k;

int cmin = 1e9, tmin = 1e9;
int d[maxn];
ll qos,f[maxn][maxn];

vector<pair<int,int> > a[maxn],b[maxn];
vector<int> ans;

void dijkstra(int st,int ed)
{
    For(i,1,n) d[i] = 1e9;
    d[st] = 0;
    priority_queue<pair<ll,int> > pq;
    pq.push({0,st});
    while(!pq.empty())
    {
        int u = pq.top().se;
        ll cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > d[u]) continue;
        for(int i = 0;i < b[u].size();i++)
        {
            int v = b[u][i].fi; ll w = b[u][i].se;
            if(d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.push({-d[v],v});
            }
        }
    }
    tmin = d[ed];
}

int cur_d = 0;
int x[100005];

void dfs(int u,int dem,ll cur_tre)
{
    if(cur_tre > qos) return;
    if(u == t)
    {
        cur_d++;
        if(cur_d == k)
        {
            dem--;
            cout << dem << endl;
            For(i,1,dem-1) printf("%d ",x[i]);
            printf("%d\n",x[dem]);
            exit(0);
        }
        return;
    }
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        x[dem] = v;
        dfs(v,dem+1,cur_tre + w);
    }
}

ll Tinh(int u,int c)
{
    if(u == t) return 1;
    if(f[u][c] != -1) return f[u][c];
    f[u][c] = 0;
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi; ll w = a[u][i].se;
        int C = d[u] + c - d[v] - w;
        //cout << u << ' ' << v << ' ' << c << ' ' << C << endl;
        if(C < 0) continue;
        f[u][c] = min(k,f[u][c] + Tinh(v,C));
    }
    return f[u][c];
}

void DFS(int u,int c)
{
    ans.push_back(u);
    if(u == t) return;
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi; ll w = a[u][i].se;
        ll C = d[u] + c - d[v] - w;
        if(C < 0) continue;
        if(Tinh(v,C) < k) k -= Tinh(v,C);
        else
        {
            DFS(v,C);
            return;
        }
    }
}

void Sub3()
{
    For(i,1,n)
        For(j,0,cmin) f[i][j] = -1;
    ll s = Tinh(1,cmin);

    if(s < k) {cout << -1 << endl; exit(0);}
    DFS(1,cmin);
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size()-1;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[ans.size()-1]);
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >> m >> t >> k;
    For(i,1,m)
    {
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back({v,w});
        b[v].push_back({u,w});
        cmin = min(cmin,w);
    }
    For(u,1,n) sort(a[u].begin(),a[u].end());
    dijkstra(t,1);
    qos = cmin + tmin;
    if(qos >= INF)
    {
        cout << -1 << endl;
        return 0;
    }
    Sub3();
}
