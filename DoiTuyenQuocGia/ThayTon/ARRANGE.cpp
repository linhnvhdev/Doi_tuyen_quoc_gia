#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
#define x fi
#define y second
#define lf double
using namespace std;

int n;
ll a[maxn],sum = 0;

bool sub1 = true;

void Sub1()
{
    ll ans = 0;
    ll x = sum/n;
    For(i,1,n-1)
    {
        ll d = a[i] - x;
        ans += abs(d);
        a[i+1] += d;
    }
    cout << ans << endl;
}

void Sub2()
{
    ll ans = 0;
    ll x = sum/n;
    int dem = sum % n;
    For(i,1,n)
    {
        //cout << i << ' ' << a[i] << ' ' << ans << endl;
        ll d = a[i] - x;
        if(d == 0) continue;
        if(d == 1 && dem <= 0) continue;
        if(d < 0)
        {
            ans += abs(d);
            ll du = 0;
            For(j,1,n)
            {
                if(du >= d) break;
                if(a[j] > x)
                {
                    if(a[j] == x+1 && dem == 0) continue;
                    ll help = min(a[j] - x,d - du);
                    a[j] -= help;
                    du += help;
                    if(a[j] == x+1) dem--;
                }
            }
            a[i] = x;
        }
        else
        {
            if(dem > 0)
            {
                ans += a[i] - x - 1;
                a[i+1] += a[i] - x - 1;
                a[i] = x+1;
                dem--;
            }
            else
            {
                ans += a[i] - x;
                a[i+1] += a[i] - x;
                a[i] = x;
            }
        }
        //cout << i << ' ' << ans << endl;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ARRANGE.inp","r",stdin);
    freopen("ARRANGE.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> a[i];
        sum += a[i];
    }
    if(sum % n == 0) Sub1();
    else
        Sub2();

}
