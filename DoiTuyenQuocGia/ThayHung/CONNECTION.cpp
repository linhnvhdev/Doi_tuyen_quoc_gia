#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >=b ;i--)
#define maxn 1000005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

struct answer
{
    char type;
    int u,v;
} ans[maxn];

int m,n,k;

int p[maxn],h[maxn],Pos[1005][1005];

int pos(int i,int j)
{
    return (i-1)*n + j;
}

void make_set(int i)
{
    p[i] = i;
    h[i] = 0;
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

bool Union(int i,int j)
{
    int x = Find(i);
    int y = Find(j);
    if(x == y) return false;
    if(h[x] < h[y]) p[x] = y;
    else
    {
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

char type;
int u,v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CONNECTION.inp","r",stdin);
    freopen("CONNECTION.out","w",stdout);
    cin >> m >> n >> k;
    For(i,1,m)
        For(j,1,n) Pos[i][j] = pos(i,j);
    For(i,1,m*n) make_set(i);
    For(i,1,k)
    {
        cin >> type >> u >> v;
        int uu = (type == 'R') ? u : u + 1;
        int vv = (type == 'R') ? v + 1 : v;
        Union(Pos[u][v],Pos[uu][vv]);
    }
    int cnt = 0;
    For(u,1,m)
        For(v,1,n-1)
        {
            int uu = u, vv = v + 1;
            if(Union(Pos[u][v],Pos[uu][vv]))
                ans[++cnt] = {'R',u,v};
        }
    For(u,1,m-1)
        For(v,1,n)
        {
            int uu = u + 1,vv = v;
            if(Union(Pos[u][v],Pos[uu][vv]))
                ans[++cnt] = {'D',u,v};
        }
    cout << cnt << '\n';
    For(i,1,cnt) cout << ans[i].type << ' ' << ans[i].u << ' ' << ans[i].v << '\n';
}
