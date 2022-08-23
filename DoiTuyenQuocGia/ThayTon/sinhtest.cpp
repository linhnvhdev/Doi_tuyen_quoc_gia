#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define ll long long
using namespace std;

const int mod = 1e9+7;

ll random(ll l,ll r)
{
    return l + ((rand()*rand() + rand()) % (r-l+1));
}

int main()
{
    srand(time(NULL));
    freopen("XXX.inp","w",stdout);
    int n = 1000;
    ll C = 57;
    cout << n << ' ' << C << '\n';
    For(i,1,n) cout << random(1,1000) << ' ';

}
