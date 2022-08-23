#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,k;
ll v[maxn],a[maxn];

void Sub1()
{
    For(i,1,n){
        ll tmp = 0;
        For(j,1,n)
            if(i != j) tmp += __gcd(v[i],v[j]);
        cout << tmp << ' ' ;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SUMGCD.inp","r",stdin);
    freopen("SUMGCD.out","w",stdout);
    cin >> n;
    For(i,1,n) cin >> v[i];
    Sub1();

}
