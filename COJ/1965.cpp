#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 5005
using namespace std;

const int base = 128;
const int mod = 1e9+7;

int n,f[maxn];
ll h1[maxn],p[maxn],h2[maxn];
string s;

ll get_hash(ll h[maxn],int i,int j)
{
    return ((h[j] - h[i-1]*p[j-i+1]) % mod + mod) % mod;
}

int main()
{
    cin >> n >> s;
    For(i,1,n) f[i] = i;
    p[0] = 1;
    For(i,1,n){
        p[i] = (p[i-1]*base)%mod;
        h1[i] = (h1[i-1]*base + s[i-1]) % mod;
    }
    reverse(s.begin(),s.end());
    For(i,1,n) h2[i] = (h2[i-1]*base + s[i-1])%mod;
    For(i,1,n)
        For(j,1,i)
            if(get_hash(h1,j,i) == get_hash(h2,n - i + 1,n - j + 1))
                f[i] = min(f[i],f[j-1] + 1);
    cout << f[n] << endl;
}
