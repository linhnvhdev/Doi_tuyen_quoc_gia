#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
using namespace std;

int n,m,a[maxn];

int main()
{
    scanf("%d%d",&n,&m);
    For(i,1,n) a[i] = 1;
    int ans = n;
    For(i,1,m){
        int l,r;
        scanf("%d%d",&l,&r);
        if(l > r) swap(l,r);
        if(r > n && l <= n){
            if(a[l] == 1 && a[r] == 0) ans--;
            if(a[l] == 0 && a[r] == 1) ans++;
        }
        swap(a[l],a[r]);
        printf("%d\n",ans);
    }
}
