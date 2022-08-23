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

int n;
string S;
ll f[maxn];

bool check(int i)
{
    if(S[i-1] == 'N' && S[i] == 'W') return true;
    if(S[i-1] == 'W' && S[i] == 'S') return true;
    if(S[i-1] == 'S' && S[i] == 'E') return true;
    if(S[i-1] == 'E' && S[i] == 'N') return true;
    return false;
}

int main()
{
    fast_read;
    freopen("weather.inp","r",stdin);
    freopen("weather.out","w",stdout);
    cin >> S;
    n = S.size();
    S = '?' + S;
    f[0] = f[1] = 1;
    For(i,2,n)
    {
        f[i] = (f[i] + f[i-1])%mod;
        if(check(i)) f[i] = (f[i] + f[i-2])%mod;
    }
    cout << f[n] << endl;
}
