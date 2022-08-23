#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,q,sz[maxn],st[maxn],ed[maxn],cnt = 0;
int depth[maxn];
int cur = 0,tp[maxn],szmax[maxn];

vector<int> a[maxn];
int root = 1;

void dfs(int u,int p)
{
    tp[++cnt] = u;
    st[u] = cnt;
    sz[u] = 1;
    for(int i = 0;i < a[u].size();i++){
        int v = a[u][i];
        if(v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v,u);
        szmax[u] = max(szmax[u],sz[v]);
        sz[u] += sz[v];
    }
    ed[u] = cnt;
}

int Solve(int u)
{
    int bestd = 1e9,bestv = u;
    For(i,st[u],ed[u]){
        int v = tp[i];
        if(2*(sz[u] - sz[v]) <= sz[u] && 2*szmax[v] <= sz[u]){
            if(bestd > abs(depth[v] - depth[u])){
                bestd = abs(depth[v] - depth[u]);
                bestv = v;
            }
        }
    }
    return bestv;
}

int main()
{
    freopen("Centroid.inp","r",stdin);
    freopen("Centroid.out","w",stdout);
    cin >> n >> q;
    For(i,1,n){
        int p;
        scanf("%d",&p);
        if(p == 0) root = i;
        //if(p == 0) continue;
        a[i].push_back(p);
        a[p].push_back(i);
    }
    dfs(root,0);
    //For(i,1,n) cout << i << ' ' << depth[i] << endl;
    For(i,1,q){
        int u;
        scanf("%d",&u);
        printf("%d ",Solve(u));
    }
}
