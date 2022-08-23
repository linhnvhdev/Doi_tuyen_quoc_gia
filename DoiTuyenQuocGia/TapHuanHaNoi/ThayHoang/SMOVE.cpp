#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 10005
#define ll long long
#define point pair<ll,ll>
#define x first
#define y second
using namespace std;

point p[5];

ll operator * (point u,point v)
{
    return (u.x*v.y - u.y*v.x);
}

point operator - (point u,point v)
{
    return point(u.x - v.x,u.y - v.y);
}

double len(point u,point v)
{
    point AB = v - u;
    return sqrt(1.0*AB.x*AB.x + 1.0*AB.y*AB.y);
}

int ccw(point A,point B,point C)
{
    ll s = (B-A)*(C-A);
    if(s < 0) return -1;
    if(s > 0) return 1;
    return 0;
}

bool check(point A,point B,point C,point D)
{
    if(ccw(A,B,C)* ccw(A,B,D) < 0 && ccw(C,D,A) * ccw(C,D,B) < 0) return true;
    return false;
}

double Solve()
{
    if(check(p[1],p[2],p[3],p[4])) return min(len(p[3],p[1]) + len(p[1],p[4]),len(p[3],p[2]) + len(p[2],p[4]));
    return len(p[3],p[4]);
}

int main()
{
    freopen("SMOVE.inp","r",stdin);
    freopen("SMOVE.out","w",stdout);
    For(i,1,4) scanf("%lld%lld",&p[i].x,&p[i].y);
    cout << fixed << setprecision(4) << Solve();
}
