#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 10004
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

const int limit = 1001;
const int minx = -limit;
const int miny = -limit;
const int maxx = limit;
const int maxy = limit;
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,1,-1};

int n;
ll S;
pii p[maxn];

bool used[3005][3005];

ll d[3005][3005];

ll count_step_goc(ll st)
{
    if(st == INF) return 0;
    ll step = max(S - st,0ll);
    return (step+1)*(step+2)/2 - 1;
}

int main()
{
    fast_read;
    freopen("ANT.inp","r",stdin);
    freopen("ANT.out","w",stdout);
    cin >> n >> S;
    For(i,minx,maxx)
        For(j,miny,maxy)
            d[i+limit][j+limit] = INF;
    For(i,1,n)
    {
        cin >> p[i].fi >> p[i].se;
        used[p[i].fi+limit][p[i].se+limit] = true;
    }
    ll ans = 0;
    queue<pair<pii,int> > q;
    q.push({{0,0},0});
    used[limit][limit] = true;
    while(!q.empty())
    {
        int x = q.front().fi.fi;
        int y = q.front().fi.se;
        int step = q.front().se;
        q.pop();
        //debug3(x,y,step);
        ans++;
        d[x+limit][y+limit] = step;
        if(step == S) continue;
        For(i,0,3)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            //debug3(xx,yy,used[xx+limit][yy+limit]);
            if(xx < minx || xx > maxx || yy < miny || yy > maxy || used[xx+limit][yy+limit]) continue;
            used[xx+limit][yy+limit] = true;
            //cerr << " < " ; debug2(xx,yy);
            q.push({{xx,yy},step+1});
        }
    }
    For(i,miny+1+limit,maxy-1+limit)
    {
        ll t1 = max(S - d[minx+limit][i],0ll);
        ll t2 = max(S - d[maxx+limit][i],0ll);
        ans += t1 + t2;
    }
    For(i,minx+1+limit,maxx-1+limit)
    {
        ll t1 = max(S - d[i][miny+limit],0ll);
        ll t2 = max(S - d[i][maxy+limit],0ll);
        ans += t1+t2;
    }
    ans += count_step_goc(d[0][0]);
    ans += count_step_goc(d[0][2*limit]);
    ans += count_step_goc(d[2*limit][0]);
    ans += count_step_goc(d[2*limit][2*limit]);
    cout << ans << endl;
}
