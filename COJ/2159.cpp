#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define maxn 100005
#define INF 1e9
using namespace std;

int n,m,q,s,t,k,d[maxn];
vector<pii> a[maxn];

bool check(int mid)
{
    For(i,1,n) d[i] = INF;
    d[s] = 0;
    queue<pii> pq;
    pq.push({0,s});
    while(!pq.empty()){
        int u = pq.front().se;
        int cur_d = -pq.front().fi;
        pq.pop();
        if(cur_d > d[u]) continue;
        if(u == t) return true;
        for(int i = 0;i < a[u].size();i++){
            int v = a[u][i].fi,w = (a[u][i].se > mid) ? 1 : 0;
            if(d[u] + w < d[v] && d[u] + w <= k){
                d[v] = d[u] + w;
                pq.push({-d[v],v});
            }
        }
    }
    return false;
}

int Solve()
{
    int l = 0, r = 1e9;
    while(r - l > 1){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(check(l)) return l;
    else return r;
}

int main()
{
    scanf("%d%d",&n,&m);
    For(i,1,m){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    scanf("%d",&q);
    For(i,1,q){
        scanf("%d%d%d",&s,&t,&k);
        printf("%d\n",Solve());
    }
}
