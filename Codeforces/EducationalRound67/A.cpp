#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
using namespace std;

int n,T,s,t;

int FindMinEgg()
{
    /*
        n > max(s,t) => thua = n - max(s,t)
        => ans = thua + min(s,t) + 1;
    */
    int thua = n - max(s,t);
    return thua + abs(s-t) + 1;
}

int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&n,&s,&t);
        printf("%d\n",FindMinEgg());
    }
}
