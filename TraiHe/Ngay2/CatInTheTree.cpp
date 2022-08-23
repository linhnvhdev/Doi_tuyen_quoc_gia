#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define fi first
#define se second
using namespace std;

int n,D,p[maxn];
vector<int> a[maxn];
vector<int> d[maxn];
int depth[maxn];
bool used[maxn];

void rmv(int u,int dis,int parent = -1)
{
    used[u] = true;
    if(dis <= 1) return;
    for(int v:a[u]){
        if(v == parent) continue;
        rmv(v,dis - 1,u);
    }
}

int main()
{
    memset(used,false,sizeof(used));
    scanf("%d%d",&n,&D);
    d[0].push_back(0);
    For(i,1,n-1){
        scanf("%d",&p[i]);
        depth[i] = depth[p[i]] + 1;
        d[depth[i]].push_back(i);
        a[i].push_back(p[i]);
        a[p[i]].push_back(i);
    }
    int ans = 0;
    Forr(i,n-1,0){
        for(int v:d[i]){
            if(used[v]) continue;
            ans++;
            rmv(v,D);
        }
    }
    cout << ans << endl;
}
