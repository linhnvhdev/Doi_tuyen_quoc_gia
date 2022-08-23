#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 205
#define pii pair<int,int>
#define INF 1e9
#define fi first
#define se second
#define ll long long
using namespace std;

int m,n,parent[maxn];
ll cap[maxn][maxn];
int a[maxn][maxn];

bool bfs(int s,int t)
{
    fill(parent,parent + 1 + n,-1);
    queue<int> q;
    q.push(s);
    parent[s] = s;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        For(i,1,a[u][0]){
            int v = a[u][i];
            if(parent[v] == -1 && cap[u][v] > 0){
                parent[v] = u;
                q.push(v);
            }
        }
    }
    return parent[t] != -1;
}

ll max_flow(int s,int t)
{
    ll max_flow = 0;
    if(s == t) return 0;
    while(bfs(s,t)){
        ll path_flow = 1e18;
        for(int i = t;i != s;i = parent[i])
            path_flow = min(path_flow,cap[parent[i]][i]);

        for(int i = t;i != s;i = parent[i]){
            int j = parent[i];
            cap[j][i] -= path_flow;
            cap[i][j] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
    scanf("%d%d",&m,&n);
    if(m == 0 || n == 0){
        cout << 0 << endl;
        return 0;
    }
    For(i,1,m){
        int u,v,c;
        scanf("%d%d%d",&u,&v,&c);
        a[u][++a[u][0]] = v;
        a[v][++a[v][0]] = u;
        cap[u][v] += 1ll*c;
    }
    cout << max_flow(1,n) << endl;
}
