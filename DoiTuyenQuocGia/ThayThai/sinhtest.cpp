#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 5005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,k;

ll a[maxn],b[maxn];

bool used[maxn];

ll random(ll l,ll r)
{
    return l + (rand()*rand() + rand()) % (r - l + 1);
}

int main()
{
    srand(time(NULL));
    freopen("test.inp","w",stdout);
    int n = 100;
    int m = 3;
    cout << n << endl;
    For(i,1,m)
    {
        For(j,1,n)
        {
            //if(i > 1) {cout << '#'; continue;}
            int t = random(1,4);
            if(t == 1) cout <<'S';
            if(t == 2) cout <<'T';
            if(t == 3) cout <<'.';
            if(t == 4) cout <<'#';
            if(t == 5) cout <<'*';
        }
        cout << endl;
    }

}
