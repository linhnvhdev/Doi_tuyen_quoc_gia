/**
    b[x] : vt xuất hiện  cuối cùng của x trong dãy
    b[1..n] = 0;
    For(i,1,n){
        b[a[i]] = i;
        < Trả lời truy vấn c,d,l,r với r = i>

    }
    sort các truy vấn theo r;
    Trả lời truy vấn (c,d,l,r)
    <=> tìm x nhỏ nhất sao cho b[x] < L
**/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 400005
#define ll long long
#define fi first
#define se second
using namespace std;

struct query{
    int id,c,d,l,r;
} q[maxn];

int n,m,a[maxn],len,cnt[maxn],it[4*maxn],ans[maxn];

bool cmp(query x,query y)
{
    return x.r < y.r;
}

void update(int node,int l,int r,int i,int val)
{
    if(l == r){
        it[node] = val;
        return;
    }
    int c = (l+r)/2;
    if(i <= c) update(2*node,l,c,i,val);
    if(i > c) update(2*node+1,c+1,r,i,val);
    it[node] = min(it[2*node],it[2*node+1]);
}

int Find(int node,int l,int r,int val)
{
    if(l == r) return l;
    int c = (l+r)/2;
    if(it[2*node] < val) return Find(2*node,l,c,val);
    return Find(2*node+1,c+1,r,val);
}

int get(int node,int l,int r,int i,int j,int val)
{
    if(i == l && j == r){
        if(it[node] < val) return Find(node,l,r,val);
        return 0;
    }
    int c = (l+r)/2,tmp1 = 0,tmp2 = 0;
    if(i <= c) tmp1 = get(2*node,l,c,i,min(c,j),val);
    if(j > c) tmp2 = get(2*node+1,c+1,r,max(c+1,i),j,val);
    if(tmp1 != 0) return tmp1;
    else return tmp2;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("COLORS.inp","r",stdin);
    freopen("COLORS.out","w",stdout);
    cin >> n >> m;
    For(i,1,n) cin >> a[i];
    For(i,1,m){
        cin >> q[i].c >> q[i].d >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q+1,q+1+m,cmp);
    int j = 1;
    For(i,1,m){
        while(j <= n && j <= q[i].r){
            update(1,1,n,a[j],j);
            j++;
        }
        ans[q[i].id] = get(1,1,n,q[i].c,q[i].d,q[i].l);
    }
    For(i,1,m){
        if(ans[i] == 0)cout << "OK\n";
        else cout << ans[i] << '\n';
    }
}
