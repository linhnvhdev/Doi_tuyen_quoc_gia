#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
using namespace std;

int n,a[maxn];

int main()
{
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans = 0;
    Forr(i,n,1)
        ans = max(ans,a[i] + n - i);
    cout << ans << endl;
}
