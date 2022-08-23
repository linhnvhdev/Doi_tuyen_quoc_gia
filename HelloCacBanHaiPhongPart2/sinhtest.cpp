#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,k;

ll random(ll l,ll r)
{
    return l + (rand()*rand() + rand()) % (r - l + 1);
}

int main()
{
    srand(time(NULL));
    //freopen("test.inp","w",stdout);
    n = 10;
    int m = 10;
    cout << n <<' ' << m << endl;
    For(i,1,n) cout << random(1,10) << endl;
    For(i,1,n){
        int a = random(1,10);
        int b = random(1,10);
        cout << min(a,b) << ' ' << max(a,b) <<endl;
    }
    return 0;
}
