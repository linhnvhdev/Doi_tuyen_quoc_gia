// FF
/*
    (1) Tìm rừng chỉ gồm các cạnh loại a(ta cạnh)
    (2) Chỉ chọn B(tb cạnh)
    (3) Hợp 2 phần để có x cạnh loại A và n-1 cạnh loại B
        (x <= số cạnh loại a),(n - 1 - x <= số cạnh loại B
        Hợp AB
            => ĐT AB rồi lần lượt bỏ từng cạnh 1 ra nếu thừa
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
pair<pair<int,int>,int> d1[maxn],d2[maxn];
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

void dfs(int u,int p)
{

}

int main()
{
    freopen("AZNET.inp","r",stdin);
    freopen("AZNET.out","w",stdout);
    scanf("%d",&t);
    while(t--) {
        cnt1 = cnt2 = ta = tb = 0;
        scanf("%d%d",&n,&m);
        For(i,1,n-1) scanf("%d",&a[i]);
        For(i,1,n-1) scanf("%d",&b[i]);
        For(i,1,m){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            if(c == 1) d1[++cnt1] = {{u,v},i};
            if(c == 2) d2[++cnt2] = {{u,v},i};
        }
        For(i,1,n) make_set(i);
        For(i,1,cnt1){
            int u = d1[i].fi.fi,v = d1[i].fi.se,id = d1[i].se;
            if(Union(u,v)){
                d[u].push_back({v,id});
                d[v].push_back({u,id});
                ta++;
            }
        }
        For(i,1,n) make_set(i);
        For(i,1,cnt2){
            int u = d2[i].fi.fi,v = d2[i].fi.se,id = d2[i].se;
            if(Union(u,v)){
                d[u].push_back({v,id});
                d[v].push_back({u,id});
                tb++;
            }
        }
//        For(x,0,ta)
//            if(n - 1 - x <= tb) ans = min(ans,1ll*a[x] + 1ll*b[n-1-x]);
//        cout << ans << endl;
        dfs(1);

    }
}
