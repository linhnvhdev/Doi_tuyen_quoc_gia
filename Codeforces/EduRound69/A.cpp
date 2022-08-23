#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
using namespace std;

int n,a[maxn],t;

int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        For(i,1,n) scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int Kp1 = min(a[n-1],a[n]);
        printf("%d\n",min(Kp1 - 1,n-2));
    }
    return 0;
}
