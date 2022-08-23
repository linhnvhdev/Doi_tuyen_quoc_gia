#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

struct line
{
    ll a,b,c;
} p[maxn];

const int mod = 1e9+7;

int n,cnt = 0;
ll a[maxn],b[maxn],c[maxn];

map<pair<pair<ll,ll>,ll>,bool> mp;

bool checksongsong(int i,int j)
{
    return (p[i].a == p[j].a && p[i].b == p[j].b);
}

bool check(int i,int j,int k)
{
    if(checksongsong(i,j)) return false;
    if(checksongsong(i,k)) return false;
    if(checksongsong(j,k)) return false;
    return true;
}

void Sub1()
{
    int ans = 0;
    For(i,1,cnt)
        For(j,i+1,cnt)
            For(k,j+1,cnt)
            {
                if(check(i,j,k)) ans++;
            }
    cout << ans % mod << endl;
}

bool cmp(line x,line y)
{
    return (x.a < y.a || x.a == y.a && x.b < y.b);
}

ll tinh(ll k,ll n)
{
    if(k == 1) return n;
    if(k == 2) return (n*(n-1)/2)%mod;
    if(k == 3)
    {
        ll a[3] = {n,n-1,n-2};
        bool c1 = false,c2 = false;
        For(i,0,2)
        {
            if(a[i] % 2 == 0 && !c1)
            {
                a[i] /= 2;
                c1 = true;
            }
            if(a[i] % 3 == 0 && !c2)
            {
                a[i] /= 3;
                c2 = true;
            }
        }
        return (a[0]*a[1] % mod)*a[2]%mod;
    }
    return 0;
}

int main()
{
    fast_read;
    freopen("Tricount.inp","r",stdin);
    freopen("Tricount.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> a[i] >> b[i] >> c[i];
        ll d = __gcd(a[i],b[i]);
        d = abs(__gcd(d,c[i]));
        a[i] /= d;
        b[i] /= d;
        c[i] /= d;
        if(a[i] < 0) a[i]=-a[i],b[i]=-b[i],c[i]=-c[i];

        if(mp.find({{a[i],b[i]},c[i]}) != mp.end()) continue;
        //cout << " ## " << a[i] << ' ' << b[i] << endl;
        mp[{{a[i],b[i]},c[i]}] = true;
        d = abs(__gcd(a[i],b[i]));
        a[i] /= d;
        b[i] /= d;
        p[++cnt] = {a[i],b[i],c[i]};
    }
    sort(p+1,p+1+cnt,cmp);
    //For(i,1,cnt) cout << p[i].a << ' ' << p[i].b << endl;
    int i = 1;
    ll ans = 0;
    while(i <= cnt)
    {
        int j = i;
        while(j <= cnt && p[i].a == p[j].a && p[i].b == p[j].b) j++;
        ll ss = j-i;
        ans += tinh(3,ss) + tinh(2,ss)*(cnt - ss);
        ans %= mod;
        //cout << i << ' ' << j << ' ' << ' ' << ans << endl;
        i = j;
    }
    ans = (tinh(3,cnt) - ans + mod)%mod;
    cout << ans << endl;
}
