#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define fi first
#define se second
#define maxn 200005
#define ll long long
#define INF 1e9
#define pii pair<int,int>
using namespace std;

int n;
ll a[maxn];

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n)
        cin >> a[i];
    queue<pair<ll,int> > curset,subset;
    int ans = 0;
    For(i,1,n)
    {
        while(!curset.empty())
        {
            ll u = curset.front().fi;
            int sl = curset.front().se;
            curset.pop();
            ll d = __gcd(u,a[i]);
            ans = max(ans,sl);
            ll val = u/d;
            if(d != 1)
                subset.push({d,sl+1});
            if(val != 1)
                subset.push({val,sl});
        }
        while(!subset.empty())
        {
            curset.push(subset.front());
            subset.pop();
        }
        curset.push({a[i],1});
    }
    while(!curset.empty())
    {
        ans = max(ans,curset.front().se);
        curset.pop();
    }
    cout << ans << endl;
}
