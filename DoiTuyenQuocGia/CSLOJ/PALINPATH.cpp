#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 50005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

const int mod = 1e9+7;
const int base = 128;

int n;
string s;

vector<int> a[maxn];

ll h[3005][3005];

int d[3005][3005];

void dfs(int cur,int u,int p)
{
    for(int v : a[u])
    {
        if(v == p) continue;
        h[cur][v] = (h[cur][u]*base + s[v-1]) % mod;
        d[cur][v] = d[cur][u] + 1;
        dfs(cur,v,u);
    }
}

void Sub1()
{
    For(i,1,n)
        dfs(i,i,0);
    int ans = 1;
    For(i,1,n)
        For(j,i+1,n)
            if(h[i][j] == h[j][i]) ans = max(ans,d[i][j]+1);
    cout << ans << '\n';
}

bool sub2 = true;

int d1[maxn],d2[maxn];

void Sub2()
{
    for(int i = 0,l = 0,r = -1;i < n;i++)
    {
        int k = (i > r) ? 1 : min(d1[l+r-i],r-i+1);
        while(0 <= i - k && i + k < n && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i + k > r)
        {
            r = i + k;
            l = i - k;
        }
    }
    for(int i = 0,l = 0,r = -1;i < n;i++)
    {
        int k = (i > r) ? 0 : min(d2[l+r-i+1],r-i+1);
        while(0 <= i - k - 1 && i + k < n && s[i-k-1] == s[i+k]) k++;
        d2[i] = k--;
        if(i + k > r)
        {
            r = i + k;
            l = i - k - 1;
        }
    }
    int ans = max(*max_element(d1,d1+n)*2-1,*max_element(d2,d2+n)*2);
    cout << ans << endl;
}

int main()
{
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
    fast_read;
    cin >> n >> s;
    For(i,1,n-1)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        if(abs(u - v) != 1) sub2 = false;
    }
    if(n <= 3000) Sub1();
    else
        if(sub2) Sub2();
}
