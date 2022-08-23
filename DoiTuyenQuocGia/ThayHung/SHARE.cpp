#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >=b ;i--)
#define maxn 100005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

ll m,n;

int main()
{
    freopen("SHARE.inp","r",stdin);
    freopen("SHARE.out","w",stdout);
    cin >> n >> m;
    cout << m - __gcd(m,n) << endl;
}
