#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
using namespace std;

int n,m,ans = 0,low[maxn],number[maxn],cnt = 0;
vector<int> a[maxn];
stack<int> stk;
bool avail[maxn];

void dfs(int u)
{
    low[u] = number[u] = ++cnt;
    stk.push(u);
    for(int v : a[u]){
        if(avail[v]) continue;
        if(!number[v]){
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],number[v]);
    }
    if(low[u] == number[u]){
        ans++;
        while(!stk.empty()){
            int v = stk.top();
            stk.pop();
            avail[v] = true;
            //cout << "## " << ans << ' ' << v << endl;
            if(v == u) break;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    For(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        //a[v].push_back(u);
    }
    For(i,1,n)
        if(!number[i]) dfs(i);
    cout << ans << endl;
}
