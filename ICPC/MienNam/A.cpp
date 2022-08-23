#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b; ++i)
#define ll long long
#define maxn 100005
using namespace std;
int n,m,k;
const ll INF = 1e18;
struct Point
{
    ll x,y;
}p[maxn],q[maxn];

typedef Point Vector;
Point A;
long long ans=0;

long double Len(Vector a)
{
    return sqrt(a.x * a.x + a.y * a.y);
}

ll Sqrlen(Vector a)
{
    return a.x * a.x + a.y * a.y;
}

Vector operator +(Vector a,Vector b)
{
    return {a.x + b.x,a.y + b.y};
}

Vector operator -(Vector a,Vector b)
{
    return {a.x - b.x,a.y - b.y};
}

ll operator %(Vector a,Vector b)
{
    return a.x * b.x + a.y * b.y;
}

ll operator * (Vector a , Vector b)
{
    return a.x * b.y - a.y * b.x;
}

void Read()
{
    scanf("%d" , &n);
    A.y = INF;
    For(i,1,n)
    {
        scanf("%lld%lld" , &p[i].x , &p[i].y);
        if(( p[i].y < A.y )|| ( p[i].y == A.y && p[i].x < A.x ) )A = p[i];
    }
}

void GrahamScan()
{
    sort(p + 1 , p + 1 + n, [](Vector B , Vector C)
    {
        Vector u = B - A , v = C - A;
        ll res = u * v;
        return ( res > 0 || ( res == 0 && Sqrlen(u) < Sqrlen(v)));
    });
}

bool CCW (  Vector D ,  Vector E ,  Vector F )
{
    return (E - D) * (F - E) > 0;
}

void FindConvexHull()
{
    m = 0;
    For(i,1,n)
    {
        while(m >=2 && !CCW(q[m - 2],q[m - 1],p[i])) m--;
        q[m] = p[i];
        m++;
    }
}

ll Area(Point A , Point B , Point C)
{
    ll res = (B - A) * (C - A);
    return abs(res);
}

void Solve()
{
    if(m == 3)
    {
        ans = Area(q[0], q[1], q[2]);
        if(ans % 2 == 1) cout << ans/2 << ".5";
        else cout << ans/2 <<".0";
        exit(0);
    }
    q[m] = q[0];
    For(i,0,m-2)
    {
        k = i+2;
        For(j,i+1,m-1)
        {
            while(k <= m && Area(q[i], q[j], q[k]) <= Area(q[i], q[j], q[k+1]))k++;
            ans = max(ans, Area(q[i], q[j], q[k]));
        }
    }
    //cout << ans << endl;
    if(ans % 2 == 1) cout << ans/2 << ".5";
    else cout << ans/2 <<".0";
}

int main()
{
    Read();
    GrahamScan();
    FindConvexHull();
    Solve();
}
