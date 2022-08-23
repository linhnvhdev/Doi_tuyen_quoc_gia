#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,cnt = 0;
map<string,int> mp;

string s;
ll price,quality,b;

struct computer{
    int id;
    ll p,q;
} a[maxn];

ll money[maxn];

bool check(ll mid)
{
    int dem = 0;
    ll tien = 0;
    For(i,1,cnt) money[i] = INF;
    For(i,1,n)
        if(a[i].q >= mid)
            money[a[i].id] = min(money[a[i].id],a[i].p);
    For(i,1,cnt){
        if(!money[i]) return false;
        tien += money[i];
        if(tien > b) return false;
    }
    return true;
}

int main()
{
    scanf("%d%lld",&n,&b);
    For(i,1,n){
        cin >> s;
        scanf("%lld%lld",&price,&quality);
        if(mp.find(s) == mp.end())
            mp[s] = ++cnt;
        a[i] = {mp[s],price,quality};
    }
    ll l = 0,r = 1e9;
    while(r - l > 1){
        int mid = (l+r)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(check(r))cout << r << endl;
    else cout << l << endl;
}
