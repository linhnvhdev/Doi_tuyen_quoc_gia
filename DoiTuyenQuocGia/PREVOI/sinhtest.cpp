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
    freopen("RATING.inp","w",stdout);
    int t = 2;
    cout << t << endl;
    For(i,1,t)
    {
        n = 10;
        int q = 10;
        cout << n << ' ' << q << endl;
        ll fixa = random(1,1000);
        For(i,1,n) cout <<random(1,1000) << ' ' ;
            //cout << fixa << ' ' ;
        cout << endl;
        For(i,1,q)
        {
            int l = random(1,n),r = random(1,n);
            if(l > r) swap(l,r);
            cout << random(1,1000) << ' ' << l << ' ' << r << endl;
        }
    }
}

int main()
{
    srand(time(NULL));
    Sinhtest1();
}
