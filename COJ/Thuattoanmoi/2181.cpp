/*
    Làm bt ngược lại: đếm bộ ba số ko nguyên tố cùng nhau => chia hết cho 1 thừa số nt
    Gọi p1,p2,...,pk là các số nt <= 10^6
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define MAX 1000000
#define ll long long
using namespace std;

int n,a[maxn];
ll f[MAX],s[MAX],ans = 0;

void Solve()
{
    Forr(i,MAX,1){
        int cnt = s[i];
        ll cur = 0;
        for(int j = i + i; j <= MAX;j += i){
            cur -= f[j];
            cnt += s[j];
        }
        cur += 1ll*cnt*(cnt-1)*(cnt-2)/6ll;
        f[i] = cur;
    }
}

int main()
{
    cin >> n;
    For(i,1,n){
        cin >> a[i];
        s[a[i]]++;
    }
    Solve();
    cout << f[1] << endl;
}
