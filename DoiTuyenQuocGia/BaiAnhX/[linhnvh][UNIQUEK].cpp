#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define INF 1e18
using namespace std;

int it[4*maxn];

int m,q,Left[maxn],le,ri;
pair<int,int> a[maxn];
int b[maxn];

void build(int node,int l,int r)
{
    if(l == r)
    {
        it[node] = Left[l];
        return;
    }
    int c = (l+r)/2;
    build(2*node,l,c);
    build(2*node+1,c+1,r);
    it[node] = max(it[2*node],it[2*node+1]);
}

int get(int node,int l,int r,int i,int j)
{
    if(l > j || r < i) return -1;
    if(i <= l && r <= j) return it[node];
    int c = (l+r)/2;
    return max(get(2*node,l,c,i,j),get(2*node+1,c+1,r,i,j));
}

int main()
{
    fast_read;
    freopen("UNIQUEK.inp","r",stdin);
    freopen("UNIQUEK.out","w",stdout);
    while(cin >> m >> q)
    {
        if(m == 0 && q == 0) return 0;
        For(i,1,m)
        {
            cin >> a[i].fi;
            a[i].se = i;
            b[i] = a[i].fi;
            Left[i] = 0;
        }
        sort(a+1,a+1+m);
        For(i,2,m)
            if(a[i].fi == a[i-1].fi)
                Left[a[i].se] = a[i-1].se;
        build(1,1,m);
        For(i,1,q)
        {
            cin >> le >> ri;
            int cur = get(1,1,m,le,ri);
            if(cur >= le) cout << b[cur] << '\n';
            else cout << "OK\n";
        }
        cout << '\n';
    }
}
