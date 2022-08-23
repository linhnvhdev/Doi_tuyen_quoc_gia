#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<ll,ll>
using namespace std;

const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};

ll n,x,y,S;
char s[maxn];
char a[maxn][maxn];

int f[maxn][maxn][4];

bool check(int i,int j)
{
    return(i < 1 || i > n || j < 1 || j > n || a[i][j] != '#');
}

void bfs()
{
    queue<pair<pii,int> > q;
    q.push({{y,x},0});
    int step = 0;
    while(!q.empty()){
        int curx = q.front().fi.fi;
        int cury = q.front().fi.se;
        int cur_m = q.front().se;
        //cerr << curx << ' ' << cury << ' ' << cur_m << ' ' << step << endl;
        if(step == S){
            cout << cury << ' ' << curx << endl;
            return;
        }
        q.pop();
        bool ok = false;
        For(k,0,3){
            int nxt_m = (cur_m + k) % 4;
            int nxtx = curx + dx[nxt_m];
            int nxty = cury + dy[nxt_m];
            //cerr << "@ " << nxt_m << ' ' << nxtx << ' ' << nxty << ' ' << check(nxtx,nxty) << endl;
            if(check(nxtx,nxty)){
                step++;
                ok = true;
                q.push({{nxtx,nxty},nxt_m});
                break;
            }
        }
        if(!ok){
            cout << cury << ' ' << curx << endl;
            return;
        }
    }
}

bool checkout(int i,int j,int dir)
{
    if(i < 1 && dir == 0) return true;
    if(j < 1 && dir == 1) return true;
    if(i > n && dir == 2) return true;
    if(j > n && dir == 3) return true;
    return false;
}

pii AC()
{
    if(x < 1 || x > n || y < 1)
        return {x + dy[0]*S,y + dx[0]*S};
    if(y > n){
        int t = min(y - n,S);
        S -= t;
        y = y - t;
        if(y == n && a[y][x] == '#'){
            y = n+1;
            //cerr << x << ' ' << y << ' ' << S << endl;
            S++;
            return{x + S*dy[1],y + S*dx[1]};
        }
    }
    if(S <= 0) return {y,x};
    queue<pair<pii,ll> > q;
    q.push({{y,x},0});
    int step = 0;
    bool lapisdone = false;
    //cerr << "######## " << S <<' ' << y << ' ' << x << " ###### " << endl;
    while(!q.empty()){
        int curx = q.front().fi.fi;
        int cury = q.front().fi.se;
        int cur_m = q.front().se;
        //cerr << step << ' ' << curx << ' ' << cury << ' ' << cur_m << endl;
        if(checkout(curx,cury,cur_m)){
            S -= step;
            curx = curx + S*dx[cur_m];
            cury = cury + S*dy[cur_m];
            return {cury,curx};
        }
        q.pop();
        if(step == S) return {cury,curx};
        bool ok = false;
        For(k,0,3){
            int nxt_m = (cur_m + k) % 4;
            int nxtx = curx + dx[nxt_m];
            int nxty = cury + dy[nxt_m];
            //cerr <<"$$ "<< nxtx << ' ' << nxty << ' ' << nxt_m << ' ' << check(nxtx,nxty) << endl;
            if(!f[curx][cury][cur_m]) f[curx][cury][cur_m] = step;
            if(check(nxtx,nxty)){
                ok = true;
                if(!lapisdone && f[curx][cury][nxt_m] > 0 && f[curx][cury][nxt_m] != step){
                    lapisdone = true;
                    //cerr << step << ' ' << f[curx][cury][nxt_m] << endl;
                    S = step + (S - step) % (step - f[curx][cury][nxt_m]);
                    if(step == S) return {y,x};
                }
                step++;
                q.push({{nxtx,nxty},nxt_m});
                break;
            }
        }
        if(!ok) return {cury,curx};
    }
}

int main()
{
    freopen("ROBOT.inp","r",stdin);
    freopen("ROBOT.out","w",stdout);
    cin >> n >> x >> y >> S;
    For(i,1,n){
        scanf("%s",&s);
        For(j,1,n)
            a[i][j] = s[j-1];
    }
    if(S <= 100000){
        bfs();
        exit(0);
    }
    pii ans = AC();
    cout << ans.fi << ' ' << ans.se << endl;
}
