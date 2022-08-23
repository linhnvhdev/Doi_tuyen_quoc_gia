#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define fi first
#define se second
#define ll long long
using namespace std;

int n;
ll a[maxn],K,Sum[maxn],bit[maxn],b[maxn];
pair<ll,int> s[maxn];
ll ans = 0;

void Sub1()
{
    Sum[0] = 0;
    For(i,1,n) Sum[i] = Sum[i-1] + b[i];
    For(i,1,n)
        For(j,i,n)
            if(Sum[j] - Sum[i-1] >= 0) ans++;
    cout << ans << endl;
    exit(0);
}

void Update(int pos)
{
    for(int i = pos;i <= n; i += (i & (-i)))
        bit[i]++;
}

ll get(int pos)
{
    ll test = 0;
    for(int i = pos;i > 0;i -= (i & (-i)))
        test += bit[i];
    return test;
}

void Solved()
{
    ans = 0;
    For(i,1,n){
        s[i] = {Sum[i],i};
        if(Sum[i] >= 0) ans++;
    }
    sort(s+1,s+1+n);
    For(i,1,n){
        //cout << i << ' ' << s[i].fi << ' ' << s[i].se << endl;
        ans += get(s[i].se);
        //cout << "^^\n";
        Update(s[i].se + 1);
    }
    cout << ans << endl;
}

int main()
{
    freopen("BAI1.inp","r",stdin);
    freopen("BAI1.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n)
        scanf("%lld",&a[i]);
    scanf("%lld",&K);
    For(i,1,n){
        b[i] = a[i] - K;
        Sum[i] = Sum[i-1] + b[i];
    }
    if(n <= 5000) Sub1();
    Solved();
}
