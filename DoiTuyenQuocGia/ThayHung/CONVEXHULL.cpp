#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >=b ;i--)
#define maxn 100005
#define pii pair<ll,ll>
#define x first
#define y second
#define ll long long
#define INF 1e18
using namespace std;

typedef pii point;

point operator - (point u,point v)
{
    return point(u.x - v.x,u.y - v.y);
}

ll operator * (point u,point v)
{
    return u.x*v.y - u.y*v.x;
}

point p[maxn],A = {INF,INF};

int n;

bool ccw(point a,point b,point c)
{
    return (b-a)*(c-a) > 0;
}

ll Len(point u)
{
    return u.x*u.x + u.y*u.y;
}

bool cmp(point B,point C)
{
    point u = B - A, v = C - A;
    ll tmp = u*v;
    return (tmp > 0 || tmp == 0 && (Len(u) < Len(v)));
}

point q[maxn];

void ConvexHull()
{
    sort(p+1,p+1+n,cmp);
    //For(i,1,n) cout << p[i].x << ' ' << p[i].y << endl;
    int m = 0;
    For(i,1,n)
    {
        while(m >= 2 && !ccw(q[m-1],q[m],p[i])) m--;
        q[++m] = p[i];
    }
    q[m+1] = q[1];
    ll ans = 0;
    cout << m << endl;
    For(i,1,m) ans += q[i]*q[i+1];
    if(ans % 2 == 0) cout << ans/2 << ".0\n";
    else cout << ans/2 << ".5\n";
    For(i,1,m)
        cout << q[i].x << ' ' << q[i].y << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CONVEXHULL.inp","r",stdin);
    freopen("CONVEXHULL.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> p[i].x >> p[i].y;
        if(p[i].y < A.y || (p[i].y == A.y && p[i].y < A.y))
            A = p[i];
    }
    ConvexHull();
}
