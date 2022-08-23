#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 5005
#define ll long long
#define INF 1e9
using namespace std;

int n;
int a[maxn];
int ans = 1000;

int check(int i)
{
    int D = -1;
    For(j,1,n)
    {
        if(a[j] == i) continue;
        int cur = abs(i - a[j]);
        if(D == -1) D = cur;
        else if(D != cur) return -1;
    }
    return max(D,0);
}

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n)
        cin >> a[i];
    For(i,1,101)
    {
        int k = check(i);
        if(k != -1) ans = min(ans,k);
    }
    if(ans == 1000) cout << -1 << endl;
    else cout << ans << endl;
}
