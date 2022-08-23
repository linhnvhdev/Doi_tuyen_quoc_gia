#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ull long long
#define fi first
#define se second
#define ll long long
using namespace std;

int n,m,st[maxn],ed[maxn],cnt = 0,logn = 0,depth[maxn];
vector<int> a[maxn];
int p[maxn][19];
ll val[2][maxn];

void dfs(int u)
{
    st[u] = ++cnt;
    for(auto v : a[u]){
        depth[v] = depth[u] + 1;
        dfs(v);
    }
    ed[u] = cnt;
}

void update(int pos,ll v,int k)
{
    for(int i = pos;i <= cnt;i += (i&(-i)))
        val[k][i] += v;
}

ll get(int pos,int k)
{
    ll tmp = 0;
    for(int i = pos;i > 0;i -= (i&(-i)))
        tmp += val[k][i];
    return tmp;
}

ll dist(int u)
{
    return get(st[u],0) + get(st[u],1)*depth[u];
}

int lca(int u,int v)
{
    if(depth[u] <= depth[v]) swap(u,v);
    Forr(i,18,0)
        if(depth[p[u][i]] >= depth[v]) u = p[u][i];
    if(u == v) return u;
    Forr(i,18,0)
        if(p[u][i] != p[v][i]){
            u = p[u][i];
            v = p[v][i];
        }
    return p[u][0];
}

void check()
{
    For(i,1,n) cerr << i << ' ' << dist(i) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("QTREE.inp","r",stdin);
    freopen("QTREE.out","w",stdout);
    cin >> n >> m;
    For(i,2,n){
        cin >> p[i][0];
        a[p[i][0]].push_back(i);
    }
    depth[1] = 1;
    p[1][0] = 0;
    dfs(1);
    For(j,1,18)
        For(i,1,n)
            p[i][j] = p[p[i][j-1]][j-1];
    For(i,1,m){
        int type,u,v,c;
        cin >> type;
        if(type == 1){
            cin >> u >> c;
            //cerr << "### " << type << ' ' << u << ' ' << c << endl;
            update(st[u],c,0);
            update(ed[u]+1,-c,0);
            //check();
        }
        if(type == 2){
            cin >> u >> c;
            //cerr << "### " << type << ' ' << u << ' ' << c << endl;
            update(st[u],(1-depth[u])*c,0);
            update(ed[u]+1,(depth[u]-1)*c,0);
            update(st[u],c,1);
            update(ed[u]+1,-c,1);
            //check();
        }
        if(type == 3){
            cin >> u;
            cout << dist(u) - dist(p[u][0]) << endl;
        }
        if(type == 4){
            cin >> u >> v;
            int s = lca(u,v);
            ll ans = dist(u) + dist(v) - dist(s) - dist(p[s][0]);
            cout << ans << endl;
        }
    }
    return 0;
}
