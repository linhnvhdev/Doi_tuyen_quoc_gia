#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 5000005
#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
#define INF 1e18
using namespace std;

const int limit = 10;

ll n;

bool f[limit];
ll t[maxn],d = 0;

int main()
{
    fast_read;
    freopen("Nim.inp","r",stdin);
    freopen("Nim.out","w",stdout);
    f[0] = false;
    For(i,1,limit)
    {
        For(j,i - (int) sqrt(i),i-1)
            if(!f[j])
            {
                f[i] = true;
                break;
            }
    }
    int chk = 0;
    //For(i,1,limit) cout << i << ' ' << f[i] << endl;
    For(i,1,limit) if(f[i] == 0) chk++;
    //cout << chk << endl;
    ll thua = 2;
    t[++d] = 2;
    while(thua <= 10000000)
    {
        ll sqr = sqrt(thua);
        ll nxt = thua + sqr + 1;
        if(nxt >= (sqr+1)*(sqr+1)) nxt++;
        thua = nxt;
        t[++d] = thua;
        //cerr << thua << endl;
        //if(f[thua] == 1) cerr << thua << endl;
    }
    //cout << d << endl;
    while(cin >> n)
    {
        int vt = lower_bound(t+1,t+1+d,n) - t;
        if(t[vt] == n) cout << "STEVE\n";
        else cout << "BILL\n";
    }
}
