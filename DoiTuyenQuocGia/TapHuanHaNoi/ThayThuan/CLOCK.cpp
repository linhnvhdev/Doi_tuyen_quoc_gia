#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define maxn 100005
#define ll long long
#define fi first
#define se second
using namespace std;

int n;
int a[maxn];
int f[maxn][14];

int xoay(int st,int ed,int dir)
{
    if(dir == 1) return (st <= ed) ? ed - st: ed - st + 12;
    else return (st < ed) ? st - ed + 12 : st - ed;
}

int vtlui(int st,int step,int dir)
{
    if(dir == 1)
        return (st - step) <= 0? st - step + 12 : st - step;
    else
        return (st + step) > 12 ? st + step - 12 : st + step;
}

int main()
{
    fast_read;
    cin >> n;
    For(i,1,n) cin >> a[i];
    For(i,0,n+1)
        For(j,1,12) f[i][j] = 1e9;
    For(i,1,12)
        f[1][i] = xoay(a[1],i,-1);
    For(i,2,n)
        For(j,1,12)
        {
            int step = xoay(a[i],j,-1);
            int pre = vtlui(12,step,1);
            f[i][j] = min(f[i][j],f[i-1][pre] + step);
        }
    int ans = 1e9;
    For(i,1,12)
        ans = min(ans,f[n][i] + xoay(i,12,1));
    cout << ans << endl;
}
