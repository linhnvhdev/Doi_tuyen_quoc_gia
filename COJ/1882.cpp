#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e14
using namespace std;

struct IT{
    ll val;
    int maxl,minr;
} it[4*maxn];

int n;
ll a[maxn],b[maxn],sum[maxn];

void init(int s,int l,int r)
{
    if(l == r)
    {
        it[s] = {1,l,l};
        return;
    }
    int c = (l+r)/2;
    init(2*s,l,c);
    init(2*s+1,c+1,r);
    it[s].val = 1;
    it[s].maxl = it[2*s+1].maxl;
    it[s].minr = it[2*s].minr;
}

void update(int s,int l,int r,int i)
{
    if(l > i || r < i) return;
    if(l == i && r == i)
    {
        it[s].val = 0;
        return;
    }
    int c = (l+r)/2;
    update(2*s,l,c,i);
    update(2*s+1,c+1,r,i);
    if(it[2*s].val < it[2*s+1].val) it[s] = it[2*s];
    if(it[2*s].val > it[2*s+1].val) it[s] = it[2*s+1];
    if(it[2*s].val == it[2*s+1].val)
    {
        it[s].minr = it[2*s].minr;
        it[s].maxl = it[2*s+1].maxl;
    }
}

IT get(int s,int l,int r,int i,int j)
{
    ll inf = INF;
    if(l > j || r < i) return {inf,0,0};
    if(i <= l && r <= j) return it[s];
    int c = (l+r)/2;
    IT t1 = get(2*s,l,c,i,j);
    IT t2 = get(2*s+1,c+1,r,i,j);
    if(t1.val < t2.val) return t1;
    if(t1.val > t2.val) return t2;
    if(t1.val == t2.val)
        return {t1.val,t2.maxl,t1.minr};
}

ll getsum(int i,int j)
{
    return sum[j] - sum[i-1];
}

set<pair<ll,pair<int,int> > >S;
set<pair<ll,pair<int,int> > >:: iterator pos;

void Print()
{
    pos = S.end(); pos--;
    printf("%lld\n",(*pos).fi);
}

int main()
{
    scanf("%d",&n);
    For(i,1,n)
    {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    init(1,1,n);
    S.insert({sum[n],{1,n}});
    For(i,1,n-1)
    {
        int d,left,right;
        scanf("%d",&d);
        IT t1 = get(1,1,n,1,d-1);
        IT t2 = get(1,1,n,d+1,n);
        left = (t1.val == 1 || d == 1) ? 1 : t1.maxl+1;
        right = (t2.val == 1 || d == n) ? n : t2.minr-1;
        S.erase({getsum(left,right),{left,right}});
        if(left < d) S.insert({getsum(left,d-1),{left,d-1}});
        if(right > d) S.insert({getsum(d+1,right),{d+1,right}});
        Print();
        update(1,1,n,d);
    }
    scanf("%d",&n);
    printf("0\n");
    return 0;
}
