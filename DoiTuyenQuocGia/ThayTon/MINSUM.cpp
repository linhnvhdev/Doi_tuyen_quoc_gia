#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int t;
ll a,b;

vector<ll> uoc;

void phantich(ll n)
{
    for(int i = 2;i <= sqrt(n);i++)
    {
        if(n % i == 0)
        {
            int cnt = 0;
            while(n % i == 0)
            {
                n /= i;
                cnt++;
            }
            if(cnt % 2 == 0) continue;
            int vt = -1;
            for(int j = 0;j < uoc.size();j++)
                if(i == uoc[j]) {vt = j; break;}
            if(vt == -1) uoc.push_back(i);
            else uoc.erase(uoc.begin() + vt);
        }
    }
    if(n != 1)
    {
        int vt = -1;
        for(int j = 0;j < uoc.size();j++)
            if(n == uoc[j]) {vt = j; break;}
        if(vt == -1) uoc.push_back(n);
        else uoc.erase(uoc.begin() + vt);
    }
}

int main()
{
    fast_read;
    freopen("MINSUM.inp","r", stdin);
    freopen("MINSUM.out","w", stdout);
    cin >> t;
    while(t--)
    {
        uoc.clear();
        cin >> a >> b;
        phantich(a);
        phantich(b);
        int m = uoc.size();
        ll ans = INF;
        pair<ll,ll> best = {1,1};
        for(int i = 0;i < (1<<m);i++)
        {
            ll t1 = 1,t2 = 1;
            For(j,0,m-1)
            {
                if(Bit(i,j)) t1*=uoc[j];
                else t2*=uoc[j];
            }
            if(t1 + t2 < ans)
            {
                ans = t1 + t2;
                best = {t1,t2};
            }
        }
        cout << best.fi << ' ' << best.se << '\n';
    }
}
