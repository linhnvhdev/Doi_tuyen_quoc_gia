#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int p[maxn],h[maxn];

ll le[maxn],ri[maxn],cnt = 0,val[4*maxn],add[4*maxn];
ll color[maxn];

struct event
{
    int type,l,r;
} e[maxn];

int n,q;

void make_set(int i)
{
    p[i] = i;
    h[i] = 0;
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

bool Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    if(h[x] < h[y])
        p[x] = y;
    else
    {
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

bool sub2 = true,sub3 = true;

void Sub12()
{
    For(i,1,n) make_set(i);
    For(i,1,q)
    {
        if(e[i].type == 1) Union(e[i].l,e[i].r);
        if(e[i].type == 2) For(j,e[i].l,e[i].r-1) Union(j,j+1);
        if(e[i].type == 3)
        {
            if(Find(e[i].l) == Find(e[i].r)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

void build(int node,int l,int r)
{
    if(l == r)
    {
        val[node] = l;
        return;
    }
    int c = (l+r)/2;
    build(2*node,l,c);
    build(2*node+1,c+1,r);
    val[node] = max(val[2*node],val[2*node+1]);
}

void down(int node)
{
    val[2*node] = max(val[2*node],add[node]);
    val[2*node+1] = max(val[2*node+1],add[node]);
    add[2*node] = max(add[2*node],add[node]);
    add[2*node+1] = max(add[2*node+1],add[node]);
    add[node] = 0;
}

void update(int node,int l,int r,int i,int j,int v)
{
    if(l > j || r < i) return;
    if(i <= l && r <= j)
    {
        val[node] = v;
        add[node] = v;
        return;
    }
    int c = (l+r)/2;
    down(node);
    update(2*node,l,c,i,j,v);
    update(2*node+1,c+1,r,i,j,v);
    val[node] = max(val[2*node],val[2*node+1]);
}

int get(int node,int l,int r,int i)
{
    if(l > i || r < i) return 0;
    if(l == r) return val[node];
    int c = (l+r)/2;
    down(node);
    return max(get(2*node,l,c,i),get(2*node+1,c+1,r,i));
}

void Sub3()
{
    cnt = n;
    For(i,1,n) le[i] = ri[i] = i;
    cin >> q;
    build(1,1,n);
    For(i,1,q)
    {
        if(e[i].type == 2)
        {
            int color1 = get(1,1,n,e[i].l);
            int color2 = get(1,1,n,e[i].r);
            if(color1 == color2) continue;
            cnt++;
            update(1,1,n,le[color1],ri[color2],cnt);
            le[cnt] = le[color1];
            ri[cnt] = ri[color2];
        }
        if(e[i].type == 3)
        {
            int color1 = get(1,1,n,e[i].l);
            int color2 = get(1,1,n,e[i].r);
            if(color1 == color2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

void Sub4()
{
    cnt = n;
    For(i,1,n) make_set(i);
    For(i,1,n) ri[i] = i+1;
    For(i,1,q)
    {
        //cout << "### " << i << endl;
        if(e[i].type == 1)
        {
            Union(e[i].l,e[i].r);
        }
        if(e[i].type == 2)
        {
            int u = e[i].l,v = e[i].r;
            int j = u;
            while(j <= v)
            {
                //cout << j << ' ' << ri[j] << endl;
                if(ri[j] > v) break;
                Union(j,ri[j]);
                int nxt = ri[j];
                ri[j] = ri[v];
                j = nxt;
            }
        }
        if(e[i].type == 3)
        {
            if(Find(e[i].l) == Find(e[i].r)) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}

int main()
{
    fast_read;
    freopen("Restruct.inp","r",stdin);
    freopen("Restruct.out","w",stdout);
    cin >> n >> q;
    For(i,1,q)
    {
        cin >> e[i].type >> e[i].l >> e[i].r;
        if(e[i].type == 2) sub2 = false;
        if(e[i].type == 1) sub3 = false;
    }
    if(n <= 1000 || sub2) Sub12();
    else if(sub3) Sub3();
    else
        Sub4();
}
