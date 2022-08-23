#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 100005
#define ll long long
#define INF 1e18
using namespace std;

const int mod = 1e9+7;

ll C;
string Cs;

bool used[maxn];

int a[maxn];
int h[maxn][10][2];
ll f[maxn][10][2];

bool check(int k)
{
    int pre = -1;
    while(k > 0)
    {
        int cs = k % 10;
        k /= 10;
        if(pre == cs) return false;
        pre = cs;
    }
    return true;
}

void Sub1()
{
    int n = Cs.size();
    for(int i = 0;i < Cs.size();i++)
        C = C*10 + Cs[i] - '0';
    int st = 1,ans = 0;
    For(i,1,n-1) st*=10;
    For(i,st,C)
    {
        if(C - i < st) break;
        if(check(i) && check(C-i))
            ans++;
    }
    cout << ans << endl;
}

void AC()
{
    int n = Cs.size();
    For(i,1,n)
        a[i] = Cs[n-i]-'0';
    For(i,1,n)
        For(j,0,9)
            For(k,0,1)
                h[i][j][k] = (a[i] - j - k + 10)%10;
    For(j,0,9) f[1][j][0] = 1;
    For(i,2,n)
    {
        For(j,0,9)
        {
            if(i == n && j == 0) continue;
            For(k,0,a[i-1])
            {
                if(k == j) continue;
                if(h[i][j][0] == h[i-1][k][0]) continue;
                f[i][j][0] = (f[i][j][0] + f[i-1][k][0]) % mod;
            }
            For(k,a[i-1]+1,9)
            {
                if(k == j) continue;
                if(h[i][j][1] == h[i-1][k][0]) continue;
                f[i][j][1] = (f[i][j][1] + f[i-1][k][0]) % mod;
            }
            For(k,0,a[i-1]-1)
            {
                if(k == j) continue;
                if(h[i][j][0] == h[i-1][k][1]) continue;
                f[i][j][0] = (f[i][j][0] + f[i-1][k][1]) % mod;
            }
            For(k,a[i-1],9)
            {
                if(k == j) continue;
                if(h[i][j][1] == h[i-1][k][1]) continue;
                f[i][j][1] = (f[i][j][1] + f[i-1][k][1]) % mod;
            }
        }
    }
    ll ans = 0;
    For(j,1,a[n]-1)
    {
        ll val0 = f[n][j][0];
        ll val1 = (j == a[n]-1) ? 0 : f[n][j][1];
        ans = (ans + val1 + val0) % mod;
    }
    cout << ans << endl;
}

int main()
{
    fast_read;
    freopen("APLUSB.inp","r",stdin);
    freopen("APLUSB.out","w",stdout);
    cin >> Cs;
    if(Cs[0] == '1')
    {
        cout << 0 << endl;
        return 0;
    }
    if(Cs.size() <= 6) Sub1();
    else
        AC();
}
