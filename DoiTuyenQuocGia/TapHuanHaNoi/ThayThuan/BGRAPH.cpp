#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 300005
using namespace std;

const ll mod = 998244353;

ll lt2[maxn];
int n,m,nhan[maxn],s[2];
vector<int> a[maxn];
int ok;

void dfs(int u,int cur)
{
    nhan[u] = cur;
    s[cur]++;
    for(int v : a[u])
    {
        int new_cur = (cur+1)%2;
        if(nhan[v] == -1) dfs(v,new_cur);
        else if(nhan[v] != new_cur) ok = 0;
    }
}

int main()
{
    memset(nhan,-1,sizeof(nhan));
    scanf("%d%d",&n,&m);
    For(i,1,m)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    lt2[0] = 1;
    For(i,1,n) lt2[i] = lt2[i-1]*2%mod;
    ll ans = 1;
    For(i,1,n)
        if(nhan[i] == -1)
        {
            ok = 1;
            s[0] = s[1] = 0;
            dfs(i,0);
            ll tmp = 0;
            For(k,0,1) tmp = (tmp + lt2[s[k]]*ok)%mod;
            ans = ans*tmp%mod;
        }
    cout << ans << endl;
}
