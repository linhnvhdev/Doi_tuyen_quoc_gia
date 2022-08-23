#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

struct data{
    ll val;
    int maxl,minr;
} tree[4*maxn];

int n,T;
ll a[maxn],b[maxn],sum[maxn];

void init(int s,int l,int r)
{
    if(l == r)
    {
        tree[s] = {1,l,l};
        return;
    }
    int c = (l+r)/2;
    init(2*s,l,c);
    init(2*s+1,c+1,r);
    tree[s].val = 1;
    tree[s].maxl = tree[2*s+1].maxl;
    tree[s].minr = tree[2*s].minr;
}

void update(int s,int l,int r,int i)
{
    if(l > i || r < i) return;
    if(l == i && r == i)
    {
        tree[s].val = 0;
        return;
    }
    int c = (l+r)/2;
    update(2*s,l,c,i);
    update(2*s+1,c+1,r,i);
    if(tree[2*s].val < tree[2*s+1].val) tree[s] = tree[2*s];
    if(tree[2*s].val > tree[2*s+1].val) tree[s] = tree[2*s+1];
    if(tree[2*s].val == tree[2*s+1].val)
    {
        tree[s].minr = tree[2*s].minr;
        tree[s].maxl = tree[2*s+1].maxl;
    }
}

data Get(int s,int l,int r,int i,int j)
{
    ll inf = INF;
    if(l > j || r < i) return {inf,0,0};
    if(i <= l && r <= j) return tree[s];
    int c = (l+r)/2;
    data t1 = Get(2*s,l,c,i,j);
    data t2 = Get(2*s+1,c+1,r,i,j);
    if(t1.val < t2.val) return t1;
    if(t1.val > t2.val) return t2;
    return {t1.val,t2.maxl,t1.minr};
}

ll getsum(int i,int j)
{
    return sum[j] - sum[i-1];
}

set<pair<ll,pair<int,int> > >S;

int main()
{
    fast_read;
    freopen("RSEQ.inp","r",stdin);
    freopen("RSEQ.out","w",stdout);
    cin >> n >> T;
    For(i,1,n)
    {
        cin >> a[i];
        sum[i] = sum[i-1] + a[i];
    }
    init(1,1,n);
    S.insert({sum[n],{1,n}});
    For(i,1,T)
    {
        int d,left,right;
        cin >> d;
        data t1 = Get(1,1,n,1,d-1);
        data t2 = Get(1,1,n,d+1,n);
        left = (t1.val == 1 || d == 1) ? 1 : t1.maxl+1;
        right = (t2.val == 1 || d == n) ? n : t2.minr-1;
        S.erase({getsum(left,right),{left,right}});
        if(left < d) S.insert({getsum(left,d-1),{left,d-1}});
        if(right > d) S.insert({getsum(d+1,right),{d+1,right}});
        cout << (--S.end())->fi << endl;
        update(1,1,n,d);
    }
    return 0;
}
