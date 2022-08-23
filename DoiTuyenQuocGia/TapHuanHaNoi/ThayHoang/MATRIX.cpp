#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 25
#define ll long long
#define INF 1e9
#define Bit(x,i) ((x >> i)&1)
using namespace std;

int m,n,c[maxn];
int a[maxn][maxn];
int xoa[maxn];
int ans = 0,Delr,Delc;

void duyet(int i)
{
    if(i > m)
    {
        int mask = 0,delrow = 0,delcol = 0;
        queue<int> q;
        For(i,1,m)
        {
            if(xoa[i]) delrow += (1<<i);
            else
            {
                mask += (1<<i);
                q.push(i);
            }
        }
        For(i,1,n)
        {
            if(q.empty())
            {
                delcol += (1<<i);
                continue;
            }
            int cur = q.front();
            if((c[i] & mask) == (1<<cur)) q.pop();
            else delcol += (1<<i);
        }
        if(q.empty())
            if(__builtin_popcount(mask) > ans)
            {
                ans = __builtin_popcount(mask);
                Delr = delrow;
                Delc = delcol;
            }
        return;
    }
    xoa[i] = 1;
    duyet(i+1);
    xoa[i] = 0;
    duyet(i+1);
}

int main()
{
    fast_read;
    freopen("MATRIX.inp","r",stdin);
    freopen("MATRIX.out","w",stdout);
    cin >> m >> n;
    For(i,1,m)
        For(j,1,n)
        {
            cin >> a[i][j];
            if(a[i][j] == 1) c[j] += (1<<i);
        }
    duyet(1);
    cout << ans << endl;
    For(i,1,m) if(Bit(Delr,i)) cout << i-1 << ' ';
    cout << endl;
    For(i,1,n) if(Bit(Delc,i)) cout << i-1 << ' ';
}
