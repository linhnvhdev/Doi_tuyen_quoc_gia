#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 10005
using namespace std;

const int mod = 1e9+7;
int n;
ll M;
ll a[maxn];

int main()
{
    scanf("%d%lld",&n,&M);
    For(i,1,n)
        scanf("%lld",&a[i]);
    ll ans = 0;
    sort(a+1,a+1+n);
    For(i,1,n)
    {
        int k = n,j = i+1;
        while(j < n && k > j)
        {
            int same = 0;
            int curj = a[j];
            while(j <= n-1 && a[j] == curj)
                same++,j++;
            if(a[i]*3 == M && curj == a[i])
            {
                For(K,j,n) if(curj == a[K]) same++;
                ans = (ans + 1ll*same*(same-1)/2)%mod;
                //cout << ans << endl;
                break;
            }
            j--;
            ll curgt = a[i] + curj;
            if(curj + curgt == M)
            {
                For(K,j+1,n) if(curj == a[K]) same++;
                ans = (ans + 1ll*same*(same-1)/2)%mod;
                j++;
                continue;
            }
            //cout << i << ' ' << a[i] << ' ' << curj << ' ' << curgt << ' ' << k << ' ' << a[k] << endl;
            while(k > j && curgt + a[k] > M) k--;
            int tmp = 0;
            while(k > j && curgt + a[k] == M) tmp++,k--;
            ans = (ans + 1ll*tmp*same)%mod;
            //cout << ans << ' ' << tmp << ' ' << same << endl;
            j++;
        }
    }
    cout << ans << endl;
}
/**
10 12
1 2 3 4 4 4 5 5 7 8
**/
