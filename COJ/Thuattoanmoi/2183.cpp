/*
    Sub1: O(n^3log2(n))
    Sub2: Đếm phần bù: số bộ 3 ko điều hòa
        => số bộ 3 ko điều hòa chứa số i = (số phần tử thuộc [2,n] nt với i)*(số phần tử thuộc [2,n] != i mà ko nguyên tố với i)
            Bộ 3 ko điều hòa chứa số i
                Hoặc GCD(i,j) = 1,GCD(i,k) > 1,GCD(j,k) = 1
                Hoặc GCD(i,j) = 1,GCD(i,k) > 1,GCD(j,k) > 1
            Mỗi bộ 3 ko điều hòa chứa số i đc đếm lặp lại 2 lần khi i = j || i = k
            cnt[i] là số thuộc [2,n] ko nguyên tố với i
            Vì vậy số bộ 3 ko điều hòa là 1/2 * Xích ma(i = 2->n,(n - 1 - cnt[i])*(cnt[i]-1))
        Tính cnt[i](2146)
        p1,p2,..,pk là các thừa số nt của i(k <= 7)
        A[i] là tập các số thuộc [2,n] chia hết cho p[i]
        Vậy số bộ 3 điều hòa là
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define MAX 1000000
#define ll long long
using namespace std;

int n;
ll ans = 0,cnt[maxn],mobius[maxn];

void Init()
{
    mobius[1] = 1;
    For(i,1,MAX)
        for(int j = 2*i;j <= MAX;j += i)
            mobius[j] -= mobius[i];
    For(i,2,n){
        if(mobius[i] == 0) continue;
        for(int j = i;j <= n;j += i)
            cnt[j] -= mobius[i]*(n/i);
    }
}

int main()
{
    scanf("%d",&n);
    if(n <= 3){
        cout << 0 << endl;
        return 0;
    }
    Init();
    ll ans = 0;
    For(i,2,n) ans -= 1ll*(n - 1 - cnt[i])*(cnt[i] - 1);
    ans/=2ll;
    ans += 1ll*(n-1)*(n-2)*(n-3)/6ll;
    cout << ans << endl;
}
