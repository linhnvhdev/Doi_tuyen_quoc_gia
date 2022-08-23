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
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

const char RGB[3] = {'R','G','B'};
int n,m;
string s;
int color[maxn],c[maxn];

vector<int> a[maxn], cur;

bool dfs(int u,int cur_color)
{
    c[u] = cur_color;
    cur.push_back(u);
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i];
        if(c[u] == c[v]) return false;
        if(!(c[v] == -1 && cur_color != color[v])) continue;
        bool ok = false;
        For(j,0,2)
            if(j != cur_color && j != color[v] && dfs(v,j))
                if(dfs(v,j))
                {
                    ok = true;
                    break;
                }
        if(!ok) return false;
    }
    return true;
}

int main()
{
    fast_read;
    freopen("COLOR3.inp","r",stdin);
    freopen("COLOR3.out","w",stdout);
    memset(c,-1,sizeof(c));
    cin >> n >> m >> s;
    For(i,0,n-1)
    {
        if(s[i] == 'R') color[i+1] = 0;
        if(s[i] == 'G') color[i+1] = 1;
        if(s[i] == 'B') color[i+1] = 2;
    }
    For(i,1,m)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    For(i,1,n)
    {
        if(c[i] == -1)
        {
            cur.clear();
            bool ok = false;
            For(j,0,2)
            {
                cur.clear();
                if(j != color[i] && dfs(i,j))
                {
                    ok = true;
                    break;
                }
                for(int v : cur) c[v] = -1;
            }
            if(!ok)
            {
                cout << "Impossible\n";
                return 0;
            }
        }
    }
    For(i,1,n)
        cout <<RGB[c[i]];
    return 0;
}
