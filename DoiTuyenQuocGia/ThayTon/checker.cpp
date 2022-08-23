#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
#define x fi
#define y second
#define lf double
using namespace std;

pair<pair<int,int>,int> e[2*maxn];

int t,n,m;

string s;

int a[2005][2005];
pair<int,int> nxt[maxn];

vector<pair<int,int> > adj[maxn];

bool check_triangle()
{
    For(i,1,m)
        For(j,1,m)
        {
            if(i == j) continue;
            pair<int,int> d1 = e[i].fi,d2 = e[j].fi;
            if(d1 == d2) return false;
            if(d1.fi == d2.fi || d1.fi == d2.se || d1.se == d2.se || d1.se == d2.fi) continue;
            if(d1.fi <= d2.fi && d2.fi <= d1.se && (d2.se < d1.fi || d2.se > d1.se)) return false;
            if(d1.fi <= d2.se && d2.se <= d1.se && (d2.fi < d1.fi || d2.fi > d1.se)) return false;
        }
    return true;
}

void Sub1()
{
    for(int i = 1;i <= n-1;i++)
        a[i][i+1] = a[i+1][i] = s[i-1] - '0';
    a[n][1] = s[n-1] - '0';
    a[1][n] = s[n-1] - '0';
    m = 0;
    For(i,1,n-3)
    {
        int u,v,c;
        cin >> u >> v >> c;
        if(u > v) swap(u,v);
        e[++m] = {{u,v},c};
        a[u][v] = a[v][u] = c;
    }
    if(!check_triangle())
    {
        cout << "neispravna triangulacija\n";
        return;
    }
    int dem = 0;
    For(i,1,n-1) e[++m] = {{i,i+1},a[i][i+1]};
    e[++m] = {{1,n},a[n][1]};
    For(u,1,m)
        For(v,1,m)
        {
            if(e[u].fi.fi != e[v].fi.fi) continue;
            int i = e[u].fi.fi;
            int j = e[u].fi.se;
            int k = e[v].fi.se;
            if(j > k) continue;
            if(a[i][j] && a[j][k] && a[i][k] && !(a[i][j] == a[i][k] || a[i][j] == a[j][k] || a[i][k] == a[j][k]))
                    dem++;
        }
    if(dem == n-2) cout << "tocno\n";
    else cout << "neispravno bojenje\n";
}

int dist(pair<int,int> a)
{
    return (a.se - a.fi + n) % n;
}

bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y)
{
    return dist(x.fi) < dist(y.fi);
}

bool check_color(int a,int b,int c)
{
    return (a + b + c == 6);
}

void Sub3()
{
    For(i,1,n-1) nxt[i] = {i+1,s[i-1] - '0'};
    nxt[n] = {1,s[n-1] - '0'};
    m = 0;
    For(i,1,n-3)
    {
        int u,v,c;
        cin >> u >> v >> c;
        e[++m] = {{u,v},c};
        e[++m] = {{v,u},c};
    }
    sort(e+1,e+1+m,cmp);
    For(i,1,n-2)
    {
        int a = e[i].fi.fi;
        int b = nxt[a].fi;
        int c = e[i].fi.se;
        if(nxt[b].fi != c)
        {
            cout << "neispravna triangulacija\n";
            exit(0);
        }
        if(!check_color(nxt[a].se,nxt[b].se,e[i].se))
        {
            cout << "neispravno bojenje\n";
            exit(0);
        }
        nxt[a] = {c,e[i].se};
    }
    cout << "tocno\n";
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("checker.inp","r",stdin);
    freopen("checker.out","w",stdout);
    cin >> t >> n >> s;
//    if(n <= 2000) Sub1();
//    else
        Sub3();
}
