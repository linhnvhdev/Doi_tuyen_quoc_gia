/**
    Xet lan luot tung dinh
    Neu den 1 dinh chua dc to mau
    thu mau tu 1->3
    neu color != c[i] thu to dinh i = mau cc
    neu to dc thi break luon
    neu ko to dc thi vo nghiem
**/

#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

const char RGB[3] = {'R','G','B'};
int n,m;
string s;
int color[maxn];
bool c[maxn][maxn];

vector<int> a[maxn];

void End()
{
    cout << "NO\n";
    exit(0);
}

void dfs(int u)
{
    for(int k : a[u])
    {
        if(color[k] == -1) continue;
        if(color[k] == color[u]) End();
        for(int v : a[u])
        {
            if(v == k || !c[v][k]) continue;
            if(color[v] == color[u] || color[v] == color[k]) End();
            if(color[v] == -1)
                For(i,0,2)
                    if(i != color[u] && i != color[k])
                    {
                        if(color[v] == -1)
                        {
                            color[v] = i;
                            dfs(v);
                        }
                        break;
                    }
        }
    }
}

int main()
{
    fast_read;
    freopen("COLOR.inp","r",stdin);
    freopen("COLOR.out","w",stdout);
    memset(color,-1,sizeof(color));
    cin >> n >> m;
    For(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        c[u][v] = c[v][u] = true;
    }
    if(n == 1)
    {
        cout << "YES\nR";
        return 0;
    }
    color[1] = 0;
    color[a[1][0]] = 1;
    dfs(1);
    cout << "YES\n";
    For(i,1,n) cout << RGB[color[i]];
}
