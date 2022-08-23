#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 300
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n,m,x[maxn],b[maxn][maxn];
ll k;
pair<int,int> e[maxn];

ll ans = 0;

bool used[maxn];

bool check()
{
    For(i,1,m)
        if(x[e[i].fi] > x[e[i].se]) return false;
    return true;
}

void duyet(int i)
{
    if(i > n)
    {
        if(check()) ans++;
        if(ans == k)
        {
            For(j,1,n) cout << x[j] << ' ';
            exit(0);
        }
        return;
    }
    For(j,1,n)
    {
        if(used[j]) continue;
        x[i] = j;
        used[j] = true;
        duyet(i+1);
        used[j] = false;
    }
}

ll fact[maxn];

void Sub2(ll k)
{
    fact[0] = 1;
    For(i,1,20) fact[i] = fact[i-1]*i;
    if(k > fact[n])
    {
        cout << "poor professor\n";
        return;
    }
    For(i,1,n)
    {
        ll d = k/fact[n-i];
        if(k % fact[n-i] == 0) d--;
        k = k - d*(fact[n-i]);
        d++;
        int dem = 0;
        For(j,1,n)
            if(!used[j])
            {
                dem++;
                if(dem == d) {x[i] = j; used[j] = true; break;}
            }
    }
    For(i,1,n) cout << x[i] << ' ';
    cout << endl;
}

vector<int> head,adj[maxn],edge[maxn];

int in[maxn],out[maxn],nhan[maxn];

bool color[maxn];

void dfs(int u)
{
    //cout << " ## " << u << endl;
    used[u] = true;
    for(int v : edge[u])
    {
        if(used[v]) continue;
        dfs(v);
    }
    For(i,1,n)
        if(!color[i])
        {
            x[u] = i;
            color[i] = true;
            break;
        }
    //cout << u << ' ' << x[u] << endl;
}

void sub3()
{
    For(i,1,m)
    {
        adj[e[i].fi].push_back(e[i].se);
        edge[e[i].se].push_back(e[i].fi);
        in[e[i].se]++;
    }
    For(i,1,n) sort(edge[i].begin(),edge[i].end());
    For(i,1,n)
        if(x[i] == 0)
        {
            dfs(i);
        }
    For(i,1,n) cout << x[i] << ' ';
}

int main()
{
    fast_read;
    freopen("CHOCOLATE.inp","r",stdin);
    freopen("CHOCOLATE.out","w",stdout);
    cin >> n >> k >> m;
    For(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        e[i] = {u,v};
        b[u][v] = 1;
    }
    if(n <= 8)
    {
        duyet(1);
        cout << "poor professor\n";
    }
    else if(m == 0) Sub2(k);
    else
        if(k == 1) sub3();
}
