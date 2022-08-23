#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

ll a[maxn];

int main()
{
    fast_read;
    //freopen("ANCTEXT.inp","r",stdin);
    //freopen("ANCTEXT.out","w",stdout);
    For(i,1,6) a[i] = i;
    For(i,1,720)
    {
        cout << i << " ### ";
        For(i,1,6) cout << a[i] << ' ';
        cout << endl;
        next_permutation(a+1,a+1+6);
    }
}
