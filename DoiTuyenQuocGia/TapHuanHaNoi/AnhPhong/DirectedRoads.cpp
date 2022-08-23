#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define INF 1e18
using namespace std;

const int mod = 1e9+7;

int n,a[maxn];

int vst[maxn];

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n)
        cin >> a[i];
    ll pw[maxn];
    pw[0] = 1;
    For(i,1,n) pw[i] = pw[i-1]*2%mod;
    int cnt = n;
    ll ans = 1;
    For(i,1,n)
        if(vst[i] == 0)
        {
            int x = i;
            while(true)
            {
                vst[x] = i;
                x = a[x];
                if(vst[x]) break;
            }
            if(vst[x] != i) continue;
            int y = x,d = 0;
            while(true)
            {
                y = a[y];
                cnt--;
                d++;
                if(x == y) break;
            }
            ans = ans*(pw[d]-2)%mod;
        }
    ans = ans*pw[cnt]%mod;
    cout << ans << endl;
    return 0;
}
