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

int n,delta,a[maxn],f1[maxn][21],f2[maxn][21];

int getmin(int i,int j)
{
    int k = log2(j-i+1);
    return min(f1[i][k],f1[j-(1<<k)+1][k]);
}

int getmax(int i,int j)
{
    int k = log2(j-i+1);
    return max(f2[i][k],f2[j-(1<<k)+1][k]);
}

bool check(int i,int j)
{
    return getmax(i,j) - getmin(i,j) <= delta;
}

int main()
{
    fast_read;
    freopen("LMINMAX.inp","r",stdin);
    freopen("LMINMAX.out","w",stdout);
    cin >> n >> delta;
    For(i,1,n)
    {
        cin >> a[i];
        f1[i][0] = f2[i][0] = a[i];
    }
    For(j,1,20)
        For(i,1,n)
        {
            if(i + (1<<j) - 1 > n) break;
            f1[i][j] = min(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
            f2[i][j] = max(f2[i][j-1],f2[i+(1<<(j-1))][j-1]);
        }
    int j = 1,ans = 1;
    For(i,1,n)
    {
        while(j <= n && check(i,j)) j++;
        ans = max(ans,j-i);
        if(j > n) break;
    }
    cout << ans << '\n';
}
