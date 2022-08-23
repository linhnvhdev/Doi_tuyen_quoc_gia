#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 100005
using namespace std;

const int max_digit = 30;
typedef int bignum[max_digit];
ll a,b,c,x,y,z;
bignum A,B;

void nhan(bignum a,ll b,bignum c)
{
    ll nho = 0;
    Forr(i,max_digit,1){
        ll t = a[i]*b + nho;
        nho = t/10;
        c[i] = t%10;
    }
}

int sosanh(bignum a,bignum b)
{
    For(i,1,max_digit){
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return -1;
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        cin >> a >> b >> c >> x >> y >> z;
        memset(A,0,sizeof(A)); A[max_digit] = 1;
        memset(B,0,sizeof(A)); B[max_digit] = 1;
        nhan(A,a*b,A); nhan(A,z,A);
        nhan(B,x*y,B); nhan(B,c,B);
        int d = sosanh(A,B);
        if(d == 1) cout <<">\n";
        if(d == 0) cout <<"=\n";
        if(d == -1) cout <<"<\n";
    }
    return 0;
}
