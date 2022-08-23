#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,x[maxn],y[maxn];
map<pair<int,int>,int> mp;

int main()
{
    freopen("NOPARALLEL.inp","r",stdin);
    freopen("NOPARALLEL.out","w",stdout);
    cin >> n;
    For(i,1,n) cin >> x[i] >> y[i];
    ll ans = 0;
    For(i,1,n)
        For(j,i+1,n){
            int vtx = x[j] - x[i];
            int vty = y[j] - y[i];
            int d = __gcd(vtx,vty);
            vtx /= d;
            vty /= d;
            if(vtx < 0){
                vtx = -vtx;
                vty = -vty;
            }
            if(mp[{vtx,vty}] == 0){
                ans++;
                mp[{vtx,vty}]++;
            }
        }
    cout << ans << endl;
}
