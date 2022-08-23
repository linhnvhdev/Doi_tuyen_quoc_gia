#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 105
#define INF 1e9
using namespace std;

int n,m,p[maxn],h[maxn];
pair<ll,pair<int,int> > e[maxn];

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

pair<int,int> edge[maxn];

int used[maxn];
int g1,g2,g3,cnt = 0;

int main()
{
    cin >> n >> m;
    For(i,1,m)
        scanf("%d%d%d",&e[i].se.fi,&e[i].se.se,&e[i].fi);
    cin >> g1 >> g2 >> g3;
    ll ans = 0;
    sort(e+1,e+1+m);
    For(i,1,n) make_set(i);
    For(i,1,m){
        if(Union(e[i].se.fi,e[i].se.se)){
            edge[++cnt] = {e[i].se.fi,e[i].se.se};
            ans += e[i].fi;
            used[e[i].se.fi] = Find(e[i].se.fi);
            used[e[i].se.se] = Find(e[i].se.se);
            if(used[g1] != 0 && used[g1] == used[g2] && used[g1] == used[g3]) break;
        }
    }
    if(used[g1] != 0 && used[g1] == used[g2] && used[g1] == used[g3]){
        cout << "Yes\n";
        cout << ans << endl << cnt << endl;
        For(i,1,cnt) cout << edge[i].fi << ' ' << edge[i].se << endl;
    }
}
