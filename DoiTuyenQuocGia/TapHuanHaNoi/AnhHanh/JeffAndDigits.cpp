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

int d5,d0,n;

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n)
    {
        int a;
        cin >> a;
        if(a == 5) d5++;
        else d0++;
    }
    d5 = d5 - (d5%9);
    if(d5 == 0)
    {
        if(d0 != 0) cout << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }
    if(d0 == 0) cout << -1 << endl;
    else
    {
        For(i,1,d5) cout << 5;
        For(i,1,d0) cout << 0;
    }
}
