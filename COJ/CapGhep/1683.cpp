#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 205
#define pii pair<int,int>
#define INF 1e9
#define fi first
#define se second
using namespace std;

int n,m,t = 0;
vector<int> a[maxn];
int used[maxn],Assign[maxn];
bool visit[maxn];

bool dfs(int u)
{
    if(visit[u] == t) return false;
    visit[u] = true;
    for(int v : a[u])
        if(!Assign[v] || dfs(Assign[v])){
            Assign[v] = u;
            return true;
        }
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    For(u,1,n){
        scanf("%d",&s);
        For(j,1,s){
            int v;
            scanf("%d",&v);
            a[u].push_back(v);
            //a[v].push_back(u);
        }
    }
    int ans = 0;
    For(i,1,m){
        t = i;
        ans += dfs(i);
    }
    cout << ans << endl;
}
