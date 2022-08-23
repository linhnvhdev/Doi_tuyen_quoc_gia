#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
#define x fi
#define y second
#define lf double
using namespace std;

ll x,y;

typedef pair<ll,ll> point;

point p[maxn];

point operator - (point a,point b)
{
    return point(a.x - b.x,a.y - b.y);
}

double operator * (point a,point b)
{
    return (double) a.x*b.y - (double) a.y*b.x;
}

int t,n,q;

int ccw(point a,point b,point c)
{
    double s = (b-a)*(c-a);
    if(s > 0) return 1;
    if(s == 0) return 0;
    return -1;
}

bool OK(int i)
{
    return (ccw(p[i],p[(i+1)%n],point(x,y)) >= 0);
}

int get(int st,int ed)
{
    int l = st,r = ed;
    while(r - l > 1)
    {
        int mid = (l+r)/2;
        if(OK(mid) == OK(st)) l = mid;
        else r = mid;
    }
    int res;
    if(OK(st) == OK(r)) res = r - st + 1;
    else res = l - st + 1;
    if(!OK(st)) res = n/2 - res;
    return res;
}

bool Solve()
{
    if(OK(0) == OK(n/2)) return OK(0);
    return get(0,n/2-1) + get(n/2,n-1) > n/2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("zvijezda.inp","r",stdin);
    freopen("zvijezda.out","w",stdout);
    cin >> t >> n;
    For(i,0,n-1) cin >> p[i].x >> p[i].y;
    ll ans = 0;
    cin >> q;
    For(i,1,q)
    {
        cin >> x >> y;
        x ^= ans*ans*ans*t;
        y ^= ans*ans*ans*t;
        int cur = Solve();
        ans += cur;
        if(cur == 0) cout << "NE\n";
        else cout << "DA\n";
    }
}
