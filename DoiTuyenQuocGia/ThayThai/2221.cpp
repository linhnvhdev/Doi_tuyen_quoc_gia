#include<bits/stdc++.h>
#define For(i,a,b) for (int i = a;i <= b;i++)
#define Forr(i,a,b) for (int i = a;i >= b;i--)
#define x first
#define y second
#define pb push_back
#define ll long long
#define pii pair <int,int>
#define point pair <ll,ll>
#define maxn 100005
#define INF 1e18
using namespace std;

int n,m,d[10];
double sum,MAX;
point p[120],top[5],A,q[151],t[5];
pair <double,double> H2;

ll len(point a)
{
   return a.x*a.x + a.y*a.y;
}

point operator - (point a,point b){
     return {a.x-b.x,a.y-b.y};
}

ll operator * (point a,point b)
{
     return a.x*b.y - a.y*b.x;
}

point middle(point a,point b)
{
    return {(a.x + b.x)/2,(a.y + b.y)/2};
}

int ccw(point a,point b,point c)
{
    ll s = (b-a)*(c-b);
    if(s > 0) return 1;
    if(s < 0) return -1;
    return 0;
}

bool cmp(point a,point b)
{
    point u = a - A;
    point v = b - A;
    ll kc = u*v;
    return (kc > 0 || (kc == 0 && len(u) < len(v)));
}

double dist(point a,point b)
{
     return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

ll dist2(point a,point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void ConvexHull()
{
    sort(p+1,p+n+1,cmp);
    m = 1;
    For(i,1,n)
    {
        while(m > 2 && ccw(q[m-2],q[m-1],p[i])<=0) m--;
        q[m++] = p[i];
    }
    m--;
    q[m+1] = q[1];
    For(i,1,m)
    {
        double k = dist(q[i],q[i+1]);
        MAX = max(MAX,k);
        sum += k;
    }
    sum -= (MAX+dist(top[1],top[2]));
}
void sub1()
{
     MAX = 0;
     For(i,1,4)
       For(j,i+1,4)
          MAX = max(MAX,dist(top[i],top[j]));
     //cout<<sum<<" "<<MAX<<endl;
     sum += MAX;
     printf("%.2f",sum);
}

void Sub23()
{
    point H = middle(top[1],top[2]);
    if (dist2(top[4],H) < dist2(top[3],H)) swap(top[3],top[4]);
    if (dist2(top[1],top[2]) >= 3*dist2(top[1],top[3]))
    {
        double d = sum + dist(top[3],top[4]) + dist(top[1],top[3])*2;
        printf("%.2f",d);
        return;
    }
    else
    {
        double d = sum + dist(top[4],H) + dist(top[1],top[2])*sqrt(3)/2;
        printf("%.2f",d);
        return;
    }
}

void Sub4()
{
    double a = dist(top[1],top[2]);
    double ans = a*(1+sqrt(3));
    cout << fixed << setprecision(2) << ans + sum;
}

int main()
{
    scanf("%d",&n);
    A.y = INF;
    For(i,1,n)
    {
        scanf("%lld%lld",&p[i].x,&p[i].y);
        if (p[i].y < A.y or (p[i].y==A.y and p[i].x<A.x)) A=p[i];
    }
    For(i,1,2)
        top[i].x = p[i].x,top[i].y = p[i].y;
    scanf("%lld%lld%lld%lld",&top[3].x,&top[3].y,&top[4].x,&top[4].y);
    ConvexHull() ;
    if(ccw(top[1],top[2],top[3]) == ccw(top[2],top[3],top[4]) &&  ccw(top[1],top[2],top[3]) == 0) sub1();
    else
    {
        point M = middle(top[1],top[2]);
        if(ccw(top[3],top[4],M) == 0) Sub23();
        else Sub4();
    }
}
