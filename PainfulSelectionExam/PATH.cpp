#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
#define fi first
#define se second
using namespace std;

int m,n,k,cnt = 0;
vector<pair<int,ll> > a[maxn];
set<int> s[maxn];

pair<ll,pair<int,int> > edge[maxn];
priority_queue<pair<ll,pair<int,int> > > pq;

ll Solve()
{
    For(i,1,n) s[i].insert(i);
    int K = 0;
    while(!pq.empty()){
        int u = pq.top().se.fi;
        int v = pq.top().se.se;
        ll w = -pq.top().fi;
        //cerr << u << ' ' << v << ' ' << w <<endl ;
        pq.pop();
        if(s[u].find(v) == s[u].end()){
            s[u].insert(v);
            s[v].insert(u);
        }
        else continue;
        K++;
        //cout << K << endl;
        if(K == k) return w;
        for(int i = 0;i < a[u].size();i++){
            int v2 = a[u][i].fi;
            ll w2 = a[u][i].se;
            if(v2 == v || s[v2].find(v) != s[v2].end() || s[v2].find(v) != s[v2].end()) continue;
            pq.push({-(w2 + w),{v2,v}});
        }
        for(int i = 0;i < a[v].size();i++){
            int u2 = a[v][i].fi;
            ll w2 = a[v][i].se;
            if(u2 == u || s[u2].find(u) != s[u2].end() || s[u].find(u2) != s[u].end()) continue;
            pq.push({-(w2 + w),{u2,u}});
        }
    }
}

int main()
{
    freopen("PATH.inp","r",stdin);
    freopen("PATH.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    For(i,1,m){
        int u,v;
        ll w;
        scanf("%d%d%lld",&u,&v,&w);
        edge[i] = {w,{u,v}};
    }
    sort(edge+1,edge+1+m);
    ll MAX = edge[min(k,m)].fi;
    For(i,1,m){
        int u = edge[i].se.fi,v = edge[i].se.se;
        ll w = edge[i].fi;
        if(w > MAX) break;
        pq.push({-w,{u,v}});
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    cout << Solve() << endl;
}
