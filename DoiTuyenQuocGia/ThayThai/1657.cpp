#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(long long i = a; i <= b; ++i)
#define maxn 100005
using namespace std;

ll n,m,ans = 1,tmp = 1;
ll val[maxn];

void check(ll x, ll add)
{
    For(i,2,sqrt(x))
        while(x % i == 0)
        {
            val[i] += add;
            x /= i;
        }
    if(x != 0)
        val[x] += add;
}

ll get(ll a, ll b){
    ll cur = 1, i = 1ll * a;
    while(b > 0)
    {
        if(b % 2 == 1)cur = (cur * i) % m;
        i = (i * i) % m;
        b /= 2;
    }
    return cur % m;
}
int main()
{
    cin>>n>>m;
    For(i,1,n)
        ans = ans * i % m;
    For(i,n + 2, 2 * n)
        check(i, 1);
    For(i,1,n)
        check(i, -1);
    For(i,1,50000)
        tmp = (tmp * get(i, val[i])) % m;
    cout<< (ans - tmp + m) % m << '\n';
}
