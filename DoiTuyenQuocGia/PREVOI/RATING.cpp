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

int T,n,q;
ll a[maxn],sum[maxn],MAXA = 0;

ll get_sum(int i,int j)
{
    return sum[j] - sum[i-1];
}

void Sub1()
{
    ll x;
    int l,r;
    For(i,1,q)
    {
        cin >> x >> l >> r;
        For(j,l,r)
            x = abs(x - a[j]);
        cout << x << endl;
    }
}

bool sub3 = true;

void Sub3()
{
    For(i,1,q)
    {
        ll x;
        int u,v;
        cin >> x >> u >> v;
        //cerr << i << ' ' << x << ' ' << u << ' ' << v << endl;
        if(x >= get_sum(u,v))
        {
            cout << x - get_sum(u,v) << endl;
            continue;
        }
        int l = u,r = v;
        while(r - l > 1)
        {
            int mid = (l+r)/2;
            if(x >= get_sum(u,mid)) l = mid;
            else r = mid;
        }
        int du = 0;
        if(x < a[u]) du = v - u + 1;
        else {x -= get_sum(u,l); du = v - l;}
        if(du % 2 == 0) cout << x << '\n';
        else cout << abs(x - a[u]) << '\n';
    }
}

int main()
{
    fast_read;
    freopen("RATING.inp","r",stdin);
    freopen("RATING.out","w",stdout);
    cin >> T;
    while(T--)
    {
        MAXA = 0;
        cin >> n >> q;
        For(i,1,n)
        {
            cin >> a[i];
            MAXA = max(MAXA,a[i]);
            sum[i] = sum[i-1] + a[i];
            if(i > 1 && a[i] != a[i-1]) sub3 = false;
        }
        if(n <= 5000 && q <= 5000) Sub1();
        else
            if(MAXA <= 1000 || sub3) Sub3();
    }
}
