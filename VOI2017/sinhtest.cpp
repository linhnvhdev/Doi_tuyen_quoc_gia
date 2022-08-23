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
    freopen("VO17TV.inp","w",stdout);
    int n = 50;
    int k = 3;
    cout << n << ' ' << k << endl;
    ll sumcs = 1000;
    For(i,1,n)
    {
        int len = sumcs/n;
        For(j,1,len) cout << char('A' + random(0,3));
        cout << endl;
    }
}
