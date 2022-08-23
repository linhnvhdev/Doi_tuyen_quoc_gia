#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; i++)
#define Forr(i,a,b) for(int i = a;i >= b; i--)
#define maxn 1005
#define ll long long
using namespace std;

const int dx[4] = {0, -1, 0, 1};
const int dy[4] = {1, 0, -1, 0};

int m, n, k, ans = 0, p[100005], h[100005];
char s[maxn][maxn];
bool block[maxn][maxn][4], visit[maxn][maxn], lead[100005];

int id(int i, int j)
{
    return i * n + j;
}

bool ok(int u, int v)
{
    if(u < 0 || u >= m || v < 0 || v >= n)return false;
    return true;
}

void Make_set(int i)
{
    p[i] = i;
    h[i] = 0;
}

int Find(int i)
{
    while(i != p[i])i = p[i];
    return p[i];
}

int Union(int i, int j)
{
    int x = Find(i), y = Find(j);
    if(x == y)return 0;
    if(h[x] < h[y])p[x] = y;
    else
    {
        p[y] = x;
        if(h[x] == h[y])h[x]++;
    }
    return 1;
}

void dfs(int i, int j)
{
    visit[i][j] = true;
    For(t,0,3)
    {
        if(block[i][j][t])continue;
        int u = i + dx[t], v = j + dy[t];
        if(!ok(u, v) || visit[u][v])continue;
        Union(id(i, j), id(u, v));
        dfs(u, v);
    }
}

int main()
{
    scanf("%d%d%d", &k, &m, &n);
    For(i,0,m - 1)
        For(j,0,n - 1)
            Make_set(id(i, j));
    while(k--)
    {
        For(i,0,m - 1)
            scanf("%s", &s[i]);
        For(i,0,m - 1)
            For(j,0,n - 1)
            {
                if(s[i][j] != '*')continue;
                For(t,0,3)
                {
                    int u = i + dx[t], v = j + dy[t];
                    if(!ok(u, v))continue;
                    if(s[u][v] == '.')
                        block[i][j][t] = block[u][v][(t + 2) % 4] = true;
                }
            }
    }
    For(i,0,m - 1)
        For(j,0,n - 1)
            if(!visit[i][j])
                dfs(i, j);
    For(i,0,m - 1)
        For(j,0, n - 1)
        {
            int r = Find(id(i, j));
            if(!lead[r])ans++;
            lead[r] = true;
        }
    printf("%d",ans);
}
