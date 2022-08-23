#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 2005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct point
{
    double x,y,z;
} p[maxn],gs;

pair<point,double> C[maxn];

point operator - (point a,point b)
{
    return {a.x - b.x,a.y - b.y,a.z - b.z};
}

double len(point a,point b)
{
    point c = a - b;
    return sqrt(c.x*c.x + c.y*c.y + c.z*c.z);
}

int m,n,k;

bool sub1 = true,sub2 = true;

ll suml[maxn],sumr[maxn],e[maxn];

bool check(double x1,double x2,double x,double r)
{
    return (x + r < x1 || x - r > x2 || (x - r <= x1 && x + r >= x2));
}

void Sub1()
{
    vector<pair<double,double> > l,r;
    For(i,1,n)
    {
        if(p[i].x < gs.x) l.push_back({p[i].x,e[i]});
        else r.push_back({p[i].x,e[i]});
    }
    sort(l.begin(),l.end());
    sort(r.begin(),r.end());
    int N = l.size(),M = r.size();
    Forr(i,N-1,0)
        suml[i] = suml[i+1] + l[i].se;
    For(i,0,M-1)
        sumr[i] = (i == 0) ? r[i].se : sumr[i-1] + r[i].se;
    ll ans = 0;
    Forr(i,N-1,-1)
        For(j,-1,M-1)
        {
            if(i == -1 && j == -1) continue;
            double x1 = (i == -1) ? gs.x : l[i].fi;
            double x2 = (j == -1) ? gs.x : r[j].fi;
            int del = 0;
            For(k,1,m)
                if(!check(x1,x2,C[k].fi.x,C[k].se))
                    del++;
            if(del <= k)
            {
                ll t1 = (i == -1) ? 0 : suml[i];
                ll t2 = (j == -1) ? 0 : sumr[j];
                ans = max(ans,t1 + t2);
            }
            //cout << x1 << ' ' << x2 << ' ' << ans << endl;
        }
    cout << ans << endl;
}

int main()
{
    fast_read;
    freopen("TEAWORLD.inp","r", stdin);
    freopen("TEAWORLD.out","w", stdout);
    cin >> m >> n >> k;
    For(i,1,m)
    {
        cin >> C[i].fi.x >> C[i].fi.y >> C[i].fi.z >> C[i].se;
        if(C[i].fi.y != 0 || C[i].fi.z != 0) sub1 = false;
        if(C[i].fi.z != 0) sub2 = false;
    }
    For(i,1,n) cin >> p[i].x >> p[i].y >> p[i].z >> e[i];
    cin >> gs.x >> gs.y >> gs.z;
    Sub1();
}
