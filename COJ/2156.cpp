#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 100005
using namespace std;

int n,minX,maxX;
ll w[maxn],b[maxn];

ll ssl(int minx,int maxx)
{
    if(minx % 2 == 0) minx++;
    if(maxx % 2 == 0) maxx--;
    if(maxx < minx) return 0;
    return (maxx-minx)/2+1;
}

int ssc(int minx,int maxx)
{
    return (maxx - minx + 1) - ssl(minx,maxx);
}

int main()
{
    scanf("%d%d%d",&n,&minX,&maxX);
    For(i,1,n) scanf("%lld%lld",&w[i],&b[i]);
    int pre = b[n]%2,cur = w[n]%2;
    Forr(i,n-1,1){
        pre = pre + b[i]*cur%2;
        cur = cur*w[i]%2;
        pre %= 2;
    }
    ll chan = 0,le = 0,spam = 0,kspam = 0;
    if(cur % 2 == 0)
        chan = maxX - minX + 1;
    else{
        chan = ssc(minX,maxX);
        le = ssl(minX,maxX);
    }
    if(pre % 2 == 0){
        kspam = chan;
        spam = le;
    }
    else{
        spam = chan;
        kspam = le;
    }
    cout << kspam << ' ' << spam << endl;
}

