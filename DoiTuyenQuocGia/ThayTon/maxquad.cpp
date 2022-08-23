#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define x first
#define y second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct Point
{
    ll x, y;
} p[maxn], q[maxn];
Point A;
int n, m;
ll Area = 0;

ll Sqrlen(Point a)
{
    return a.x * a.x + a.y * a.y;
}

Point operator + (Point a, Point b)
{
    return {a.x + b.x, a.y + b.y};
}

Point operator - (Point a, Point b)
{
    return {a.x - b.x, a.y - b.y};
}

ll operator * (Point a, Point b)
{
    return a.x * b.y - a.y * b.x;
}
bool CCW (Point D, Point E, Point F)
{
    return (E - D ) * (F - E) > 0;
}

bool operator == (Point a,Point b)
{
    return a.x == b.x && a.y == b.y;
}

void GrahamScan()
{
    sort(p + 1,p + 1 + n,[](Point B, Point C)
    {
        Point u = B - A, v = C - A;
        ll tmp = u * v;
        return ( tmp > 0 || (tmp == 0 && Sqrlen(u) < Sqrlen(v)));
    });
}

void FindConvexHull()
{
    m = 0;
    For(i,1,n)
    {
        while(m >= 2 && !CCW(q[m - 2], q[m - 1], p[i]))m--;
        q[m++] = p[i];
    }
}

ll DreamSquad(int i,int j,int k,int l)
{
    ll cur_ans = 0;
    Point d[5] = {q[i], q[j], q[k], q[l], q[i]};
    For(t,0,3)
        cur_ans += d[t] * d[t + 1];
    return cur_ans;
}

void Solve()
{
    q[m] = q[0];
    For(i,0,m - 3)
        For(j,i+1,m - 2)
        {
            int l = j + 2;
            For(k, j + 1, m - 1)
            {
                while(l <= m && DreamSquad(i, j, k, l) <= DreamSquad(i, j, k, l + 1))l++;
                Area = max(Area, DreamSquad(i, j, k, l));
            }
        }
    cout << Area /2;
    if(Area % 2 == 0)cout << ".000000" << endl;
    else
        cout << ".500000" << endl;
}
int main()
{
    fast_read;
    freopen("maxquad.inp", "r", stdin);
    freopen("maxquad.out", "w", stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> p[i].x >> p[i].y;
        if(p[i].y < A.y || (p[i].y == A.y && p[i].x < A.x))A = p[i];
    }
    GrahamScan();
    FindConvexHull();
    Solve();
}
