#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
using namespace std;

int n,q;
const int mod = 1e9+7;

ll x[4*maxn],val[4*maxn],add[4*maxn],a[4*maxn],b[4*maxn];

void init(int node,int l,int r)
{
    if(l == r){
        val[node] = add[node] = x[l];
        return;
    }
    int c = (l+r)/2,p1 = 2*node+1,p2 = 2*node+2;
    init(p1,l,c);
    init(p2,c+1,r);
    val[node] = (val[p1] + val[p2]) % mod;
    add[node] = -1;
    a[node] = 1;
    b[node] = 0;
}

void down(int node,int l1,int l2)
{
    int p1 = 2*node+1,p2 = 2*node+2;
    if(add[node] != -1){
        val[p1] = 1ll*l1*add[node] % mod;
        val[p2] = 1ll*l2*add[node] % mod;
        add[p1] = add[node];
        add[p2] = add[node];
    }
    else{
        val[p1] = (val[p1] * a[node] + b[node] * l1) % mod;
        val[p2] = (val[p2] * a[node] + b[node] * l2) % mod;

        if(add[p1] != -1) add[p1] = (add[p1] * a[node] + b[node]) % mod;
        else a[p1] = a[p1] * a[node] % mod, b[p1] = (b[p1] * a[node] + b[node]) % mod;

        if(add[p2] != -1) add[p2] = (add[p2] * a[node] + b[node]) % mod;
        else a[p2] = a[p2] * a[node] % mod, b[p2] = (b[p2] * a[node] + b[node]) % mod;
    }
    add[node] = -1; a[node] = 1; b[node] = 0;
}

void update(int node,int l,int r,int type,int i,int j,ll v)
{
    if(i == l && j == r){
        if(type == 1){
            val[node] = (val[node] +  v*(r-l+1))%mod;
            if(add[node] != -1)
                add[node] = (add[node] + v) % mod;
            else b[node] = (b[node] + v) % mod;
        }
        if(type == 2){
            val[node] = val[node]*v % mod;
            if(add[node] != -1) add[node] = add[node]*v%mod;
            else{
                a[node] = a[node]*v % mod;
                b[node] = b[node]*v % mod;
            }
        }
        if(type == 3){
            val[node] = 1ll*v*(r-l+1) % mod;
            add[node] = v;
        }
        return;
    }
    int c = (l+r)/2,p1 = 2*node+1,p2 = 2*node+2;
    down(node,c - l + 1,r - c);
    if(i <= c) update(p1,l,c,type,i,min(c,j),v);
    if(j > c) update(p2,c+1,r,type,max(i,c+1),j,v);
    val[node] = (val[p1] + val[p2]) % mod;
}

ll Get(int node,int l,int r,int i,int j)
{
    if(i == l && j == r) return val[node] % mod;
    int c = (l+r)/2,p1 = 2*node+1,p2 = 2*node+2;
    ll ans = 0;
    down(node,c - l + 1,r - c);
    if(i <= c) ans = (ans + Get(p1,l,c,i,min(c,j)))%mod;
    if(j > c) ans = (ans + Get(p2,c+1,r,max(c+1,i),j))%mod;
    return ans % mod;
}

int main()
{
    scanf("%d%d",&n,&q);
    For(i,1,n) scanf("%lld",&x[i]);
    init(0,1,n);
    For(i,1,q){
        int t,x,y;
        ll v;
        scanf("%d%d%d",&t,&x,&y);
        if(t == 4) printf("%lld\n",Get(0,1,n,x,y));
        else{
            scanf("%lld",&v);
            update(0,1,n,t,x,y,v);
        }
    }
}
