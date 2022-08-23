/**
    Xđ các đỉnh nằm trong chu trình và các đỉnh ko nằm trong chu trình
    Xử lí các đỉnh nằm ngoài chu trình trước
        money[next[i]] += cost[i];
        ans += max(cost[i] - money[i],0);
        ct[i] = true;
        i = prv[i];
    Xử lí các nút trong chu trình có hỗ trợ tài chính nhất
        Thực hiện theo thứ tự trên chu trình
**/


#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,m,cost[maxn],Next[maxn],cnt = 0;
vector<int> a[maxn];
vector<pair<ll,int> > b[maxn];
bool ct[maxn];
int used[maxn];
ll ans = 0;
ll money[maxn];
stack<int> stk;

void findct(int u,int cur)
{
    if(ct[u] || used[u]) return;
    stk.push(u);
    used[u] = cur;
    int v = Next[u];
    if(ct[v]) return;
    if(used[v] == cur){
        cnt++;
        while(!stk.empty()){
            int q = stk.top();
            stk.pop();
            b[cnt].push_back({cost[q],q});
            ct[q] = true;
            if(q == v) break;
        }
    }
    else findct(v,cur);
}

bool checkDFS[maxn];

void DFS(int u)
{
    money[Next[u]] += cost[u];
    for(int i = 0;i < a[u].size();i++){
        int v = a[u][i];
        if(!checkDFS[v]) DFS(v);
    }
    ans += max(cost[u] - money[u],0ll);
}

bool check[maxn];

void dfs(int u)
{
    if(check[u]) return;
    check[u] = true;
    ans += max(0ll,cost[u] - money[u]);
    money[Next[u]] += cost[u];
    dfs(Next[u]);
}

int main()
{
    scanf("%d",&n);
    For(i,1,n){
        int u,w;
        scanf("%d%d",&Next[i],&w);
        a[Next[i]].push_back(i);
        cost[i] = w;
    }
    For(i,1,n)
        if(!used[i]){
            while(!stk.empty()) stk.pop();
            findct(i,i);
        }
    For(i,1,n)
        if(!ct[i] && ct[Next[i]])
            DFS(i);
    For(i,1,cnt){
        for(int j = 0;j < b[i].size();j++){
            int u = b[i][j].se;
            b[i][j].fi = cost[u] - money[u];
        }
        sort(b[i].begin(),b[i].end());
    }
    cout << cnt << endl;
    For(i,1,cnt){
        cout <<"## " <<  i << endl;
        for(int j = 0;j < b[i].size();j++) cout << b[i][j].fi << ' ' << b[i][j].se <<endl ;
    }
    For(i,1,cnt)
        dfs(b[i][0].se);
    cout << ans << endl;
}
