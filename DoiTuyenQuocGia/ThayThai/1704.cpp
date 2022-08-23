#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,m;
ll a[maxn],b[maxn];
ll tong = 0;

void check(int i)
{
    if(i == 0 || i == n+1) return;
    if(a[i] >= a[i-1] && a[i] <= a[i+1]) b[i] = 1;
    else b[i] = 0;
}

int main()
{
    scanf("%d%d",&n,&m);
    a[0] = -INF;
    a[n+1] = INF+1;
    For(i,1,n)
        scanf("%d",&a[i]);
    For(i,1,n){
        if(a[i] >= a[i-1] && a[i] <= a[i+1]) b[i] = 1;
        else b[i] = 0;
        tong += b[i];
    }
    For(i,1,m){
        char type;
        int k,x;
        scanf(" %c",&type);
        if(type == '?'){
            if(tong == n) printf("YES\n");
            else printf("NO\n");
        }
        else{
            scanf("%d%d",&k,&x);
            a[k] = x;
            tong = tong - b[k] - b[k-1] - b[k+1];
            check(k); check(k-1); check(k+1);
            tong += b[k] + b[k-1] + b[k+1];
        }
    }
}
