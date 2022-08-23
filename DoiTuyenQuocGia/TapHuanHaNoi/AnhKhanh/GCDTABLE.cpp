///https://codeforces.com/contest/583/problem/C
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
using namespace std;

int n,m = 0;
int ans[maxn];

map<int,int> mp;

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n*n)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    while(m < n)
    {
        auto it = (--mp.end());
        ans[++m] = it->first;
        it->second--;
        if(it->second == 0) mp.erase(it);
        For(i,1,m-1)
        {
            int d = __gcd(ans[i],ans[m]);
            mp[d] -= 2;
            if(mp[d] == 0) mp.erase(d);
        }
    }
    For(i,1,n) cout << ans[i] << ' ';
}
