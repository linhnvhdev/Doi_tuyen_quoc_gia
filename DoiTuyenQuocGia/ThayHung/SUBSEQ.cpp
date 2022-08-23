#include <bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 400005
#define fi first
#define se second
#define INF 1e18
#define ll long long
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n;
ll S,a[maxn];
int val[4*maxn],f[maxn];

void Sub1()
{
    For(i,1,n) f[i] = 1;
    For(i,2,n)
    {
        For(j,1,i-1)
            if(abs(a[i] - a[j]) <= S)
                f[i] = max(f[i],f[j] + 1);
    }
    pair<ll,int> best = {0,0};
    For(i,1,n)
        if(f[i] > best.fi) best = {f[i],i};
    int u = best.se;
    vector<int> ans;
    ans.push_back(a[u]);
    while(f[u] > 1)
    {
        Forr(i,u-1,1)
            if(abs(a[i] - a[u]) <= S && f[u] == f[i] + 1)
            {
                ans.push_back(a[i]);
                u = i;
                break;
            }
    }
    cout << ans.size() << endl;
    for(int i = ans.size()-1;i >= 0;i--)
        cout << ans[i] << ' ';
    cout << endl;
}

ll d[maxn],b[maxn];
int N = 0;

void compress()
{
    For(i,1,n)
    {
        d[++N] = a[i];
        d[++N] = a[i] - S;
        d[++N] = a[i] + S;
    }
    sort(d+1,d+1+N);
    N = unique(d+1,d+1+N) - d;
    For(i,1,n)
    {
        b[i] = lower_bound(d+1,d+1+N,a[i]) - d;
        ///cerr << b[i] << ' ';
    }
}

int pos(ll x)
{
    return lower_bound(d+1,d+1+N,x) - d;
}

void update(int node,int l,int r,int i,int v)
{
    if(l > i || r < i) return;
    if(l == r)
    {
        val[node] = max(val[node],v);
        return;
    }
    int c = (l+r)/2;
    update(2*node,l,c,i,v);
    update(2*node+1,c+1,r,i,v);
    val[node] = max(val[2*node],val[2*node+1]);
}

int get(int node,int l,int r,int i,int j)
{
    if(l > j || r < i) return -1e9;
    if(i <= l && r <= j) return val[node];
    int c = (l+r)/2;
    return max(get(2*node,l,c,i,j),get(2*node+1,c+1,r,i,j));
}

int dp[maxn];

void Sub2()
{
    compress();
    For(i,1,n)
    {
        f[b[i]] = 1;
        dp[i] = 1;
        int t = get(1,1,N,pos(a[i] - S),pos(a[i] + S));
        ///cerr << b[i] << ' ' << pos(a[i] - S) << ' ' << pos(a[i] + S) << ' ' << t << endl;
        f[b[i]] = max(f[b[i]],t + 1);
        dp[i] = f[b[i]];
        update(1,1,N,b[i],f[b[i]]);
    }
    pair<ll,int> best = {0,0};
    For(i,1,n)
        if(dp[i] > best.fi) best = {dp[i],i};
    int u = best.se;
    vector<int> ans;
    ans.push_back(a[u]);
    while(dp[u] > 1)
    {
        Forr(i,u-1,1)
            if(abs(a[i] - a[u]) <= S && dp[u] == dp[i] + 1)
            {
                ans.push_back(a[i]);
                u = i;
                break;
            }
    }
    cout << ans.size() << endl;
    for(int i = ans.size()-1;i >= 0;i--)
        cout << ans[i] << ' ';
}

int main()
{
    fast_read;
    freopen("SUBSEQ.inp","r",stdin);
    freopen("SUBSEQ.out","w",stdout);
    cin >> n >> S;
    For(i,1,n) cin >> a[i];
    if(n <= 5000) Sub1();
    else Sub2();
}
