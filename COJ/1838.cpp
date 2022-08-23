/*
    Cứ mỗi bước mình sẽ thêm cạnh vào
    nếu nó tạo thành 1 chu trình thì sẽ loại bỏ cạnh lớn nhất trong chu trình đó đi
*/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 5005
using namespace std;

int n,m;
vector<int> a[maxn];
int b[maxn][maxn],parent[maxn];
bool ok,used[maxn];
pair<int,int> maxc;

void dfs(int u,int goal)
{
    used[u] = true;
    if(u == goal){
        ok = true;
        return;
    }
    for(int i = 0;i < a[u].size();i++){
        int v = a[u][i];
        if(used[v] || b[u][v] == 0 || b[v][u] == 0) continue;
        parent[v] = u;
        dfs(v,goal);
        if(ok) return;
    }
}

int main()
{
    //freopen("1838.inp","r",stdin);
    //freopen("1838.out","w",stdout);
    scanf("%d%d",&n,&m);
    int cnt = 0,cur_ans = 0;
    For(i,1,m){
        memset(used,false,sizeof(used));
        int u,v,c,maxd = 0;
        scanf("%d%d%d",&u,&v,&c);
        ok = false;
        dfs(u,v);
        if(!ok){
            a[u].push_back(v);
            a[v].push_back(u);
            b[u][v] = b[v][u] = c;
            cnt++;
            cur_ans += c;
            if(cnt < n - 1) printf("-1\n");
            else printf("%d\n",cur_ans);
        }
        else{
            int t = v;
            while(t != u){
                if(b[t][parent[t]] > maxd){
                    maxd = b[t][parent[t]];
                    maxc = {t,parent[t]};
                }
                t = parent[t];
            }
            if(maxd > c){
                cur_ans = cur_ans - maxd + c;
                a[u].push_back(v);
                a[v].push_back(u);
                b[maxc.fi][maxc.se] = b[maxc.se][maxc.fi] = 0;
                b[u][v] = b[v][u] = c;
            }
            if(cnt == n - 1)
                printf("%d\n",cur_ans);
            else printf("-1\n");
        }
    }
}
