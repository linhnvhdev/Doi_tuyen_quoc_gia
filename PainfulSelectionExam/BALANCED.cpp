#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,q,p[3][maxn],h[3][maxn];
int tp[3];
vector<int> a[3][maxn];
ll gt1[3][maxn],gt2[3][maxn];
bool used[maxn];
queue<int> qu;

void Make_set(int k,int i)
{
    p[k][i] = i;
    h[k][i] = 0;
    gt1[k][i] = i;
    gt2[k][i] = 1ll*i*i;
}

int Find(int k,int i)
{
    while(i != p[k][i]) i = p[k][i];
    return i;
}

bool Union(int k,int i,int j)
{
    int x = Find(k,i);
    int y = Find(k,j);
    if(x == y) return false;
    if(h[k][x] < h[k][y]){
        p[k][x] = y;
        gt1[k][y] += gt1[k][x];
        gt2[k][y] += gt2[k][x];
    }
    else{
        gt1[k][x] += gt1[k][y];
        gt2[k][x] += gt2[k][y];
        p[k][y] = x;
        if(h[k][x] == h[k][y]) h[k][x]++;
    }
    return true;
}

bool check(int tv)
{
    if(tp[1] != tp[2]) return false;
    while(!qu.empty()){
        int t = qu.front();
        int u = Find(1,t),v = Find(2,t);
        if(gt1[1][u] != gt1[2][v] || gt2[1][u] != gt2[2][v])
            return false;
        qu.pop();
    }
    return true;
}

int main()
{
    //freopen("BALANCED.inp","r",stdin);
    //freopen("BALANCED.out","w",stdout);
    scanf("%d%d",&n,&q);
    tp[1] = tp[2] = n;
    For(i,1,n)
        For(j,1,2) Make_set(j,i);
    int pre = 0;
    For(i,1,q){
        int k,u,v;
        scanf("%d%d%d",&k,&u,&v);
        if(!used[u]){
            qu.push(u);
            used[u] = true;
        }
        if(!used[v]){
            qu.push(v);
            used[v] = true;
        }
        if(Union(k,u,v)){
            tp[k]--;
            pre = check(i);
        }
        if(pre) printf("Yes\n");
        else printf("No\n");
    }
}
