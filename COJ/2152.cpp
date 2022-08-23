#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
using namespace std;

int q;
ll l,r,d;

int main()
{
    scanf("%d",&q);
    while(q--){
        scanf("%lld%lld%lld",&l,&r,&d);
        if(l > d){
            printf("%lld\n",d);
            continue;
        }
        ll right = ceil((1.0*(r+1)/d));
        right *= d;
        printf("%lld\n",right);
    }
}
