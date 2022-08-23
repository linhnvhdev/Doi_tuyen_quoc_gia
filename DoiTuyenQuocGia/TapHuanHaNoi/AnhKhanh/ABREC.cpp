#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 60006
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int test,m,n,K;
int f[maxn],a[maxn];
pii d[maxn];
int cnt = 0;
string s[maxn];

int t(int i,int j)
{
    if(i == 0 || j == 0) return 0;
    return (i-1)*n + j;
}

void Solve()
{
    int ans = 0;
    For(i,1,m)
        For(j,1,m)
        {
            For(k,1,n)
                d[k] = {f[t(j,k)] - f[t(i-1,k)],k};
            d[n+1] = {0,0};
            sort(d+1,d+1+n+1);
            priority_queue<pii> p,q;
            For(k,1,n+1)
            {
                while(!p.empty() && d[k].fi - p.top().se > K) p.pop();
                while(!q.empty() && d[k].fi - q.top().se > K) q.pop();
                if(!p.empty()) ans = max(ans,(j-i+1)*(d[k].se + p.top().fi));
                if(!q.empty()) ans = max(ans,(j-i+1)*(q.top().fi - d[k].se));
                p.push({-d[k].se,d[k].fi});
                q.push({d[k].se,d[k].fi});
            }
        }
    cout << ans << '\n';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ABREC.inp","r",stdin);
    freopen("ABREC.out","w",stdout);
    cin >> test;
    while(test--)
    {
        cin >> m >> n >> K;
        For(i,1,m)
            cin >> s[i];
        if(m <= n)
        {
            For(i,1,m)
                For(j,1,n)
                    f[t(i,j)] = f[t(i-1,j)] + f[t(i,j-1)] - f[t(i-1,j-1)] + (s[i][j-1] == 'A' ? 1 : -1);
        }
        else
        {
            swap(m,n);
            For(i,1,m)
                For(j,1,n)
                    f[t(i,j)] = f[t(i-1,j)] + f[t(i,j-1)] - f[t(i-1,j-1)] + (s[j][i-1] == 'A' ? 1 : -1);
        }
        Solve();
    }
}
