#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define INF 1e9
using namespace std;

int n,color[maxn];
int f[maxn][2];
string s;

vector<int> a[maxn];
int ans = INF;

void dfs(int u,int p)
{
    f[u][0] = (color[u] != 0);
    f[u][1] = (color[u] != 1);
    for(int v : a[u])
    {
        if(v == p) continue;
        dfs(v,u);
        For(i,0,1)
            f[u][i] += min(f[v][i],f[v][1-i]+1);
    }
}

void dfs2(int u,int p)
{
    if(u != 1)
    {
        ll t[2];
        t[0] = f[u][0];
        t[1] = f[u][1];
        For(i,0,1)
        {
            f[u][i] = t[i] + min(f[p][i] - min(t[i],t[1-i]+1),f[p][1-i] - min(t[1-i],t[i]+1) + 1);
            ans = min(ans,f[u][i] + 1);
        }
    }
    for(int v : a[u])
    {
        if(v == p) continue;
        dfs2(v,u);
    }
}

int main()
{
    fast_read;
    cin >> n >> s;
    For(i,1,n) color[i] = s[i-1] - '0';
    For(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    ans = min(f[1][0] + 1,f[1][1] + 1);
    cout << ans << endl;
}
/**
12
000001011100
1 2
1 3
2 4
2 5
2 6
3 7
3 8
6 9
6 10
8 11
8 12
**/
