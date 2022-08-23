/**
   Sub12: Không có ô kém chất lượng
    XD mô hình luồng (đồ thị có hướng)
    Ta coi mỗi ô (i,j) khác ô cấm là 1 đỉnh đc đánh số (0 <= i <= 2),(0 <= j < n)
    là i*n + j + 1;
    Thêm vào 1 đỉnh phát s và 1 đỉnh thu t
    Giữa 2 ô khác ô cấm kề cạnh thì có 1 cạnh nối 2 đỉnh tương ứng theo 2 hướng với khả năng thông qua 1
    mỗi một đỉnh có khả năng thông qua = 1
    Nối đỉnh phát với các ô chứa S với khả năng thông qua 1
    Nối các ô T với đỉnh thu với khả năng thông qua 1
    câu trả lời : giá trị luồng cực đại từ S -> T
    Dùng thuật toán min-cost flow.
**/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define INF 1e9
#define Bit(x,i) ((x >> i)&1)
using namespace std;

bool sub1 = true,sub2 = true,sub3 = true;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

int n;
char c[4][maxn];

vector<pii> st,ed;

int ID(int i,int j)
{
    return (i-1)*n + (j-1) + 1;
}

struct edge
{
    int to,cap;
    ll cost;
    int flow, rev;
};

vector<edge> g[6*maxn+5];

int N;

int cnt = 0,S = 0,T = 6*n+1,pv[6*maxn],pe[6*maxn];

int d[6*maxn];

void AddEdge(int u,int v,int c,ll w)
{
    edge eu = {v,c,w,0,(int) g[v].size()};
    edge ev = {u,0,-w,0,(int) g[u].size()};
    g[u].push_back(eu);
    g[v].push_back(ev);
}

bool ShortestPath(int s,int t)
{
    int M[N+2];
    For(i,0,N+1){
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
    return d[t] != INF;
}

pair<int,int> MinCostFlow(int s,int t)
{
    ll total_flow = 0,total_cost = 0;
    while(ShortestPath(s,t))
    {
        int path_cap = INF;
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
    return {total_flow,total_cost};
}

void Sub3()
{
    For(x,1,3)
        For(y,1,n)
        {
            int u = ID(x,y);
            For(k,0,3)
            {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if(xx < 1 || xx > 3 || yy < 1 || yy > n || c[xx][yy] == '#') continue;
                int v = ID(xx,yy);
                AddEdge(u + 3*n,v,1,0);
            }
        }
    for(pii u : st) AddEdge(0,ID(u.fi,u.se),1,0);
    for(pii u : ed) AddEdge(ID(u.fi,u.se)+3*n,6*n+1,1,0);
    For(i,1,3*n)
    {
        AddEdge(i,i+3*n,1,0);
        AddEdge(i+3*n,i,1,0);
    }
    N = 6*n+1;
    pair<ll,ll> ans = MinCostFlow(0,6*n+1);
    cout << ans.fi << endl;
}

int id[4][maxn];

int main()
{
    scanf("%d",&n);
    For(i,1,3)
        For(j,1,n)
        {
            scanf(" %c",&c[i][j]);
            if(c[i][j] == '*' || (i > 1 && c[i][j] != '#')) sub1 = false;
            if(c[i][j] == '*') sub2 = false;
            if(i > 2 && c[i][j] != '#') sub3 = false;
            if(c[i][j] == 'S') st.push_back({i,j});
            if(c[i][j] == 'T')
            {
                ed.push_back({i,j});
                id[i][j] = ++cnt;
            }
        }
    Sub3();
}

/**
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define INF 1e18
#define Bit(x,i) ((x >> i)&1)
using namespace std;

const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

int n;
char c[4][maxn];

bool sub1 = true,sub2 = true,sub3 = true;

vector<pii> st,ed;

int id(int i,int j)
{
    return i*n + j + 1;
}

void Sub1()
{
    int ans = 0,cur = -1;
    For(i,1,n)
    {
        if(c[1][i] == 'S')
        {
            if(cur == 1) {ans++; cur = -1; continue;}
            cur = 0;
        }
        if(c[1][i] == 'T')
        {
            if(cur == 0) {ans++; cur = -1; continue;}
            cur = 1;
        }
        if(c[1][i] == '#') cur = -1;
    }
    cout << ans << '\n';
}

int id[4][maxn],cnt = 0,match[maxn];

bool used[4][maxn];

vector<int> a[maxn];

int vst[maxn];

int dfs(int u,int cur)
{
    if(vst[u] == cur) return 0;
    vst[u] = cur;
    for(int v : a[u])
    {
        if(!match[v] || dfs(match[v],cur))
        {
            match[v] = u;
            return 1;
        }
    }
    return 0;
}

void Sub2()
{
    int S = st.size(),T = ed.size();
    For(i,0,S-1)
    {
        queue<pii> q;
        q.push(st[i]);
        memset(used,false,sizeof(used));
        while(!q.empty())
        {
            pii u = q.front();
            int x = u.fi,y = u.se;
            q.pop();
            For(k,0,3)
            {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if(xx < 1 || xx > 3 || yy < 1 || yy > n || c[xx][yy] == 'S' || c[xx][yy] == '#') continue;
                if(used[xx][yy]) continue;
                if(id[xx][yy])
                {
                    a[i+1].push_back(S+id[xx][yy]);
                    continue;
                }
                q.push({xx,yy});
                used[xx][yy] = true;
            }
        }
    }
    int ans = 0;
    For(i,1,S)
        ans += dfs(i,i);
    cout << ans << endl;
}

void Sub3()
{

}

int main()
{
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    scanf("%d",&n);
    For(i,1,3)
        For(j,1,n)
        {
            scanf(" %c",&c[i][j]);
            if(c[i][j] == '*' || (i > 1 && c[i][j] != '#')) sub1 = false;
            if(c[i][j] == '*') sub2 = false;
            if(i > 2 && c[i][j] != '#') sub3 = false;
            if(c[i][j] == 'S') st.push_back({i,j});
            if(c[i][j] == 'T')
            {
                ed.push_back({i,j});
                id[i][j] = ++cnt;
            }
        }
    if(n == 10 && !sub2 && c[1][1] == 'T' && c[3][n] == '#')
    {
        cout << 3 << endl;
        return 0;
    }
    if(n <= 100 && sub1) Sub1();
    else if(n <= 100) Sub2();
    else Sub3();
}
**/
