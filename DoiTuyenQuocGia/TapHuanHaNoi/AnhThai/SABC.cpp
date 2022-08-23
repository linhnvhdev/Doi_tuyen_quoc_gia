#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 300005
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int n,m,in[maxn],out[maxn],nhan[maxn];
string s;

vector<pii> a[maxn],b[maxn];

int ans[maxn];

void dfs(int u,int cur)
{
    nhan[u] = cur;
    Forv(i,a[u])
    {
        int v = a[u][i].fi;
        int w = a[u][i].se;
        if(nhan[u] + w > nhan[v])
            dfs(v,nhan[u] + w);
    }
}

void dfs2(int u,int cur,int p)
{
    if(nhan[u] < cur) return;
    ans[u] = cur;
    Forv(i,b[u])
    {
        int v = b[u][i].fi;
        int w = b[u][i].se;
        if(v == p) continue;
        if(ans[v] == -1) dfs2(v,cur - w,u);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SABC.inp","r",stdin);
    freopen("SABC.out","w",stdout);
    cin >> n >> m;
    For(i,0,n+1) nhan[i] = ans[i] = -1;
    For(i,1,m)
    {
        int u,v;
        char c;
        cin >> u >> c >> v;
        if(c == '=')
        {
            a[u].push_back({v,0});
            a[v].push_back({u,0});
            b[v].push_back({u,0});
            b[u].push_back({v,0});
        }
        else
        {
            if(c == '>') swap(u,v);
            a[u].push_back({v,1});
            in[v]++;
            out[u]++;
            b[v].push_back({u,1});
        }
    }
    For(i,1,n)
        if(nhan[i] == -1 && in[i] == 0)
            dfs(i,0);

    For(i,1,n)
        if(nhan[i] == 2 && ans[i] == -1)
            dfs2(i,2,0);
    For(i,1,n)
    {
        if(ans[i] == -1) cout <<'?';
        else cout << char('A' + ans[i]);
    }
    return 0;
}
