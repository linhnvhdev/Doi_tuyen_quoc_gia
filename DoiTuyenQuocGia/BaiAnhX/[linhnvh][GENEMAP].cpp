#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define INF 1e18
using namespace std;

const int mod = 1e9+7;
const int base = 128;

int n,k;
string s;

int len[maxn];
ll h[maxn][205],p[maxn];

int get(ll H[205],int i,int j)
{
    return ((H[j] - H[i-1]*p[j-i+1])%mod + mod)%mod;
}

pair<int,int> a[maxn];
int cnt = 0;

int main()
{
    fast_read;
    freopen("GENEMAP.inp","r",stdin);
    freopen("GENEMAP.out","w",stdout);
    cin >> n >> k;
    p[0] = 1;
    For(i,1,200) p[i] = p[i-1]*base%mod;
    For(i,1,n)
    {
        cin >> s;
        len[i] = s.size();
        for(int j = 0;j < len[i]; j++)
            h[i][j+1] = (h[i][j]*base + s[j]) % mod;
    }
    ll ans = 0;
    For(i,1,n)
    {
        if(len[i] < k) continue;
        int dau = get(h[i],1,k);
        int cuoi = get(h[i],len[i]-k+1,len[i]);
        a[++cnt] = {dau,cuoi};
    }
    sort(a+1,a+1+cnt);
    int curd = 1;
    For(i,2,cnt)
    {
        if(a[i] == a[i-1])
        {
            ans += curd;
            curd++;
        }
        else
            curd = 1;
    }
    curd = 1;
    cnt = 0;
    For(i,1,n)
    {
        if(len[i] < k+1) continue;
        int dau = get(h[i],1,k+1);
        int cuoi = get(h[i],len[i] - k,len[i]);
        a[++cnt] = {dau,cuoi};
    }
    sort(a+1,a+1+cnt);
    For(i,2,cnt)
    {
        if(a[i] == a[i-1])
        {
            ans -= curd;
            curd++;
        }
        else
            curd = 1;
    }
    cout << ans % mod << endl;
}
