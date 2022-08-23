#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,root;
vector<int> a[maxn];
int xa1,xa2,curmax1 = 0,ans = 0;

void dfs(int u,int p,int depth)
{
    for(int v : a[u]){
        if(v == p) continue;
        if(depth + 1 > curmax1){
            curmax1 = depth + 1;
            xa1 = v;
        }
        dfs(v,u,depth + 1);
    }
}

void dfs2(int u,int p,int depth)
{
    //cerr << u << ' ' << p << ' ' << depth << endl;
    for(int v : a[u]){
        if(v == p) continue;
        if(depth + 1 > ans)
            ans = depth + 1;
        dfs2(v,u,depth + 1);
    }
}

int main()
{
    freopen("Diameter.inp","r",stdin);
    freopen("Diameter.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n){
        int p;
        scanf("%d",&p);
        if(p == 0){
            root = i;
            continue;
        }
        a[i].push_back(p);
        a[p].push_back(i);
    }
    dfs(root,0,0);
    ans = curmax1;
    //cout << curmax1 << endl;
    dfs2(xa1,0,0);
    cout << ans << endl;
    return 0;
}
