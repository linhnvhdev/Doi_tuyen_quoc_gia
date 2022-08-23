#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 10005
#define ll long long
#define fi first
#define se second
#define INF 1e9+1
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

const int mod = 1e9+7;
const int base = 128;

string S;
int k,q,n;
ll h1[maxn],h2[maxn],p[maxn];
int f[10005][10005];

ll get_hash(ll h[maxn],int i,int j)
{
    return ((h[j] - h[i-1]*p[j-i+1])%mod + mod) % mod;
}

void Sub1()
{
    For(i,1,q)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int st = l-1,ed = r-1,ans = 0;
        while(st <= ed)
        {
            if(S[st] != S[ed]) ans++;
            st++;
            ed--;
        }
        cout << ((ans <= k) ? 1 : 0) << endl;
    }
    exit(0);
}

bool check(int l,int r)
{
    ll t1 = get_hash(h1,l,r);
    ll t2 = get_hash(h2,n - r + 1,n - l + 1);
    return (t1 == t2);
}

void Sub2()
{
    p[0] = 1;
    For(i,1,n)
    {
        p[i] = p[i-1]*base%mod;
        h1[i] = (h1[i-1]*base + S[i-1])%mod;
    }
    reverse(S.begin(),S.end());
    For(i,1,n) h2[i] = (h2[i-1]*base + S[i-1])%mod;
    For(i,1,q)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(check(l,r)) printf("1\n");
        else printf("0\n");
    }
    exit(0);
}

int Solve(int i,int j)
{
    if(i == j) return 1;
    if(f[i][j]) return f[i][j]+1;
    if(i+1 == j)
    {
        f[i][j] = (S[i] != S[j]);
        return f[i][j] + 1;
    }
    if(check(i,j))
    {
        f[i][j] = 0;
        return 1;
    }
    int add = (S[i] != S[j]);
    f[i][j] = add + Solve(i+1,j-1) - 1;
    return f[i][j] + 1;
}

void Sub3()
{
    p[0] = 1;
    For(i,1,n)
    {
        p[i] = p[i-1]*base%mod;
        h1[i] = (h1[i-1]*base + S[i-1])%mod;
    }
    reverse(S.begin(),S.end());
    For(i,1,n) h2[i] = (h2[i-1]*base + S[i-1])%mod;
    reverse(S.begin(),S.end());
    For(i,1,q)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int d = Solve(l-1,r-1) - 1;
        //cout << l << ' ' << r << ' ' << d << endl;
        if(d <= k) printf("1\n");
        else printf("0\n");
    }
}

int main()
{
    freopen("LRKPALIN.inp","r",stdin);
    freopen("LRKPALIN.out","w",stdout);
    cin >> S;
    n = S.size();
    cin >> k >> q;
    if(n <= 100) Sub1();
    if(k == 0) Sub2();
    Sub3();
}
