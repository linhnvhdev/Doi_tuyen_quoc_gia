#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 125
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;

const char bracket[2] = {'(',')'};

int n;
ll k;

void Print()
{

}

void Print(int i)
{
    Forr(j,n-1,0)
        cout << bracket[Bit(i,j)];
    Forr(j,n-1,0)
        cout << bracket[1-Bit(i,j)];
    cout << endl;
}

int main()
{
    fast_read;
    freopen("WBRACK2.inp","r",stdin);
    freopen("WBRACK2.out","w",stdout);
    cin >> n >> k;
    ll ans = 0;
    for(int i = 0;i < (1<<n);i++)
    {
        int cur = 0;
        Forr(j,n-1,0)
        {
            if(!Bit(i,j)) cur++;
            else cur--;
            if(cur < 0) break;
        }
        Print(i);
    }
    cout << ans << endl;
}
