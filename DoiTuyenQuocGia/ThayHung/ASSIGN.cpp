#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >=b ;i--)
#define maxn 100005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

int m,n,p;

vector<int> a[maxn];
int match[maxn],used[maxn];

bool dfs(int u,int cur)
{
    if(used[u] == cur) return false;
    used[u] = cur;
    for(int v : a[u])
        if(!match[v] || dfs(match[v],cur))
        {
            match[v] = u;
            return true;
        }
    return false;
}

int main()
{
    fast_read;
    freopen("ASSIGN.inp","r",stdin);
    freopen("ASSIGN.out","w",stdout);
    cin >> m >> n >> p;
    For(i,1,p)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
    }
    int ans = 0;
    For(i,1,m) ans += dfs(i,i);
    cout << ans << endl;
    For(i,1,n) cout << match[i] <<' ' ;
}
