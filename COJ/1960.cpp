#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
using namespace std;

int a,b,n;
int uoca[maxn],cnta = 0,uoc[maxn],cnt;

int main()
{
    scanf("%d%d%d",&a,&b,&n);
    if(a > b) swap(a,b);
    uoca[++cnta] = 1;
    uoca[++cnta] = a;
    for(int i = 2;i <= sqrt(a);i++)
        if(a % i == 0){
            uoca[++cnta] = i;
            if(i != a/i) uoca[++cnta] = a/i;
        }
    For(i,1,cnta) if(b % uoca[i] == 0) uoc[++cnt] = uoca[i];
    sort(uoc+1,uoc+1+cnt);
    For(i,1,n){
        int l,r;
        scanf("%d%d",&l,&r);
        int t = upper_bound(uoc+1,uoc+1+cnt,r) - uoc - 1;
        if(uoc[t] >= l && uoc[t] <= r)
            printf("%d\n",uoc[t]);
        else printf("-1\n");
    }
}
