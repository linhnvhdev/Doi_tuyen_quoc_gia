#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 505
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define pii pair<int,int>
using namespace std;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

int n,m,t,st,ed,p[maxn][maxn],a[maxn][maxn],N = 0;

char s[maxn];
int dp = 0,cnt = 0;
ll d[maxn*maxn];

vector<pair<int,ll> > edge[maxn*maxn];
vector<pii> P;

void Read()
{
    freopen("WALL.inp","r",stdin);
    freopen("WALL.out","w",stdout);
    scanf("%d%d%d",&n,&m,&t);
    For(i,1,n){
        scanf("%s",&s);
        For(j,0,strlen(s)-1){
            p[i][j+1] = ++cnt;
            if(s[j] == '.') a[i][j+1] = 1;
            if(s[j] == 'W'){
                a[i][j+1] = 2;
                st = cnt;
            }
            if(s[j] == 'E'){
                a[i][j+1] = 3;
                ed = cnt;
            }
            if(s[j] == '#') a[i][j+1] = 0;
            if(s[j] == '+') a[i][j+1] = 4;
            if(s[j] == 'P') a[i][j+1] = 5;
        }
    }
}

bool check(int i,int j)
{
    return (i >= 1 && i <= n && j >= 1 && j <= m && a[i][j] != 0);
}

void KhoiTao()
{
    For(i,1,n)
        For(j,1,m)
        {
            int add = (a[i][j] == 4) ? t : 0;
            if(a[i][j] == 5) P.push_back({i,j});
            else{
                For(k,0,3)
                {
                    int u = i + dx[k], v = j + dy[k];
                    if(check(u, v))
                        edge[p[i][j]].push_back({p[u][v], 1 + add});
                }
            }
        }
    for(int ii = 0;ii < P.size();ii++)
        for(int jj = 0;jj < P.size();jj++)
        {
            pii x = P[ii],y =P[jj];
            int i = x.fi, j = x.se, u = y.fi, v = y.se;
            if(i == u && j == v)continue;
            For(k,0,3)
            {
                int uu = u + dx[k], vv = v + dy[k];
                if(check(uu, vv))
                    edge[p[i][j]].push_back({p[uu][vv], 1});
            }
        }
}

void Dijkstra()
{
    For(i,1,cnt) d[i] = INF;
    d[st] = 0;
    priority_queue<pair<ll,int> > pq;
    pq.push({0,st});
    while(!pq.empty()){
        int u = pq.top().se;
        ll cur_d = -pq.top().fi;
        pq.pop();
        if(cur_d > d[u]) continue;
        for(int i = 0;i < edge[u].size();i++){
            int v = edge[u][i].fi;
            ll w = edge[u][i].se;
            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                pq.push({-d[v],v});
            }
        }
    }
    if(d[ed] == INF) printf("-1\n");
    else printf("%d\n",d[ed]);
}

int main()
{
    Read();
    KhoiTao();
    Dijkstra();
}
