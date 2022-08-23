#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
using namespace std;

int n,m,scc = 0,ans = 0,low[maxn],number[maxn],cnt = 0;
vector<int> a[maxn],b[maxn];
stack<int> stk;
int nhan[maxn];

void dfs(int u)
{
    low[u] = number[u] = ++cnt;
    stk.push(u);
    for(int v : a[u]){
        if(nhan[v]) continue;
        if(!number[v]){
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],number[v]);
    }
    if(low[u] == number[u]){
        scc++;
        while(!stk.empty()){
            int v = stk.top();
            stk.pop();
            nhan[v] = scc;
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
    }
    For(i,1,n) if(!number[i]) dfs(i);
    For(u,1,n)
        for(int v : a[u]) if(nhan[u] != nhan[v]) b[nhan[u]].push_back(nhan[v]);
    Forr(u,scc,2){
        bool ok = false;
        for(int v : b[u]){
            if(v == u-1){
                ok = true;
                break;
            }
        }
        if(!ok){
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}
