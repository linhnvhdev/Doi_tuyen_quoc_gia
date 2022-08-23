#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 10000005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

ll f[maxn],c[maxn];
ll n,k;
ll F,A,B,mod;

int dq[2*maxn];

int main()
{
    fast_read;
    freopen("supermario.inp","r",stdin);
    freopen("supermario.out","w",stdout);
    cin >> n >> k >> F >> A >> B >> mod;
    c[1] = F;
    For(i,2,n) c[i] = (c[i-1]*A + B)%mod;
    f[0] = 0;
    c[n+1] = 0;
    int fr = 1, bk = fr - 1;
    dq[++bk] = 0;
    For(i,1,n+1)
    {
        f[i] = f[dq[fr]] + c[i];
        //cout << i << ' ' << f[i] << endl;
        while(fr <= bk && i - dq[fr] >= k) fr++;
        while(fr <= bk && f[i] <= f[dq[bk]]) bk--;
        dq[++bk] = i;
    }
    cout << f[n+1] << endl;
}
