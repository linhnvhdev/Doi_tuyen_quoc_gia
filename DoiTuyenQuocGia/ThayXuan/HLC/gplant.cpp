#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,q,cnt = 0;
int s[maxn],d[maxn],p[maxn],e[maxn];
int head[maxn],heavy[maxn],pos[maxn],rpos[maxn];
ll val[4*maxn],add[4*maxn];
vector<int> a[maxn];

void dfs(int u,int parent)
{
    s[u] = 1;
    int scmax = 0;
    for(int v : a[u])
    {
        if(v == parent) continue;
        p[v] = u;
        d[v] = d[u] + 1;
        dfs(v,u);
        s[u] += s[v];
        if(s[v] > scmax)
            heavy[u] = v, scmax = s[v];
    }
}

void hld(int u,int cur_head)
{
    head[u] = cur_head;
    pos[u] = ++cnt;
    if(heavy[u])
        hld(heavy[u],cur_head);
    for(int v : a[u])
        if(v != p[u] && v != heavy[u]) hld(v,v);
}

void down(int s,int d1,int d2)
{
    val[2*s] += add[s]*d1;
    val[2*s+1] += add[s]*d2;
    add[2*s] += add[s];
    add[2*s+1] += add[s];
    add[s] = 0;
}

void update(int s,int l,int r,int i,int j,int v)
{
    if(i > j) return;
    if(l > j || r < i) return;
    if(i <= l && r <= j)
    {
        val[s] += v*(r - l + 1);
        add[s] += v;
        return;
    }
    int c = (l+r)/2;
    down(s,c - l + 1,r - c);
    update(2*s,l,c,i,j,v);
    update(2*s+1,c+1,r,i,j,v);
    val[s] = val[2*s] + val[2*s+1];
}

ll get(int s,int l,int r,int i,int j)
{
    if(i > j) return 0;
    if(l > i || r < j) return 0;
    if(i <= l && r <= j) return val[s];
    int c = (l+r)/2;
    down(s,c-l+1,r-c);
    return get(2*s,l,c,i,j) + get(2*s+1,c+1,r,i,j);
}

void ADD(int u,int v)
{
    for(;head[u] != head[v]; u = p[head[u]])
    {
        if(d[head[u]] < d[head[v]]) swap(u,v);
        update(1,1,n,pos[head[u]],pos[u],1);
    }
    if(pos[u] > pos[v]) swap(u,v);
    update(1,1,n,pos[u] + 1,pos[v],1);
}

ll get_sum(int u,int v)
{
    ll ans = 0;
    for(;head[u] != head[v]; u = p[head[u]])
    {
        if(d[head[u]] < d[head[v]]) swap(u,v);
        ans += get(1,1,n,pos[head[u]],pos[u]);
    }
    if(pos[u] > pos[v]) swap(u,v);
    ans += get(1,1,n,pos[u] + 1,pos[v]);
    return ans;
}

int main()
{
    freopen("gplant.inp","r",stdin);
    freopen("gplant.out","w",stdout);
    scanf("%d%d",&n,&q);
    For(i,1,n-1)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    hld(1,1);
    For(i,1,q)
    {
        char type;
        int u,v;
        scanf(" %c%d%d",&type,&u,&v);
        if(type == 'P')
        {
            ADD(u,v);
        }
        else
        {
            printf("%lld\n",get_sum(u,v));
        }
    }
}
