#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 300005
#define ll long long
using namespace std;

ll a[4][4];
ll c[4][4][44];
int n;
ll ans = 0;

ll chuyendia(ll n,int d1,int d2)
{
    if(n == 0) return 0;
    if(c[d1][d2][n] != 0) return c[d1][d2][n];
    ll cost1 = chuyendia(n-1,d1,6-d1-d2) + a[d1][d2] + chuyendia(n-1,6-d1-d2,d2);
    ll cost2 = 2*chuyendia(n-1,d1,d2) + a[d1][6-d1-d2] + a[6-d1-d2][d2] + chuyendia(n-1,d2,d1);
    c[d1][d2][n] = min(cost1,cost2);
    return c[d1][d2][n];
}

int main()
{
    For(i,1,3)
        For(j,1,3)
            scanf("%lld",&a[i][j]);
    scanf("%d",&n);
    cout << chuyendia(n,1,3) << endl;
}
