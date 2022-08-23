#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
using namespace std;



int main()
{
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&a[i]);
    Sang();
    For(i,1,n){
        b[i] = b[i-1];
        c[i] = c[i-1];
        if(!prime[a[i]]) b[i]++;
        else c[i]++;
        d[i] = {b[i] - c[i],i};
    }
    sort(d+1,d+1+n);
    //For(i,1,n) cout << d[i].fi << ' ' << d[i].se << endl;
    ll ans = 0;

    For(i,1,n){
        if(d[i].fi >= 0) ans++;
        //cout << i << ' ' << ans << endl;
        ans += get(d[i].se);
        //cout << i << ' ' << ans << endl;
        update(d[i].se);
    }
    cout << ans << endl;
}
/**
10
7 2 6 8 5 11 3 4 12 17
**/
