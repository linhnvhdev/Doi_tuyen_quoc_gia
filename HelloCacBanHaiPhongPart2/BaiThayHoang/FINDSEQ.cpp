#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ull long long
#define fi first
#define se second
#define INF 1e9
using namespace std;

struct query{
    int l,r,k;
} q[maxn];

int n,m,a[maxn],it[4*maxn],add[4*maxn];

void init(int node,int l,int r)
{
    if(l == r){
        it[node] = add[node] = 1e9+1;
        return;
    }
    int c = (l+r)/2;
    init(2*node,l,c);
    init(2*node+1,c+1,r);
    it[node] = max(it[2*node],it[2*node+1]);
}

void down(int node)
{
    if(add[node] == 1e9+1) return;
    it[2*node] = min(it[2*node],add[node]);
    it[2*node+1] = min(it[2*node+1],add[node]);
    add[2*node] = add[node];
    add[2*node+1] = add[node];
    add[node] = 1e9+1;
}

void update(int node,int l,int r,int i,int j,int val)
{
    if(l == i && r == j){
        it[node] = add[node] = val;
        return;
    }
    down(node);
    int c = (l+r)/2;
    if(i <= c) update(2*node,l,c,i,min(c,j),val);
    if(j > c) update(2*node+1,c+1,r,max(c+1,i),j,val);
    it[node] = min(it[2*node],it[2*node+1]);
}

int get(int node,int l,int r,int i)
{
    if(l == i && r == i) return it[node];
    down(node);
    int c = (l+r)/2;
    if(i <= c) return get(2*node,l,c,i);
    else return get(2*node+1,c+1,r,i);
}

bool cmp(query x,query y)
{
    return x.k > y.k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("FINDSEQ.inp","r",stdin);
    freopen("FINDSEQ.out","w",stdout);
    cin >> n >> m;
    For(i,1,m)
        cin >> q[i].l >> q[i].r >> q[i].k;
    init(1,1,n);
    sort(q+1,q+1+m,cmp);
    For(i,1,m)
        update(1,1,n,q[i].l,q[i].r,q[i].k);
    For(i,1,n){
        a[i] = get(1,1,n,i);
        if(a[i] == 1e9+1){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    For(i,1,n)cout << a[i] << ' ';
}
