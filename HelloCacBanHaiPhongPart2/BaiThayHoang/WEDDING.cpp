#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 4005
#define INF 1e9
#define Bit(x,i) ((x >> i) & 1)
#define point pair<int,int>
using namespace std;

int n,x[maxn];
bool kt[maxn][maxn];
vector<int> a[maxn];

bool used[maxn];

void dfs(int i)
{
    int u = x[i];
    if(i == n){
        if(kt[u][1] || kt[1][u]) return;
        For(j,1,n) printf("%d ",x[j]);
        exit(0);
    }
    used[u] = true;
    for(int j = 0;j < a[u].size();j++){
        int v = a[u][j];
        if(!used[v]){
            x[i+1] = v;
            dfs(i+1);
        }
    }
    used[u] = false;
}

int main()
{
    freopen("WEDDING.inp","r",stdin);
    freopen("WEDDING.out","w",stdout);
    scanf("%d",&n);
    n *= 2;
    For(i,1,n){
        int m;
        scanf("%d",&m);
        For(k,1,m){
            int j;
            scanf("%d",&j);
            kt[i][j] = true;
        }
    }
    For(i,1,n)
        For(j,1,n) if(i != j && kt[i][j] == 0 && kt[j][i] == 0)
            a[i].push_back(j);
    x[1] = 1;
    dfs(1);
}
