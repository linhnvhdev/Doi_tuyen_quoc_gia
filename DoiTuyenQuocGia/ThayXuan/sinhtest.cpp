#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

ll random(ll l, ll r)
{
    return l + (rand()*rand() + rand())%(r-l+1);
}

int a[maxn];

int main()
{
    srand(time(NULL));
    freopen("CAKE.inp","w",stdout);
    int t = 2;
    cout << t << endl;
    while(t--)
    {
        int n = 8;
        cout << n << ' ';
        int step = 5;
        For(i,1,n) a[i] = n+1-i;
        For(i,1,step)
        {
            ll l = random(1,n);
            ll r = n;
            if(l > r) swap(l,r);
            reverse(a+l,a+r+1);
        }
        For(i,1,n) cout << a[i]+100 << ' ';
        cout << endl;
    }
}
