#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define maxn 3005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,k,c[maxn],a[maxn];
int val[105][4*maxn],add[105][4*maxn];

void down(int node,int id)
{
    val[id][2*node] = max(val[id][2*node],add[id][node]);
    val[id][2*node+1] = max(val[id][2*node+1],add[id][node]);
    add[id][2*node] = max(add[id][2*node],add[id][node]);
    add[id][2*node+1] = max(add[id][2*node+1],add[id][node]);
    add[id][node] = 0;
}

void update(int node,int l,int r,int i,int j,int v,int id)
{
    if(l > j || r < i) return;
    if(i <= l && r <= j)
    {
        val[id][node] = max(val[id][node],v);
        add[id][node] = max(add[id][node],v);
        return;
    }
    int c = (l+r)/2;
    down(node,id);
    update(2*node,l,c,i,j,v,id);
    update(2*node+1,c+1,r,i,j,v,id);
    val[id][node] = max(val[id][2*node],val[id][2*node+1]);
}

int get(int node,int l,int r,int i,int id)
{
    if(l > i || r < i) return 0;
    if(l == i && r == i) return val[id][node];
    int c = (l+r)/2;
    down(node,id);
    return max(get(2*node,l,c,i,id),get(2*node+1,c+1,r,i,id));
}

int main()
{
    fast_read;
    cin >> n>>k;
    For(i,1,n) cin >> c[i];
    For(i,1,n) cin >> a[i];
    if(n == 1)
    {
        cout << c[1] << endl;
        return 0;
    }
    update(1,1,n,2,min(1+a[1],n),c[1],1);
    For(i,2,n-1)
    {
        For(j,1,k-1)
        {
            int F = get(1,1,n,i,j);
            if(F != 0) update(1,1,n,i+1,min(i+a[i],n),F+c[i],j+1);
        }
    }
    int ans = 0;
    For(i,1,k)
        ans = max(ans,get(1,1,n,n,i) + c[n]);
    if(ans == c[n]) cout << -1 << endl;
    else cout << ans << endl;
}
