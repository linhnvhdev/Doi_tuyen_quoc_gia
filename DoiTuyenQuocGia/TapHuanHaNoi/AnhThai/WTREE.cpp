#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int n,p[maxn],h[maxn],s[maxn],q[maxn],Q;
int ans[maxn];
pii event[maxn];
vector<int> a[maxn];

bool used[maxn];

void make_set(int i)
{
    p[i] = i;
    h[i] = 0;
    s[i] = 1;
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

ll Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return 0;
    ll tmp = 0;
    if(h[x] < h[y])
    {
        p[x] = y;
        tmp = s[y]*s[x];
        s[y] += s[x];
    }
    else
    {
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
        tmp = s[x]*s[y];
        s[x] += s[y];
    }
    return tmp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("WTREE.inp","r",stdin);
    freopen("WTREE.out","w",stdout);
    cin >> n;
    For(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        event[i] = {u,v};
    }
    cin >> Q;
    For(i,1,Q)
    {
        cin >> q[i];
        used[q[i]] = true;
    }
    For(i,1,n) make_set(i);
    For(i,1,n-1) if(!used[i])
        Union(event[i].fi,event[i].se);
    Forr(i,Q,1)
    {
        int u = event[q[i]].fi;
        int v = event[q[i]].se;
        ans[i] = Union(u,v);
    }
    For(i,1,Q) cout << ans[i] << '\n';
}
