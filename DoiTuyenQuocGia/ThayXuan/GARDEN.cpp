#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 151
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int n,m;
vector<int> a[maxn],sum[maxn];
string s;

int get_sum(int i,int j,int u,int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("GARDEN.inp","r",stdin);
    freopen("GARDEN.out","w",stdout);
    cin >> n >> m;
    For(i,0,m+1) sum[0].push_back(0);
    For(i,1,n)
    {
        int val;
        a[i].push_back(0);
        sum[i].push_back(0);
        For(j,1,m)
        {
            cin >> val;
            //cout << s[j-1] << endl;
            a[i].push_back(val);
            sum[i].push_back(sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1] + a[i][j]);
        }
    }
    int ans = 1e9;
    For(i,1,n)
        For(j,i,n)
        {
            int curmax = 0;
            For(k,1,m)
            {
                int t = k*(j-i+1) - 2*get_sum(i,1,j,k);
                ans = min(ans,t - curmax);
                curmax = max(curmax,t);
            }
        }
    cout << ans + get_sum(1,1,n,m) << endl;
}
