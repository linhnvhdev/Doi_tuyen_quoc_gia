#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 58
#define Bit(x,i) ((x >> i)&1)
#define fi first
#define se second
using namespace std;

int d;

int main()
{
    //freopen("etable.inp","r",stdin);
    //freopen("etable.out","w",stdout);
    string s = "CHAO_MUNG_CAC_THAY_CO_VA_CAC_EM.";
    int n = s.size();
    cin >> d;
    d %= n;
    For(i,d,n-1) cout << s[i];
    For(i,0,d-1) cout << s[i];
}
