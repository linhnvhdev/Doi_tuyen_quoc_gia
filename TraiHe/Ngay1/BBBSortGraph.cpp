#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >=b;i--)
#define maxn 100005
using namespace std;

int n,a[maxn],b[maxn];

int main()
{
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&a[i]);
    int best = 0,m = 0;
    For(i,1,n){
        m = lower_bound(b+1,b+1+best,a[i]) - b;
        best = max(best,m);
        b[m] = a[i];
    }
    cout << best << endl;
}
