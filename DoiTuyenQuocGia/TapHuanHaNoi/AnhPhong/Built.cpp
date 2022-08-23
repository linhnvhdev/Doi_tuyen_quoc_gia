///https://atcoder.jp/contests/abc065/tasks/arc076_b
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define INF 1e18
using namespace std;

int P[maxn],h[maxn];

struct edge
{
    int u,v;
    ll d;
} e[maxn];

int n;

struct point
{
    ll x,y;
    int id;
} p[maxn];

ll len(point u,point v)
{
    return min(abs(u.x - v.x),abs(u.y - v.y));
}

void make_set(int i)
{
    P[i] = i;
    h[i] = 0;
}

int Find(int i)
{
    while(i != P[i]) i = P[i];
    return i;
}

bool Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    if(h[x] < h[y]) P[x] = y;
    else
    {
        P[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

bool cmp1(point u,point v)
{
    return u.x < v.x;
}

bool cmp2(point u,point v)
{
    return u.y < v.y;
}

bool cmp(edge x,edge y)
{
    return x.d < y.d;
}

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n)
     {
         cin >> p[i].x >> p[i].y;
         p[i].id = i;
     }
    int cnt = 0;
    sort(p+1,p+1+n,cmp1);
    For(i,1,n-1)
    {
        int u = p[i].id;
        int v = p[i+1].id;
        e[++cnt] = {u,v,len(p[i],p[i+1])};
    }
    sort(p+1,p+1+n,cmp2);
    For(i,1,n-1)
    {
        int u = p[i].id;
        int v = p[i+1].id;
        e[++cnt] = {u,v,len(p[i],p[i+1])};
    }
    For(i,1,n) make_set(i);
    int t = 0;
    ll ans = 0;
    sort(e+1,e+1+cnt,cmp);
    For(i,1,cnt)
        if(Union(e[i].u,e[i].v))
        {
            t++;
            ans += e[i].d;
            if(t == n-1) break;
        }
    cout << ans << endl;
}
