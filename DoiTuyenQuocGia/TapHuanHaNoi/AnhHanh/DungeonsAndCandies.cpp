#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1005
#define ll long long
#define INF 1e18
using namespace std;

struct edge
{
    int u,v;
    ll cost;
} e[maxn*maxn];

int n,m,K,w,p[maxn],h[maxn];
char c[maxn][15][15];
string s;

vector<int> a[maxn*maxn];

int dif(int k1,int k2)
{
    int dem = 0;
    For(i,1,n)
        For(j,1,m)
            dem += (c[k1][i][j] != c[k2][i][j]);
    return dem;
}

void make_set(int i)
{
    p[i] = i;
    h[i] = 1;
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

bool Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    if(h[x] < h[y]) p[x] = y;
    else
    {
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

bool cmp(edge a,edge b)
{
    return a.cost < b.cost;
}

void dfs(int u,int p)
{
    for(int v : a[u])
    {
        if(v == p) continue;
        cout << v << ' ' << u << endl;
        dfs(v,u);
    }
}

int main()
{
    fast_read;
    cin >> n >> m >> K >> w;
    For(k,1,K)
    {
        For(i,1,n)
        {
            cin >> s;
            For(j,1,m)
                c[k][i][j] = s[j-1];
        }
    }
    int cnt = 0;
    For(i,1,K)
        For(j,i+1,K)
        {
            ll Cost = dif(i,j)*w;
            e[++cnt] = {i,j,Cost};
        }
    For(i,1,K)
        e[++cnt] = {0,i,n*m};
    For(i,0,K) make_set(i);
    sort(e+1,e+1+cnt,cmp);
    ll ans = 0;
    int canh = 0;
    For(i,1,cnt)
        if(Union(e[i].u,e[i].v))
        {
            ans += e[i].cost;
            a[e[i].u].push_back(e[i].v);
            a[e[i].v].push_back(e[i].u);
        }
    cout << ans << endl;
    dfs(0,-1);
}
