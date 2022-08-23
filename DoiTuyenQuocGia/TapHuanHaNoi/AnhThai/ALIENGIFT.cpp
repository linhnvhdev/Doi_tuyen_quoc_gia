#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n,L[maxn],H[maxn];
ll a[maxn][5],f[maxn][(1<<5)],d[maxn][(1<<5)];
bool ok1[(1<<5)],ok2[(1<<5)][1<<5];
ll val[(1<<5)][5*maxn],add[(1<<5)][5*maxn];

bool OK(int mask1,int mask2)
{
    if(!ok1[mask1] || !ok1[mask2] || !ok2[mask1][mask2]) return false;
    return true;
}

void build(int node,int l,int r,int id)
{
    if(l == r)
    {
        val[id][node] = -INF;
        add[id][node] = -INF;
        return;
    }
    int c = (l+r)/2;
    build(2*node,l,c,id);
    build(2*node+1,c+1,r,id);
    val[id][node] = -INF;
    add[id][node] = -INF;
}

void down(int node,int id)
{
    val[id][2*node] = max(val[id][2*node],add[id][node]);
    val[id][2*node+1] = max(val[id][2*node+1],add[id][node]);
    add[id][2*node] = max(add[id][2*node],add[id][node]);
    add[id][2*node+1] = max(add[id][2*node+1],add[id][node]);
    add[id][node] = -INF;
}

void update(int node,int l,int r,int i,int j,ll v,int id)
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

ll get(int node,int l,int r,int i,int id)
{
    if(l > i || r < i) return -INF;
    if(l == r) return val[id][node];
    int c = (l+r)/2;
    down(node,id);
    return max(get(2*node,l,c,i,id),get(2*node+1,c+1,r,i,id));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(ok1,true,sizeof(ok1));
    freopen("ALIENGIFT.inp","r",stdin);
    freopen("ALIENGIFT.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> L[i] >> H[i];
        For(j,0,3) cin >> a[i][j];
        For(mask,0,(1<<4)-1)
            For(j,0,3) if(Bit(mask,j)) d[i][mask] += a[i][j];
    }
    For(mask,1,(1<<4))
        For(j,1,3) if(Bit(mask,j) && Bit(mask,j) == Bit(mask,j-1)) ok1[mask] = false;
    //For(mask,1,(1<<4)-1) build(1,1,n,mask);
    For(i,0,16)
        For(j,0,4*maxn) val[i][j] = add[i][j] = -INF;
    ll ans = -INF;
    For(i,1,n)
        For(mask,0,(1<<4)-1)
        {
            if(!ok1[mask]) continue;
            ll F = get(1,1,n+1,i,mask);
            if(i == 1) F = 0;
            if(F == -INF) continue;
            else
            {
                int le = min(i + L[i],n+1);
                int ri = min(i + H[i],n+1);
                if(i + H[i] > n && (F != 0 || mask != 0)) ans = max(ans,F + d[i][mask]);
                For(mask2,0,(1<<4)-1)
                {
                    if(ok1[mask] && ok1[mask2] && (mask & mask2) == 0)
                        update(1,1,n+1,le,ri,F + d[i][mask],mask2);
                }
            }
        }
    cout << ans << endl;
}

