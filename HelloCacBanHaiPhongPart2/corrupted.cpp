#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

struct query{
    char type;
    int c;
    int d,x,trc;
} Q[maxn];

int n,m,q,p[maxn],h[maxn],sz = 0;
ll w[maxn],s[maxn],cur_w[maxn];
pair<int,int> edge[maxn];
set<pair<ll,int> > S;
ll ans[maxn];

bool used[maxn];

void Make_set(int i)
{
    p[i] = i;
    h[i] = 0;
    s[i] = cur_w[i];
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

int Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return 0;
    if(h[x] < h[y]){
        p[x] = y;
        s[y] += s[x];
        return y;
    }
    else{
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
        s[x] += s[y];
        return x;
    }
}

void Get(int i)
{
    while(true){
        set<pair<ll,int> >::iterator it = S.end();
        it--;
        if((*it).fi != s[(*it).se]){
            S.erase(it);
            it--;
            continue;
        }
        ans[i] = (*it).fi;
        return;
    }
}

int main()
{
    freopen("corrupted.inp","r",stdin);
    freopen("corrupted.out","w",stdout);
    scanf("%d%d%d",&n,&m,&q);
    For(i,1,n) scanf("%d",&w[i]);
    For(i,1,m) scanf("%d%d",&edge[i].fi,&edge[i].se);
    For(i,1,n) cur_w[i] = w[i];
    For(i,1,q){
        cin >> Q[i].type;
        if(Q[i].type == 'D'){
            scanf("%d",&Q[i].c);
            used[Q[i].c] = true;
        }
        else{
            scanf("%d%d",&Q[i].d,&Q[i].x);
            Q[i].trc = cur_w[Q[i].d];
            cur_w[Q[i].d] = Q[i].x;
        }
    }
    For(i,1,n)
        Make_set(i);
    For(i,1,m)
        if(!used[i])
            Union(edge[i].fi,edge[i].se);
    For(i,1,n){
        int goc = Find(i);
        S.insert({s[goc],goc});
    }
    Forr(i,q,1){
        if(Q[i].type == 'D'){
            Get(i);
            int canh = Q[i].c;
            int g1 = Find(edge[canh].fi),g2 = Find(edge[canh].se);
            int goc = Union(edge[canh].fi,edge[canh].se);
            if(goc){
                S.erase({s[g2],g2});
                S.erase({s[g1],g1});
                S.insert({s[goc],goc});
            }
        }
        else{
            Get(i);
            int goc = Find(Q[i].d);
            S.erase({s[goc],goc});
            s[goc] = s[goc] - Q[i].x + Q[i].trc;
            S.insert({s[goc],goc});
        }
    }
    For(i,1,q) printf("%lld\n",ans[i]);
    return 0;
}
