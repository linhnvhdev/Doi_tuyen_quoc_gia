#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 5005
#define ll long long
#define INF 1e18
using namespace std;

int n,m,a[maxn][maxn];
string s;
vector<ll> d[maxn];

int main()
{
    fast_read;
    cin >> n >> m;
    For(i,1,n)
    {
        cin >> s;
        For(j,1,m)
            a[i][j] = s[j-1] - '0';
    }
    For(i,1,n)
    {
        int cur = 0;
        Forr(j,m,1)
        {
            if(a[i][j] == 1)
                cur++;
            else cur = 0;
            d[j].push_back(cur);
        }
    }
    For(i,1,m) sort(d[i].begin(),d[i].end());
    ll ans = 0;
    For(i,1,m)
        For(j,0,n-1)
            ans = max(ans,1ll*d[i][j]*(n-j));
    cout << ans << endl;
}
