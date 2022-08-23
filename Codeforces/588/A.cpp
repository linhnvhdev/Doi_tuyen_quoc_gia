#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 400010
using namespace std;

int a[5];

int main()
{
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a+1,a+1+4);
    if(a[1] + a[4] == a[2] + a[3]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
