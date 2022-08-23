#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
using namespace std;

const int MAX = 10000000;

int t;
ll n,ans = 0;
int snt = 0,num[MAX],prime[MAX];

void Sang()
{
    For(i,1,MAX) prime[i] = num[i] = 1;
    For(i,2,MAX)
        if(prime[i]){
            num[i] = -1;
            for(int j = 2;i*j <= MAX;j++){
                prime[i*j] = 0;
                if(j % i == 0) num[i*j] = 0;
                else num[i*j] *= -1;
            }
        }
    //cout << snt << endl;
}

int main()
{
    Sang();
    //For(i,1,20) cout << i << ' ' << num[i] << endl;
    scanf("%d",&t);
    while(t--){
        scanf("%lld",&n);
        ans = 0;
        ll N = sqrt(n);
        for(ll i = 1;i <= N;i++)
            ans += 1ll*num[i]*n/(i*i);
        cout << ans<<endl;
    }
}
