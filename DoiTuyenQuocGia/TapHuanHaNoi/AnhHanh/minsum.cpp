/// Code nay duoc sinh ra chi de quay xo so :)
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 100005
#define ll long long
#define INF 1e18
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int t,n;
ll a,b;

vector<ll> g;

void phantich(ll a)
{
    for(int i = 2;i <= sqrt(a);i++)
    {
        if(a % i == 0)
        {
            int vt = -1,cnt = 0;
            while(a % i == 0)
            {
                a /= i;
                cnt++;
            }
            if(cnt % 2 == 0) continue;
            for(int j = 0;j < g.size();j++) if(g[j] == i) {vt = j; break;}
            if(vt == -1) g.push_back(i);
            else g.erase(g.begin() + vt);
        }
    }
    if(a != 1)
    {
        int vt = -1;
        for(int j = 0;j < g.size();j++) if(g[j] == a) {vt = j; break;}
        if(vt == -1) g.push_back(a);
        else g.erase(g.begin() + vt);
    }
}

int main()
{
    fast_read;
    freopen("minsum.inp","r",stdin);
    freopen("minsum.out","w",stdout);
    cin >> t;
    while(t--)
    {
        g.clear();
        cin >> a >> b;
        phantich(a);
        phantich(b);
        ll ans = INF;
        pair<ll,ll> best = {1,1};
        int m = g.size();
//        For(i,0,m-1) cout << g[i] << ' ';
//        cout << endl;
        for(int i = 0;i < (1<<m);i++)
        {
            ll x = 1, y = 1;
            For(j,0,m-1)
                if(Bit(i,j)) x *= g[j];
                else y *= g[j];
            if(x + y < ans)
            {
                ans = x+y;
                best = {x,y};
            }
        }
        cout << best.fi << ' ' << best.se << endl;
    }
}
