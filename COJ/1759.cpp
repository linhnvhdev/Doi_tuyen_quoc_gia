#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define MAXN 100001
using namespace std;

int n,m, cnt = 0,scc = 0;
int low[MAXN],number[MAXN];
vector<int> a[MAXN];
stack<int> stk;
bool unavail[MAXN];

void dfs(int u)
{
    //cout<<u<<' '<<"HIHI"<<endl;
    number[u] = ++cnt;
    low[u] = cnt;
    stk.push(u);
    for(int i = 0;i < a[u].size();i++){
        int v = a[u][i];
        //cout<<u<<' '<<v<<endl;
        if(unavail[v]) continue;
        if(number[v]==0){
            dfs(v);
            low[u] = min(low[u],low[v]);
        }
        else low[u] = min(low[u],number[v]);
    }
    if(low[u] == number[u]){
        scc++;
        cout << " ########### " << scc << endl;
        while(true){
            int v = stk.top();
            stk.pop();
            unavail[v] = true;
            cout << v << ' ' ;
            if(v==u) break;
        }
        cout << endl;
    }
}

int main()
{
    memset(unavail,false,sizeof(unavail));
    scanf("%d%d",&n,&m);
    For(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    For(i,1,n)
        if(number[i]==0) dfs(i);
    printf("%d\n",scc);
}
