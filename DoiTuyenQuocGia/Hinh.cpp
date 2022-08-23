#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b; ++i)
#define ll long long
#define maxN 100005
using namespace std;
int n,m;
const ll INF=1e15;
struct Point
{
    ll x,y;
}p[maxN],q[maxN];
typedef Point Vector;
Point A; // điểm có tung độ thấp nhất nằm trái nhất
long double ans=0;
double Len(Vector a) // độ dài vector
{
    return sqrt(a.x * a.x + a.y * a.y);
}
ll Sqrlen(Vector a) // bình phương độ dài vector
{
    return a.x * a.x + a.y * a.y;
}
Vector operator +(Vector a,Vector b) // cộng 2 vector
{
    return {a.x + b.x,a.y + b.y};
}
Vector operator -(Vector a,Vector b) //trừ 2 vector
{
    return {a.x - b.x,a.y - b.y};
}
ll operator %(Vector a,Vector b) // tích chấm
{
    return a.x * b.x + a.y * b.y;
}

ll operator * (Vector a , Vector b) // tích chéo
{
    return a.x * b.y - a.y * b.x;
}
/* đo góc giữa 2 vector atan2(u*v,u%v); // kq đo bằng radian */
void GrahamScan(){
    sort(p + 1, p + 1 + n, []( Vector B , Vector C ){
        Vector u = B - A , v = C - A;
        ll temp = u * v;
        return (temp > 0 || (temp == 0 && Sqrlen(u) < Sqrlen(v) ) );
    });
}

bool CCW (Vector D, Vector E, Vector F){return (E - D) * (F - E) > 0;}

void FindConvexHull(){
    m=0;
    //For(i,1,n) cout << p[i].x << ' ' << p[i].y << endl;
    For(i,1,n){
        while( m >= 2 && !CCW(q[m - 2] , q[m - 1] , p[i]))m--;
        q[m]=p[i];
        m++;
    }
    printf("%d\n",m);
    q[m]=q[0];
    For(i,0,m-1)ans+= q[i] * q[i+1];
    ans/=2;
    printf("%.1lf\n",abs(ans));
    For(i,0,m-1)
        printf("%lld %lld\n",q[i].x,q[i].y);
}
int main()
{
    scanf("%d" , &n);
    A.y=INF;
    For(i,1,n){
        scanf("%lld%lld" , &p[i].x , &p[i].y);
        if(( p[i].y < A.y )|| ( p[i].y == A.y && p[i].x < A.x ) )A = p[i];
    }
    GrahamScan();
    FindConvexHull();
}
