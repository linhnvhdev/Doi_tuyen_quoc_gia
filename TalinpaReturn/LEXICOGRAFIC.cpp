#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 250005
#define ll long long
#define fi first
#define se second
#define INF 1e9
using namespace std;

ll n,t,add[4*maxn],a[maxn],b[maxn];
ll k,bit[maxn];
pair<int,ll> val[4*maxn];

void init(int node,int l,int r)
{
    if(l == r){
        val[node] = {l,a[l]};
        return;
    }
    int c = (l+r)/2;
    init(2*node,l,c);
    init(2*node+1,c+1,r);
    val[node] = (val[2*node].se <= val[2*node+1].se) ? val[2*node] : val[2*node+1];
}

void update(int node,int l,int r,int i,ll v)
{
    if(l == i && r == i){
        val[node] = {0,INF};
        return;
    }
    int c = (l+r)/2;
    if(i <= c) update(2*node,l,c,i,v);
    if(i > c) update(2*node+1,c+1,r,i,v);
    val[node] = (val[2*node].se <= val[2*node+1].se) ? val[2*node] : val[2*node+1];
}

pair<int,ll> get(int node,int l,int r,int i,int j)
{
    if(r < i || l > j) return {0,1e18};
    if(l >= i && r <= j) return val[node];
    int c = (l+r)/2;
    pair<int,ll> p1 = get(2*node,l,c,i,j);
    pair<int,ll> p2 = get(2*node+1,c+1,r,i,j);
    if(p1.se <= p2.se) return p1;
    return p2;
}

void updbit(int pos,int v)
{
    for(int i = pos;i <= n;i += (i&(-i)))
        bit[i] += v;
}

ll getbit(ll pos)
{
    ll tmp = 0;
    for(int i = pos;i > 0; i-= (i&(-i)))
        tmp += bit[i];
    return tmp;
}

int Find(ll K)
{
    int l = 1, r = n;
    while(r - l > 1){
        int mid = (l+r)/2;
        if(getbit(mid) < K) l = mid;
        else r = mid;
    }
    if(getbit(l) >= K) return l;
    else return r;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LEXICOGRAFIC.inp","r",stdin);
    freopen("LEXICOGRAFIC.out","w",stdout);
    cin >>t;
    while(t--){
        cin >> n >> k;
        bool ok1 = false;
        For(i,1,n)
            cin >> a[i];
        if(k == 1ll*n*(n-1)/2){
            sort(a+1,a+1+n);
            For(i,1,n) cout << a[i] << ' ' ;
            continue;
        }
        init(1,1,n);
        For(i,1,n) updbit(i,1);
        for(int i = 1;i <= n;i++){
            int vt = Find(k+1);
            pair<int,ll> tt = get(1,1,n,1,vt);
            int minval = tt.se;
            int pos = tt.fi;
            //cerr << k << ' ' << vt << ' ' <<pos << ' ' << minval << endl;
            b[i] = minval;
            k -= (getbit(pos) - 1);
            updbit(pos,-1);
            update(1,1,n,pos,INF);
        }
        For(i,1,n) cout << b[i] << ' ';
        cout << '\n';
    }
    return 0;
}
