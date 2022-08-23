#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1005
#define ll long long
#define INF 1e9
using namespace std;

const int MAX = 1000000;
int m,n;
int a[maxn],b[MAX+5];

int f[maxn][maxn],ans[MAX+5];
vector<int> vtb[2000005];

int Find(int vt,int val)
{
    if(vtb[val].size() == 0) return INF;
    int d = upper_bound(vtb[val].begin(),vtb[val].end(),vt) - vtb[val].begin();
    return (d == vtb[val].size()) ? INF : vtb[val][d];
}

int main()
{
    fast_read;
    freopen("LCS.inp","r",stdin);
    freopen("LCS.out","w",stdout);
    cin >> m >> n;
    For(i,1,m)
    {
        cin >> a[i];
        a[i] += MAX;
    }
    For(i,1,n)
    {
        cin >> b[i];
        b[i] += MAX;
        vtb[b[i]].push_back(i);
    }
    For(i,0,m)
        For(j,0,m) f[i][j] = INF;
    For(i,0,m)
        f[i][0] = 0;
    For(i,1,m)
        For(j,1,m)
        {
            f[i][j] = f[i-1][j];
            int vt = Find(f[i-1][j-1],a[i]);
            if(f[i][j] > vt) f[i][j] = vt;
            if(f[i][j] == INF) break;
        }
    int cnt = 0;
    Forr(i,m,1)
    {
        if(f[m][i] != INF)
        {
            int M = m,k = i;
            cout << i << endl;
            while(k > 0)
            {
                if(f[M][k] == f[M-1][k]) M--;
                else
                {
                    ans[++cnt] = a[M] - MAX;
                    M--;
                    k--;
                }
            }
            break;
        }
    }
    Forr(i,cnt,1) cout << ans[i] << ' ';
    if(cnt == 0) cout << 0 << endl;
}
