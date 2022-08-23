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

ll x[5];

int main()
{
    fast_read;
    For(i,1,4) cin >> x[i];
    sort(x+1,x+1+4);
    For(i,1,3) cout << x[4] - x[i] << ' ';
    return 0;
}
