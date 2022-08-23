/*
    (1) Tìm rừng chỉ gồm các cạnh loại a(ta cạnh)
    (2) Chỉ chọn B(tb cạnh)
    (3) Hợp 2 phần để có x cạnh loại A và n-1 cạnh loại B
        (x <= số cạnh loại a),(n - 1 - x <= số cạnh loại B
        Hợp AB
            Trong đồ thị AB
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
using namespace std;

int t,n,m,ta = 0,tb = 0;
int a[maxn],b[maxn];
vector<pair<pair<int,int>,int> > d[maxn];
pair<int,int> d1[maxn],d2[maxn];
int p[maxn],h[maxn];
int cnt1 = 0,cnt2 = 0;

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
    if(h[x] < h[y]) p[x] = y;
    else{
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

int main()
{
    freopen("AZNET2.inp","r",stdin);
    freopen("AZNET2.out","w",stdout);
    scanf("%d",&t);
    while(t--) {
        cnt1 = cnt2 = ta = tb = 0;
        scanf("%d%d",&n,&m);
        For(i,1,n-1) scanf("%d",&a[i]);
        For(i,1,n-1) scanf("%d",&b[i]);
        For(i,1,m){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            if(c == 1) d1[++cnt1] = {u,v};
            if(c == 2) d2[++cnt2] = {u,v};
        }
        For(i,1,n) make_set(i);
        For(i,1,cnt1)
            if(Union(d1[i].fi,d1[i].se))
                ta++;
        For(i,1,n) make_set(i);
        For(i,1,cnt2)
            if(Union(d2[i].fi,d2[i].se))
                tb++;
        ll ans = 1e18;
        For(x,0,ta)
            if(n - 1 - x <= tb) ans = min(ans,1ll*a[x] + 1ll*b[n-1-x]);
        cout << ans << endl;
    }
}
