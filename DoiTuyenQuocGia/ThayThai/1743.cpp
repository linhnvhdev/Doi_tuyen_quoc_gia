/**
    Tìm bao lồi của tập các điểm của đèn trời lớn
    (Dùng thuật toán quét Graham) ĐPT : (nlog2(n))
    Xét lần lượt đèn trời nhỏ kiểm tra xem nó có nằm trong || trên bao lồi hay ko
    Nếu có tăng ans lên 1

**/


#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define INF 1e18
#define maxn 200005
#define Bit(x,i) ((x >> i)&1)
#define ll long long
#define point pair<long long,long long>
#define x first
#define y second
using namespace std;

int n,k,m;
point P[maxn],p[maxn],A,q[maxn];

ll operator * (point u,point v)
{
    return u.x*v.y - u.y*v.x;
}

point operator - (point u,point v)
{
    return {u.x - v.x,u.y - v.y};
}

ll sqrlen(point u)
{
    return u.x*u.x + u.y*u.y;
}

int ccw(point a,point b,point c)
{
    ll s = (b-a)*(c-a);
    if(s > 0) return 1;
    if(s < 0) return -1;
    return 0;
}

bool cmp(point B,point C)
{
    point u = B - A;
    point v = C - A;
    return (u*v > 0 || (u*v == 0 && sqrlen(u) < sqrlen(v)));
}

void ConvexHull()
{
    sort(P+1,P+1+n,cmp);
    m = 0;
    For(i,1,n)
    {
        while(m > 1 && ccw(q[m-1],q[m],P[i]) <= 0) m--;
        q[++m] = P[i];
    }
}

bool inside(point A, point q[])
{
    if(ccw(q[1],q[2],A) < 0 || ccw(q[1],q[m],A) > 0) return false;
    int l = 2,r = m;
    while(r - l > 1)
    {
        int mid = (l+r)/2;
        if(ccw(q[1],q[mid],A) >= 0) l = mid;
        else r = mid;
    }
    return ccw(q[l],q[l+1],A) >= 0;
}

int main()
{
    scanf("%d",&n);
    A = {INF,INF};
    For(i,1,n)
    {
        scanf("%lld%lld",&P[i].x,&P[i].y);
        if(P[i].y < A.y || (P[i].y == A.y && P[i].x < A.x)) A = P[i];
    }
    scanf("%d",&k);
    For(i,1,k) scanf("%lld%lld",&p[i].x,&p[i].y);
    ConvexHull();
    int ans = 0;
    For(i,1,k)
        ans += inside(p[i],q);
    cout << ans << endl;
    return 0;
}
