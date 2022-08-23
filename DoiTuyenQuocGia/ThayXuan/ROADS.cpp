#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 20006
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define pii pair<int,int>
using namespace std;

int n,a[maxn];
int in[maxn],f[maxn],nhan[maxn],cnt = 0,last[maxn];

bool used[maxn];

void dfs(int u)
{
    nhan[u] = cnt;
    used[u] = true;
    if(a[u] == -1)
    {
        last[cnt] = u;
        f[u] = 1;
        return;
    }
    if(nhan[a[u]] == cnt) return;
    dfs(a[u]);
    f[u] = f[a[u]]+1;
}

int main()
{
    fast_read;
    freopen("ROADS.inp","r",stdin);
    freopen("ROADS.out","w",stdout);
    cin >> n;
    For(i,0,n-1)
    {
        cin >> a[i];
        in[a[i]]++;
    }
    int u = 0,ans = 0;
    while(u != -1 && !used[u])
    {
        used[u] = true;
        ans++;
        u = a[u];
    }
    //For(i,0,n-1) cout << in[i] << ' ';
    //cout << endl;
    For(i,0,n) f[i] = -INF;
    memset(used,false,sizeof(used));
    For(i,0,n) last[i] = -1;
    For(i,0,n-1)
        if(in[i] == 0 && a[i] != -1)
        {
            cnt++;
            dfs(i);
        }
    For(i,0,n-1) if(!used[i])
    {
        cnt++;
        dfs(i);
    }
    int cur = ans;
    //cout << cur << endl;
    For(i,0,n-1)
        if(nhan[i] != nhan[0])
        {
            if(last[nhan[i]] == last[nhan[0]])
                f[i]--;
            //cout << i << ' ' << f[i] << endl;
            ans = max(ans,cur + f[i]);
        }
    cout << ans << endl;
}
