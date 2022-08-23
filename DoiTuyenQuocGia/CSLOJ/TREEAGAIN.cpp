#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define x first
#define y second
#define INF 1e18
#define point pair<ll,ll>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int t,n,q;

point operator - (point u,point v)
{
    return {u.x - v.x,u.y - v.y};
}

double operator * (point u,point v)
{
    return 1.0*u.x*v.y - 1.0*u.y*v.x;
}

double ccw(point a,point b,point c)
{
    return (b-a)*(c-a);
}

point p[maxn],A;

bool check(int i)
{
    return (ccw(p[i],p[(i+1)%n],A) >= 0);
}

int tinh(int st,int ed)
{
    int l = st,r = ed;
    while(r - l > 1)
    {
        int mid = (l+r)/2;
        if(check(mid) == check(st)) l = mid;
        else r = mid;
    }
    int cur = -1;
    cur = (check(r) == check(st)) ? r : l;
    return (check(st)) ? cur - st + 1 : ed - cur;
}

int Solve()
{
    if(check(0) == check(n/2)) return check(0);
    return tinh(0,n/2-1) + tinh(n/2,n-1) > n/2;
}

int main()
{
    fast_read;
    freopen("test.inp","r",stdin);
    freopen("test.out","w",stdout);
    cin >> t >> n;
    For(i,0,n-1) cin >> p[i].x >> p[i].y;
    ll ans = 0;
    cin >> q;
    For(i,1,q)
    {

        cin >> A.x >> A.y;
        A.x ^= (ans*ans*ans*t);
        A.y ^= (ans*ans*ans*t);
        int add = Solve();
        ans += add;
        if(add) cout << "YES\n";
        else cout << "NO\n";
    }
}
