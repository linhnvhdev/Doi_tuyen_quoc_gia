#include <bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define fi first
#define se second
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,m;
ll a[maxn],val[4*maxn];

void update(int node,int l,int r,int i,int v)
{
    if(l > i || r < i) return;
    if(l == r)
    {
        val[node] += v;
        return;
    }
    int c = (l+r)/2;
    update(2*node,l,c,i,v);
    update(2*node+1,c+1,r,i,v);
    val[node] = val[2*node] + val[2*node+1];
}

ll get(int node,int l,int r,int i,int j)
{
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return val[node];
    int c =(l+r)/2;
    return get(2*node,l,c,i,j) + get(2*node+1,c+1,r,i,j);
}

int main()
{
    fast_read;
    freopen("QUERYSUM.inp","r",stdin);
    freopen("QUERYSUM.out","w",stdout);
    cin >> n >> m;
    char type;
    int l,r;
    For(i,1,m)
    {
        cin >> type >> l >> r;
        if(type == 'S')
        {
            update(1,1,n,l,r-a[l]);
            a[l] = r;
        }
        else
            cout << get(1,1,n,l,r) << '\n';
    }
}
