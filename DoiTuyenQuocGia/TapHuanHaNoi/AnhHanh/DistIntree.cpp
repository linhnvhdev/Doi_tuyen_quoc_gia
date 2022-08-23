/**
int getcount(map<int,int> &m,int key)
{
    __typeof(m.begin()) it = m.find(key);
    return it == m.end() ? 0 : it->second
}
map<int,int> *count[maxn]
for(__typeof(m.begin()) it = m.begin();it != m.end();it++)
{
    int l = it-> fi;
    int c = it-> se;
}
dfs(int u)
{
    if(u is leaf)
    {
        count[u] = new map<int,int>();
        count[u][0] = 1;
        return;
    }
    // v1,v2...: con,v1 is max con
    count[u] = count[v1];
    For(i,2,k)
    {
        for(auto <l,c> thuoc *count[vi])
            res += c*(getcount(*count[u],k-l-1));
        for(<l,c> thuoc *count[vi])
            *count[u][l] += c;
    }
}
**/

#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 50005
#define ll long long
#define INF 1e9
using namespace std;

int n,k;

vector<int> a[maxn];
ll f[maxn][505];
ll ans = 0;

void dfs(int u,int p)
{
    for(int v : a[u])
    {
        if(v == p) continue;
        dfs(v,u);
        For(i,0,k-1) ans += f[u][i]*f[v][k-i-1];
        For(i,1,k) f[u][i] += f[v][i-1];
    }
}

int main()
{
    fast_read;
    cin >> n >> k;
    For(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    For(i,1,n) f[i][0] = 1;
    dfs(1,0);
    cout << ans << endl;
}
