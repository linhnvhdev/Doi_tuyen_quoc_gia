/*
    Làm bt ngược lại: đếm bộ ba số ko nguyên tố cùng nhau => chia hết cho 1 thừa số nt
    Gọi p1,p2,...,pk là các số nt <= 10^6
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 10005
#define MAX 10000
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
        cur += 1ll*cnt*(cnt-1)*(cnt-2)*(cnt-3)/24ll;
        f[i] = cur;
    }
}

int main()
{
    freopen("2182.inp","r",stdin);
    freopen("2182.out","w",stdout);
    while(scanf("%d",&n) != EOF){
        memset(s,0,sizeof(s));
        memset(f,0,sizeof(f));
        For(i,1,n){
            cin >> a[i];
            s[a[i]]++;
        }
        Solve();
        cout << f[1] << '\n';
    }
}
