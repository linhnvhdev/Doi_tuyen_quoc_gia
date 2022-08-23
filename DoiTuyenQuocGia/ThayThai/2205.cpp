#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define pii pair<int,int>
#define fi first
#define se second
#define INF 1e9
using namespace std;

const int dx[4] = {-1,0,0,1};
const int dy[4] = {-1,-2,-1,-1};

int m,n;
char s[maxn];
pii st;

vector<char> a[maxn];

bool check(int i,int j)
{
    if(j > n) j = j - n;
    else if(j <= 0) j = n + j;
    return (i >= 1 && i <= m && a[i][j] != 'M');
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d%d",&m,&n);
    int d[m+5][n+5];
    For(i,1,m)
    {
        scanf("%s",&s);
        a[i].push_back('#');
        For(j,1,n)
        {
            a[i].push_back(s[j-1]);
            if(a[i][j] == 'G') st = {i,j};
        }
    }
    For(i,1,m)
        For(j,0,n+2) d[i][j] = INF;
    d[st.fi][st.se] = 0;
    queue<pair<pii,int> > q;
    q.push({st,0});
    while(!q.empty())
    {
        int u = q.front().fi.fi;
        int v = q.front().fi.se;
        int cur_t = q.front().se;
        q.pop();
        if(cur_t > d[u][v]) continue;
        For(k,0,3)
        {
            int uu = u + dx[k];
            int vv = v + dy[k];
            if(vv <= 0) vv = n + vv;
            if(check(uu,vv) && check(uu,vv+1))
            {
                if(d[u][v] + 1 < d[uu][vv])
                {
                    d[uu][vv] = d[u][v] + 1;
                    q.push({{uu,vv},d[uu][vv]});
                }
            }
        }
    }
    int ans = INF;
    For(i,1,n) ans = min(ans,d[m][i]);
    if(ans == INF) cout << -1 << endl;
    else cout << ans + 1 << endl;
}
