#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
#define point pair<int,int>
#define fi first
#define se second
using namespace std;

int n;
ll a1,b1,a2,b2;
pair<ll,ll> p[maxn];
pair<ll,int> d[maxn];
ll maxd[maxn];

ll dis(ll x,ll y,ll u,ll v)
{
    return (x - u)*(x - u) + (y - v)*(y - v);
}

void Sub2()
{
    ll ans = INF;
    For(i,1,n){
        ll dist = dis(a1,b1,p[i].fi,p[i].se),dist2 = 0;
        For(j,1,n)
            if(dis(a1,b1,p[j].fi,p[j].se) > dist) dist2 = max(dist2,dis(a2,b2,p[j].fi,p[j].se));
        ans = min(ans,dist + dist2);
    }
    For(i,1,n){
        ll dist = dis(a2,b2,p[i].fi,p[i].se),dist2 = 0;
        For(j,1,n)
            if(dis(a2,b2,p[j].fi,p[j].se) > dist) dist2 = max(dist2,dis(a1,b1,p[j].fi,p[j].se));
        ans = min(ans,dist + dist2);
    }
    cout << ans << endl;
}

void Sub3()
{
    For(i,1,n) d[i] = {dis(a1,b1,p[i].fi,p[i].se),i};
    sort(d+1,d+1+n);
    d[0] = {0,0};
    ll curd = 0;
    ll ans = d[n].fi;
    Forr(i,n,1){
        curd = max(curd,dis(a2,b2,p[d[i].se].fi,p[d[i].se].se));
        ans = min(ans,curd + d[i-1].fi);
    }
    cout << ans << endl;
}

int main()
{
    //freopen("FOUNTAIN.inp","r",stdin);
    //freopen("FOUNTAIN.out","w",stdout);
    cin >> n >> a1 >> b1 >> a2 >> b2;
    For(i,1,n) scanf("%lld%lld",&p[i].fi,&p[i].se);
    if(n <= 1000) Sub2();
    else Sub3();
}
