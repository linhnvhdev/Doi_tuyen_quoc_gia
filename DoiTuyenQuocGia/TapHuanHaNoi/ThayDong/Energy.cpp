/**
    cap ghep tach 1 ben tong chan 1 ben tong le
    2 diem 2 ben ghep dc cho nhau neu v[i] + v[i] >= e vaf khonag cach == 1
**/
/**
    Xet lan luot tung dinh
    Neu den 1 dinh chua dc to mau
    thu mau tu 1->3
    neu color != c[i] thu to dinh i = mau cc
    neu to dc thi break luon
    neu ko to dc thi vo nghiem
**/

#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

struct point
{
    ll a,b,c,p;
} a[maxn],b[maxn];

int n,r,cnta = 0,cntb = 0,q = 0;

vector<int> adj[maxn];

int used[maxn],matchU[maxn],matchV[maxn];

bool ok(point u,point v)
{
//    if(u.a == v.a && u.b == v.b && abs(u.c - v.c) == 1) return true;
//    if(abs(u.a - v.a) == 1 && u.b == v.b && u.c == v.c) return true;
//    if(u.a == v.a && abs(u.b - v.b) == 1 && u.c == v.c) return true;
    if(abs(u.a - v.a) + abs(u.b - v.b) + abs(u.c - v.c) == 1) return true;
    return false;
}

bool dfs(int u,int cur)
{
    if(used[u] == cur) return false;
    used[u] = cur;
    for(int i = 0;i < adj[u].size();i++)
    {
        int v = adj[u][i];
        if(!matchV[v] || dfs(matchV[v],cur))
        {
            matchU[u] = v;
            matchV[v] = u;
            return true;
        }
    }
    return false;
}

bool check(ll mid)
{
    memset(used,0,sizeof(used));
    memset(matchU,0,sizeof(matchU));
    memset(matchV,0,sizeof(matchV));
    For(i,1,cnta) adj[i].clear();
    For(i,1,cnta)
        For(j,1,cntb)
            if(ok(a[i],b[j]) && a[i].p + b[j].p >= mid)
                adj[i].push_back(j);
    int tmp = 0;
    For(i,1,cnta)
        tmp += dfs(i,i);
    For(i,1,cnta)
        if(!matchU[i])
        {
            if(a[i].p >= mid) {tmp++;continue;}
            ll M = -INF;
            For(j,1,cntb)
                if(ok(a[i],b[j])) M = max(M,b[j].p);
            if(M + a[i].p >= mid) tmp++;
            else return false;
        }
    For(i,1,cntb)
        if(!matchV[i])
        {
            if(b[i].p >= mid) {tmp++;continue;}
            ll M = -INF;
            For(j,1,cnta)
                if(ok(b[i],a[j])) M = max(M,a[j].p);
            if(M + b[i].p >= mid) tmp++;
            else return false;
        }
    //cout <<" ^^ " <<  mid << ' ' << tmp << endl;
    return (tmp <= r);
}

int main()
{
    fast_read;
    freopen("Energy.inp","r",stdin);
    freopen("Energy.out","w",stdout);
    cin >> n >> r;
    For(i,1,n)
    {
        ll A,B,C,P;
        cin >> A >> B >> C >> P;
        if((A + B + C) % 2 == 0) a[++cnta] = {A,B,C,P};
        else b[++cntb] = {A,B,C,P};
    }
    ll l = 0,r = 1e14;
    while(r - l > 1)
    {
        ll mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(check(r)) cout << r << endl;
    else if(check(l)) cout << l << endl;
    else cout << -1 << endl;
}
