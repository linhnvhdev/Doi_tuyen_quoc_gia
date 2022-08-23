/// Code nay duoc sinh ra chi de quay xo so :)
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 5005
#define ll long long
#define INF 1e18
using namespace std;

int n;
int a[maxn],b[maxn];

int main()
{
    fast_read;
    freopen("bubbletea.inp","r",stdin);
    freopen("bubbletea.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> a[i];
        a[i] += 2000;
    }
    sort(a+1,a+1+n);
    int ans = 0;
    For(i,1,n)
    {
        ans++;
        if(a[i+1] - a[i] <= 2) i++;
    }
    cout << ans << endl;
}
