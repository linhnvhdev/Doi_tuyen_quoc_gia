#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

bool used[maxn];
int n,m,c[maxn][maxn];
int dp[maxn][maxn];

vector<pii> a[1005];

struct run
{
    int x,y,dir,val;
};

bool check(int x,int y,int u,int v,int k)
{
    For(i,0,m+1)
        For(j,0,n+1) dp[i][j] = 1e9;
    dp[x][y] = 1;
    deque<run> dq;
    For(i,0,3) dq.push_back({x,y,i,1});
    while(!dq.empty())
    {
        run cur = dq.front();
        dq.pop_front();
        if(cur.val > dp[cur.x][cur.y]) continue;
        For(i,0,3)
        {
            int idx = cur.x + dx[i];
            int idy = cur.y + dy[i];
            int add = (i != cur.dir);
            if(idx < 0 || idx > m+1 || idy < 0 || idy > n+1) continue;
            if(idx == u && idy == v)
            {
                dp[idx][idy] = min(dp[idx][idy],cur.val + add);
            }
            if(c[idx][idy] == 0 && cur.val + add <= dp[idx][idy])
            {
                dp[idx][idy] = cur.val + add;
                if(!add) dq.push_front({idx,idy,i,cur.val});
                else dq.push_back({idx,idy,i,cur.val + add});
            }
        }
    }
    return (dp[u][v] <= k);
}

int main()
{
    fast_read;
    freopen("pikachu.inp","r",stdin);
    freopen("pikachu.out","w",stdout);
    cin >> m >> n;
    int cell = 0;
    For(i,1,m)
        For(j,1,n)
        {
            cin >> c[i][j];
            cell += (c[i][j] != 0);
            if(c[i][j] != 0) a[c[i][j]].push_back({i,j});
        }
    For(k,1,100000)
    {
        while(true)
        {
            int des = 0;
            For(i,1,m)
                For(j,1,n)
                {
                    if(c[i][j] == 0) continue;
                    int val = c[i][j];
                    if(a[val].size() % 2 == 1)
                        continue;
                    int x = a[val][0].fi,y = a[val][0].se,u = a[val][1].fi,v = a[val][1].se;
                    if(check(x,y,u,v,k))
                    {
                        des++;
                        c[x][y] = c[u][v] = 0;
                        cell -= 2;
                    }
                }
            if(!des) break;
        }
        if(cell <= 1)
        {
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
