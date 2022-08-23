#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b; i--)
#define maxn 100005
#define ll long long
#define plli pair<long long, int>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

struct point{
    ll x,y,z,id;
} d[maxn];

pair<point,point> p[maxn];

ll a,b,c,m;

bool check(point u,point v,point uu,point vv)
{
    ll X1 = u.x;
    ll Y1 = u.y;
    ll Z1 = u.z;
    ll XX1 = v.x;
    ll YY1 = v.y;
    ll ZZ1 = v.z;
    if(X1 > XX1) swap(X1,XX1);
    if(Y1 > YY1) swap(Y1,YY1);
    if(Z1 > ZZ1) swap(Z1,ZZ1);
    ll X2 = uu.x;
    ll Y2 = uu.y;
    ll Z2 = uu.z;
    ll XX2 = vv.x;
    ll YY2 = vv.y;
    ll ZZ2 = vv.z;
    if(X2 > XX2) swap(X2,XX2);
    if(Y2 > YY2) swap(Y2,YY2);
    if(Z2 > ZZ2) swap(Z2,ZZ2);
    if(XX1 < X2  || XX2 < X1) return false;
    if(YY1 < Y2  || YY2 < Y1) return false;
    if(ZZ1 < Z2  || ZZ2 < Z1) return false;
    return true;
}

bool Checkchoco(point u,point v,point k)
{
    ll X1 = u.x;
    ll Y1 = u.y;
    ll Z1 = u.z;
    ll XX1 = v.x;
    ll YY1 = v.y;
    ll ZZ1 = v.z;
    if(X1 > XX1) swap (X1,XX1);
    if(Y1 > YY1) swap (Y1,YY1);
    if(Z1 > ZZ1) swap (Z1,ZZ1);
    if(k.x > XX1 || k.x < X1) return false;
    if(k.y > YY1 || k.y < Y1) return false;
    if(k.z > ZZ1 || k.z < Z1) return false;
    return true;
}

int main()
{
    while(cin >> a)
    {
        if(a == -1) break;
        scanf("%d%d%d",&b,&c,&m) ;
        For(i,1,m) scanf("%lld%lld%lld",&d[i].x,&d[i].y,&d[i].z);
        ll V = a*b*c;
        ll sumv = 0;
        bool no  = false;
        For(i,1,m){
            scanf("%lld%lld%lld%lld%lld%lld",&p[i].fi.x ,& p[i].fi.y ,& p[i].fi.z ,& p[i].se.x ,&p[i].se.y ,& p[i].se.z);
            if(
               p[i].fi.x > a ||
               p[i].fi.x > p[i].se.x ||
               p[i].fi.y > b ||
               p[i].fi.y > p[i].se.y ||
               p[i].fi.z > c ||
               p[i].fi.z > p[i].se.z ||
               p[i].se.x > a ||
               p[i].se.y > b ||
               p[i].se.z > c
               ) {
                    no = true ;
               }
            sumv += (abs(p[i].se.x - p[i].fi.x)+1)*(abs(p[i].se.y - p[i].fi.y)+1)*(abs(p[i].se.z - p[i].fi.z)+1);
        }
        if(sumv != V || no)
        {
            printf("NO\n");
            continue;
        }
        bool ok = true;
        For(i,1,m)
            For(j,i+1,m)
                if(check(p[i].fi,p[i].se,p[j].fi,p[j].se)){
                    ok = false;
                    break;
                }
        if(!ok)
        {
            printf("NO\n");
            continue;
        }
        For(i,1,m)
            if(!Checkchoco(p[i].fi,p[i].se,d[i]))
            {
               ok = false;
               break;
            }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }
}
/*
2 2 2 8
1 1 1
1 2 1
2 1 1
2 2 1
1 1 2
1 2 2
2 1 2
2 2 2
1 1 1 1 1 1
1 2 1 1 2 1
2 1 1 2 1 1
2 2 1 2 2 1
1 1 2 1 1 2
1 2 2 1 2 2
2 1 2 2 1 2
2 2 2 2 2 2
-1
*/
