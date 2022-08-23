#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define fi first
#define se second
#define ll long long
using namespace std;

int main()
{
    freopen("BAI3.inp","w",stdout);
    int n = 100000,m = 100000;
    cout << n << ' ' << m << endl;
    For(i,1,n-1){
        cout << i << ' ' << i + 1 << endl;
    }
}
