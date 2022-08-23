#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 1005
#define INF 1e9
using namespace std;

int m,n,cnt = 0,a[maxn][maxn],p[maxn*maxn],h[maxn*maxn],cs[maxn][maxn];
int t[100005],T,ans[100005];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool used[maxn][maxn];

void Make_set(int i)
{
    p[i] = i;
    h[i] = 0;
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

bool Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    if(h[x] < h[y]) p[x] = y;
    else{
        p[y] = x;
        if(h[y] == h[x]) h[x]++;
    }
    return true;
}

struct island{
    int id,x,y,hi;
} g[maxn*maxn];

bool cmp(island p,island q)
{
    return p.hi > q.hi;
}

int main()
{
    scanf("%d%d",&m,&n);
    For(i,1,m)
        For(j,1,n){
            int c;
            scanf("%d",&c);
            g[++cnt] = {cnt,i,j,c};

        }
    sort(g + 1,g + 1 + cnt,cmp);
    For(i,1,cnt)
        cs[g[i].x][g[i].y] = i;
    scanf("%d",&T);
    For(i,1,T) scanf("%d",&t[i]);
    int cur_block = 0,vt = 1;
    For(i,1,cnt) Make_set(i);
//    For(i,1,cnt) cout << g[i].x << ' ' << g[i].y << ' ' << g[i].hi << endl;
//    For(i,1,m)
//        For(j,1,n) cout << " ^^ " << i << ' ' << j << ' ' << cs[i][j] << endl;
    Forr(i,T,1){
        while(vt <= cnt && g[vt].hi > t[i]){
            cur_block++;
            For(k,0,3){
                int xx = g[vt].x + dx[k];
                int yy = g[vt].y + dy[k];
                if(xx < 1 || xx > m || yy < 1 || yy > n) continue;
                if(used[xx][yy])
                    if(Union(vt,cs[xx][yy])) cur_block--;
            }
            used[g[vt].x][g[vt].y] = true;
            vt++;
        }
        ans[i] = cur_block;
    }
    For(i,1,T-1) printf("%d ",ans[i]);
    printf("%d\n",ans[T]);
}
