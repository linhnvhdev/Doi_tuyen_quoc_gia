#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 500005
#define ll long long
#define fi first
#define se second
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n;
int a[maxn];

ll ans = 0,c[2049];

int scs[2049];

ll get(int a)
{
    bool d[10];
    int cnt = 0,p = a,tp = 0;
    memset(d,false,sizeof(d));
    if(p == 0) tp = 1;
    while(p > 0){
        if(!d[p%10])
            tp += (1<< (p%10));
        d[p%10] = true;
        p /= 10;
    }
    ll tmp = 0;
    for(int i = 1;i < (1<<10);i++){
        if((i ^ tp) == (tp-i)){
            tmp += (scs[i] % 2 == 0) ? -c[i] : c[i];
            c[i]++;
        }
    }
    return tmp;
}

int main()
{
    freopen("Relatives.inp","r",stdin);
    freopen("Relatives.out","w",stdout);
    scanf("%d",&n);
    For(i,1,1023)
        For(j,0,9) if(Bit(i,j)) scs[i]++;
    For(i,1,n){
        scanf("%d",&a[i]);
        ans += get(a[i]);
    }
    cout << ans << endl;
}
