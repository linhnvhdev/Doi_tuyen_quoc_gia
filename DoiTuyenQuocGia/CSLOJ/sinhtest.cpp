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

void Sinhtest1()
{
    freopen("GARDEN.inp","w",stdout);
    int m = 300;
    int n = 300;
    cout << m << ' ' << n << endl;
    For(i,1,m)
    {
        For(j,1,n)
        {
            int a = random(0,1);
            if(a == 0) cout << "#";
            else cout <<".";
        }
        cout << endl;
    }
}

int main()
{
    srand(time(NULL));
    Sinhtest1();
}
