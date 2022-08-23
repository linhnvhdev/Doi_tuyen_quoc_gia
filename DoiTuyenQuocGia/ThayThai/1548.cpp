/**
    hsg = (yb-ya)/(xb-xa);
**/

#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(long long i = a; i <= b; ++i)
#define maxn 1005
#define INF 1e18
#define x first
#define y second
#define point pair<ll,ll>
#define ppll pair<pair<ll,ll>,ll>
using namespace std;

int n;
point p[2*maxn];

point operator - (point a,point b)
{
    return {a.x - b.x,a.y - b.y};
}

ll operator * (point a,point b)
{
    return 1ll*a.x*b.y - 1ll*a.y*b.x;
}

int ccw(point a,point b,point c)
{
    ll s = (b-a)*(c-a);
    if(s > 0) return 1;
    if(s < 0) return -1;
    return 0;
}

void Sub1()
{
    For(i,1,n)
        For(j,i+1,n)
            For(k,n+1,2*n)
                if(ccw(p[i],p[j],p[k]) == 0)
                {
                    cout << i << ' ' << j << ' ' << k << endl;
                    exit(0);
                }
    For(i,n+1,2*n)
        For(j,i+1,2*n)
            For(k,1,n)
                if(ccw(p[i],p[j],p[k]) == 0)
                {
                    cout << i << ' ' << j << ' ' << k << endl;
                    exit(0);
                }
    cout << -1 << endl;
}

double pt[maxn*maxn],bi[maxn*maxn];
int cnt = 0;

double ptdt(int i,int j)
{
    return 1.0*(p[j].y-p[i].y)/(p[j].x-p[i].x);
}

void Sub3()
{
    For(i,1,n)
        For(j,i+1,n)
            bi[++cnt] = ptdt(i,j);
    sort(bi+1,bi+1+cnt);
    For(i,1,n)
    {
        For(k,n+1,2*n)
        {
            double bido = ptdt(i,k);
            int vt = lower_bound(bi+1,bi+1+cnt,bido) - bi;
            if(vt <= cnt && bi[vt] == bido)
                For(j,i+1,n)
                    if(ptdt(i,j) == bido)
                    {
                        cout << i << ' ' << j << ' ' << k << endl;
                        exit(0);
                    }
        }
    }
    cnt = 0;
    For(i,n+1,2*n)
        For(j,i+1,2*n)
            bi[++cnt] = ptdt(i,j);
    sort(bi+1,bi+1+cnt);
    For(i,n+1,2*n)
    {
        For(k,1,n)
        {
            double bixanh = ptdt(i,k);
            int vt = lower_bound(bi+1,bi+1+cnt,bixanh) - bi;
            if(vt <= cnt && bi[vt] == bixanh)
                For(j,i+1,2*n)
                    if(ptdt(i,j) == bixanh)
                    {
                        cout << i << ' ' << j << ' ' << k << endl;
                        exit(0);
                    }
        }
    }
    cout << -1 << endl;
}

int main()
{
   // freopen("test.inp","r",stdin);
   // freopen("test.out","w",stdout);
    cin >> n;
    For(i,1,2*n)
        scanf("%lld%lld",&p[i].x,&p[i].y);
    if(n <= 100) Sub1();
    else
        Sub3();
}
