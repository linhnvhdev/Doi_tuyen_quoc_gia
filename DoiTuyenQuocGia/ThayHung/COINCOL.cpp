#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >=b ;i--)
#define maxn 1000005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

int n;
ll k,a[maxn];
pair<ll,int> sum[maxn];

int main()
{
    fast_read;
    freopen("COINCOL.inp","r",stdin);
    freopen("COINCOL.out","w",stdout);
    cin >> n >> k;
    For(i,1,n) cin >> a[i];
    sort(a+1,a+1+n);
    pair<int,ll> best = {1,a[1]};
    ll cur_sum = a[1];
    int cur_t = 1;
    For(i,2,n)
    {
        if(a[i] > cur_sum)
        {
            cur_sum += a[i];
            cur_t++;
            if(cur_sum == k)
            {
                cout << cur_sum << ' ' << cur_t << endl;
                return 0;
            }
            else if(cur_sum > k)
            {
                cout << cur_sum <
            }
        }
        else
        {
            cur_sum += a[i] - a[i-1];
            if(cur_sum > k) break;
        }
    }
}
