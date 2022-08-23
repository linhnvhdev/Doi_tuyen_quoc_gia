#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 105
#define ll long long
#define fi first
#define se second
using namespace std;

const int mod = 1e9+7;
int n,m;

vector<int> a[maxn];
int st[maxn],ed[maxn],cnt = 0,ts[maxn];

int ans = 0;

bool dfs(int u,int p)
{
    for(int v : a[u]){
        if(v == p) continue;
        if(__gcd(ts[u],ts[v]) <= 1) return false;
        if(!dfs(v,u)) return false;
    }
    return true;
}

void duyet(int i)
{
    if(i > n){
        if(dfs(1,0)) ans++;
        return;
    }
    For(j,2,m){
        ts[i] = j;
        duyet(i+1);
    }
}

int main()
{
    freopen("TREEGCD.inp","r",stdin);
    freopen("TREEGCD.out","w",stdout);
    scanf("%d%d",&n,&m);
    For(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    duyet(1);
    cout << ans << endl;
    return 0;
}
