#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

ll x[maxn],t[maxn],best[maxn],ans[maxn];
int n;

struct query{
    int id;
    ll a,b;
} q[maxn];

bool cmp(query x,query y)
{
    if(x.a != y.a) return x.a < y.a;
    return x.b > y.b;
}

int main()
{
    freopen("DROPDEW2.inp","r",stdin);
    freopen("DROPDEW2.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n){
        scanf("%lld%lld",&x[i],&t[i]);
        q[i] = {i,x[i] - t[i],x[i] + t[i]};
    }
    sort(q+1,q+1+n,cmp);
    int m = 1;
    best[1] = q[1].b;
    ans[q[1].id] = 1;
    For(i,2,n){
        int vt = lower_bound(best+1,best+1+m,q[i].b) - best;
        m = max(m,vt);
        best[vt] = q[i].b;
        ans[q[i].id] = vt;
    }
    printf("%d\n",m);
    For(i,1,n) printf("%lld %lld %lld\n",x[i],t[i],ans[i]);
    return 0;
}
