#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define INF 1e18
#define ll long long
#define fi first
#define se second
using namespace std;

int n;
ll c[maxn][maxn],d[maxn][maxn];
ll sum[maxn];

vector<pair<int,ll> > a[maxn];

int main()
{
    freopen("GUEST.inp","r",stdin);
    freopen("GUEST.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n)
        For(j,i,n)
        {
            scanf("%lld",&c[i][j]);
            c[j][i] = c[i][j];
            d[i][j] = d[j][i] = c[i][j];
        }
    For(i,0,n)
        For(j,i+1,n){
            a[i].push_back({j,c[i+1][j]});
            a[j].push_back({i,c[i+1][j]});
        }
}
