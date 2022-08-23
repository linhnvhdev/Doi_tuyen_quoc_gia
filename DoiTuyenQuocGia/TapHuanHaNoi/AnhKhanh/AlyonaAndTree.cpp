///https://codeforces.com/contest/583/problem/C
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define INF 1e9
using namespace std;

int n;
ll c[maxn];
int s[maxn],d[maxn],p[maxn],heavy[maxn],head[maxn];
int pos[maxn],rpos[maxn],cnt = 0,nhan[maxn];
ll dist[maxn],add[4*maxn],ans[4*maxn],kq[maxn];

vector<pair<int,ll> > a[maxn];

void dfs(int u,int parent)
{
    s[u] = 1;
    int sconmax = 0;
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi;
        ll w = a[u][i].se;
        if(v == parent) continue;
        d[v] = d[u]+1;
        dist[v] = dist[u] + w;
        p[v] = u;
        dfs(v,u);
        s[u] += s[v];
        if(s[v] > sconmax)
            heavy[u] = v,sconmax = s[v];
    }
}

void hld(int u,int cur_head)
{
    head[u] = cur_head;
    pos[u] = ++cnt; rpos[cnt] = u;
    if(heavy[u])
        hld(heavy[u],cur_head);
    for(int i = 0;i < a[u].size();i++)
    {
        int v = a[u][i].fi;
        if(v != p[u] && v != heavy[u])
            hld(v,v);
    }
}

void down(int s,int d1,int d2)
{
    ans[2*s] += d1*add[s];
    ans[2*s+1] += d2*add[s];
    add[2*s] += add[s];
    add[2*s+1] += add[s];
    add[s] = 0;
}

void update(int s,int l,int r,int i,int j,ll v)
{
    if(l > j || r < i) return;
    if(i <= l && r <= j)
    {
        ans[s] += v*(r - l + 1);
        add[s] += v;
        return;
    }
    int c = (l+r)/2;
    down(s,c-l+1,r-c);
    update(2*s,l,c,i,j,v);
    update(2*s+1,c+1,r,i,j,v);
    ans[s] = max(ans[s],ans[2*s+1]);
}

int get(int s,int l,int r,int i,int j)
{
    if(l > j || r < i) return INF;
    if(i <= l && r <= j) return ans[s];
    int c = (l+r)/2;
    down(s,c-l+1,r-c);
    return min(get(2*s,l,c,i,j),get(2*s+1,c+1,r,i,j));
}

ll DIST(int u,int v)
{
    return dist[v] - dist[u];
}

void Solve(int u)
{
    int cur_u = u;
    while(u != 0)
    {
        if(DIST(head[u],cur_u) <= c[cur_u])
            update(1,1,n,pos[head[u]],pos[u],1);
        else
        {
            int l = pos[head[u]],r = pos[u],tmp = -1;
            while(r - l > 1)
            {
                int mid = (l+r)/2;
                if(DIST(rpos[mid],cur_u) <= c[cur_u]) r = mid;
                else l = mid;
            }
            if(DIST(rpos[r],cur_u) <= c[cur_u]) tmp = r;
            else if(DIST(rpos[l],cur_u) <= c[cur_u]) tmp = l;
            if(tmp != -1)
                update(1,1,n,tmp,pos[u],1);
            break;
        }
        u = p[head[u]];
    }
    return;
}

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n)
        cin >> c[i];
    For(i,2,n)
    {
        int u,w;
        cin >> u >> w;
        a[u].push_back({i,w});
        a[i].push_back({u,w});
    }
    dfs(1,0);
    hld(1,1);
    For(i,1,n) Solve(i);
    For(i,1,n)
        cout << get(1,1,n,pos[i],pos[i]) - 1 << ' ' ;
}
