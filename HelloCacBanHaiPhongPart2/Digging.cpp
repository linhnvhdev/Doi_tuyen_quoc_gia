#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n;
ll T,a[maxn],b[maxn];

bool check(ll mid,int pos)
{
    ll tmp = 0,cur = mid;
    tmp = a[pos] - mid;
    if(tmp < 0) return false;
    For(i,pos+1,n){
        if(a[i] > cur+1){
            tmp += a[i] - (cur+1);
            cur++;
        }
        else cur = a[i];
    }
    Forr(i,pos-1,1){
        if(a[i] > cur+1){
            tmp += a[i] - (cur+1);
            cur++;
        }
        else cur = a[i];
    }
    return(tmp <= T);
}

int main()
{
    freopen("Digging.inp","r",stdin);
    freopen("Digging.out","w",stdout);
    cin >> n >> T;
    For(i,1,n)
        scanf("%lld",&a[i]);
    ll l = -1e9,r = 1e9;
    while(r - l > 1){
        ll mid = (l+r)/2;
        ll l1 = 1,r1 = n;

        if(check(mid)) r = mid;
        else l = mid;
    }
    if(check(l)) cout << l << endl;
    else cout << r << endl;
}
