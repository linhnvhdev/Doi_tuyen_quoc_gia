#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 50005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

int test,m,n,ans = 0,q = 0;

int x[20],vst[maxn],match[maxn];

bool used[20];

pii p[maxn];

pii it[4*maxn];

vector<int> a[maxn];

void init(int node,int l,int r)
{
    if(l == r){
        it[node] = {0,l};
        return;
    }
    int c = (l+r)/2;
    init(2*node,l,c);
    init(2*node+1,c+1,r);
    it[node] = it[2*node];
}

void update(int node,int l,int r,int i,int v)
{
    if(r < i || l > i) return;
    if(l == i && r == i){
        it[node].fi = v;
        return;
    }
    int c = (l+r)/2;
    update(2*node,l,c,i,v);
    update(2*node+1,c+1,r,i,v);
    if(it[2*node].fi >= it[2*node+1].fi) it[node] = it[2*node];
    else it[node] = it[2*node+1];
}

pii get(int node,int l,int r,int i,int j)
{
    if(l > j || r < i) return {-1e9,1};
    if(i <= l && r <= j) return it[node];
    int c = (l+r)/2;
    pii t1 = get(2*node,l,c,i,j);
    pii t2 = get(2*node+1,c+1,r,i,j);
    if(t1.fi >= t2.fi) return t1;
    else return t2;
}

bool cmp(pii x,pii y)
{
    return (x.se < y.se || (x.se == y.se && x.fi > y.fi));
}

bool check(int mid)
{
    init(1,1,m);
    pii c[maxn];
    For(i,1,mid) c[i] = p[i];
    sort(c+1,c+1+mid,cmp);
    For(i,1,mid){
        pii cur = get(1,1,m,c[i].fi,c[i].se);
        if(cur.fi == -1) return false;
        update(1,1,m,cur.se,-1);
    }
    return true;
}

void AC()
{
    int l = 1, r = n;
    while(r - l > 1){
        int mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(check(r)) cout << r << endl;
    else cout << l << endl;
}

void duyet(int i)
{
    ans = max(ans,i-1);
    if(i > n) return;
    For(j,p[i].fi,p[i].se)
        if(!used[j]){
            used[j] = true;
            x[i] = j;
            duyet(i+1);
            used[j] = false;
        }
}


bool dfs(int u)
{
    if(vst[u] != q) vst[u] = q;
    else return false;
    vst[u] = q;
    for(int v : a[u])
        if(!match[v] || dfs(match[v])){
            match[v] = u;
            return true;
        }
    return false;
}

void Sub2()
{
    memset(match,0,sizeof(match));
    memset(vst,0,sizeof(vst));
    ans = 0;
    For(i,1,n) a[i].clear();
    q = 0;
    int cnt = 0;
    For(i,1,n){
        For(j,p[i].fi,p[i].se) a[i].push_back(j);
        q++;
        cnt += dfs(i);
        if(cnt == i) ans = max(ans,cnt);
        else break;
    }
    cout << ans << endl;
}

int main()
{
    freopen("QUEUE.inp","r",stdin);
    freopen("QUEUE.out","w",stdout);
    cin >> test;
    while(test--){
        scanf("%d%d",&m,&n);
        For(i,1,n){
            scanf("%d%d",&p[i].fi,&p[i].se);
        }
        if(m <= 300 && n <= 300){
            Sub2();
            continue;
        }
        else AC();
    }
}
