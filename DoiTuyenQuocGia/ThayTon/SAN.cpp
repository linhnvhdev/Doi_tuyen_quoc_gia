#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 45
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

int n;
ll k;

ll h[maxn],g[maxn];

vector<ll> a[maxn];

void Sub2()
{
    ll ans = 0;
    int m = n - n/2;
    for(int i = 1; i < (1 << (n/2));i++)
    {
        ll cur_h = 0, cur_money = 0;
        bool ok = true;
        int last_cot = 0;
        For(j,0,n/2-1)
            if(Bit(i,j))
            {
                if(cur_h > h[j+1]) {ok = false; break;}
                cur_h = h[j+1];
                last_cot = j+1;
                cur_money += g[j+1];
            }
        if(ok)
        {
            a[last_cot].push_back(cur_money);
            if(cur_money >= k) ans++;
        }
    }
    //cout << ans << endl;
    For(i,1,n/2) sort(a[i].begin(),a[i].end());
    for(int i = 1; i < (1 << m);i++)
    {
        ll cur_h = 0, cur_money = 0;
        int first_h = 0;
        bool ok = true;
        For(j,0,m-1)
            if(Bit(i,j))
            {
                if(first_h == 0) first_h = h[n/2+j+1];
                if(cur_h > h[n/2+j+1]) {ok = false; break;}
                cur_h = h[n/2+j+1];
                cur_money += g[n/2+j+1];
            }
        if(!ok) continue;
        if(cur_money >= k) ans++;
        For(j,1,n/2)
        {
            if(h[j] > first_h) continue;
            int vt = lower_bound(a[j].begin(),a[j].end(),k - cur_money) - a[j].begin();
            ans += a[j].size() - vt;
        }
    }
    cout << ans << endl;
}

void Sub1()
{
    ll ans = 0;
    for(int i = 0; i < (1 << n);i++)
    {
        ll cur_h = 0, cur_money = 0;
        bool ok = true;
        For(j,0,n-1)
            if(Bit(i,j))
            {
                if(cur_h > h[j+1]) {ok = false; break;}
                cur_h = h[j+1];
                cur_money += g[j+1];
            }
        if(ok && cur_money >= k) ans++;
    }
    cout << ans << endl;
    exit(0);
}

int main()
{
    freopen("SAN.inp","r",stdin);
    freopen("SAN.out","w",stdout);
    cin >> n >> k;
    For(i,1,n) cin >> h[i] >> g[i];
    if(n <= 20) Sub1();
    Sub2();
}
