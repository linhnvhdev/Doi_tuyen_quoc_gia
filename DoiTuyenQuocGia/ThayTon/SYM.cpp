#include <bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define point pair<ll,ll>
#define line pair<point,ll>
#define x fi
#define y second
#define lf double
using namespace std;

int n;
point p[maxn];

map<point,int> mp,bg;

point middle(point a,point b)
{
    return {(a.x + b.x)/2,(a.y + b.y)/2};
}

point dx(point a,point M)
{
    return {2*M.x - a.x,2*M.y - a.y};
}

int ans1 = 0,ans2 = 0;

void FirstHalf()
{
    For(i,1,n)
        For(j,i+1,n)
            mp[middle(p[i],p[j])]++;
    pair<point,int> best = {{-1e9,-1e9},0};
    for(auto it : mp) if(it.se > best.se) best = it;
    point M = best.fi;
    For(i,1,n)
    {
        point b = dx(p[i],M);
        if(bg.find(b) == bg.end())
        {
            ans1++;
            bg[b]++;
        }
    }
}

line dtt(point a,point b)
{
    point M = middle(a,b);
    point ab = {b.x - a.x,b.y - a.y};
    ll A = ab.x,B = ab.y,C = -ab.x*M.x - ab.y*M.y;
    if(A < 0 || (A == 0 && B < 0)) A = -A,B = -B,C = -C;
    ll d = __gcd(__gcd(abs(A),abs(B)),abs(C));
    A = A/d;
    B = B/d;
    C = C/d;
    return {{A,B},C};
}

map<line,int> mp2;

int cnt = 0;

point dxt(point a,line d)
{
    ll x0 = a.x,y0 = a.y;
    ll A = d.x.x,B = d.x.y,C = d.y;
    if((A*x0 + B*y0 + C) % (A*A + B*B) != 0) return {1e9,1e9};
    ll X = x0 - 2*A*((A*x0 + B*y0 + C)/(A*A + B*B));
    ll Y = y0 - 2*B*((A*x0 + B*y0 + C)/(A*A + B*B));
    return {X,Y};
}

line dt(point a,point b)
{
    ll A = b.y - a.y;
    ll B = a.x - b.x;
    ll C = b.fi * a.se - a.fi*b.se;
    if(A < 0 || (A == 0 && B < 0)) A = -A,B = -B,C = -C;
    ll d = __gcd(__gcd(abs(A),abs(B)),abs(C));
    A = A/d;
    B = B/d;
    C = C/d;
    return {{A,B},C};
}

void SecondHalf()
{
    bg.clear();
    For(i,1,n) bg[p[i]]++;
    For(i,1,n)
        For(j,i+1,n)
            mp2[dtt(p[i],p[j])]++;
    For(i,1,n)
        For(j,i+1,n)
            mp2[dt(p[i],p[j])]++;
    pair<line,int> best = {{{-1e9,-1e9},-1e9},0};
    for(auto it : mp2)
        if(it.se > best.se) best = it;
    line M = best.fi;
    //cout << M.x.x << ' ' << M.x.y << ' ' << M.y << '\n';
    For(i,1,n)
    {
        point b = dxt(p[i],M);
        if(b.x == 1e9)
        {
            ans2++;
            continue;
        }
        if(bg.find(b) == bg.end())
        {
            ans2++;
            bg[b]++;
        }
    }
}

int main()
{
    fast_read;
    freopen("SYM.inp","r",stdin);
    freopen("SYM.out","w",stdout);
    cin >> n;
    For(i,1,n) cin >> p[i].x >> p[i].y;
    For(i,1,n) p[i].x *= 2, p[i].y *= 2;
    For(i,1,n) bg[p[i]]++;
    FirstHalf();
    SecondHalf();
    cout << ans1 << ' ' << ans2 << endl;
}
