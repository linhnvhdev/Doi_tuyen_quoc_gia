#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
using namespace std;

const int mod = 666777;
const int mod1 = 3;
const int mod2 = 37;
const int mod3 = 6007;
ll ans = 0;
ll fact[1000005];
int M1 = mod/mod1,M2 = mod/mod2,M3 = mod/mod3;
vector<int> Num;

vector<int> getRepresentation(int N,int m) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % m);
        N /= m;
    }
    return res;
}

ll luythua(ll a,int n,int m)
{
    ll test = 1;
    while(n > 0){
        if(n % 2 == 1) test = (test*a) % m;
        a = (a*a) % m;
        n /= 2;
    }
    return test % m;
}

ll Cbe(int k,int n,int m)
{
    if(k > n) return 0;
    ll A = 1,C = 1,B = 1;
    For(i,1,n) A = (A*i)%m;
    For(i,1,k) B = (B*i)%m;
    For(i,1,n-k) C = (C*i)%m;
    return (A*(luythua(C,m-2,m))%m)*luythua(B,m-2,m) % m;
}

ll C(int k,int n,int m)
{
    if(k > n) return 0;
    //cout << k << ' ' << n << ' ' << m << endl;
    vector<int> K = getRepresentation(k,m);
    vector<int> Num = getRepresentation(n,m);
//    cout << "K ";
//    for(int i = 0;i < K.size();i++) cout << K[i] << ' ';
//    cout << endl;
//    cout << "Num ";
//    for(int i = 0;i < Num.size();i++) cout << Num[i] << ' ';
//    cout << endl;

    ll res = 1;
    for(int i = 0;i < K.size();i++)
        res = (res * Cbe(K[i],Num[i],m)) % m;
    return res;
}

void ext_gcd(long long a,long long b,long long &d, long long &x,long long &y){
    if(b==0){
        d=a;
        x=1;
        y=0;
    }
    else{
        long long x1,y1;
        ext_gcd(b,a%b,d,x1,y1);
        x=y1;
        y=x1-(a/b)*y1;
    }
}
long long mod_inverse(long long a,long long m){
    long long x,y,d;
    ext_gcd(a,m,d,x,y);
    return (x%m+m)%m;
}

int n,k;

int main()
{
    cin >> n >> k;
    ans = 1;
    ll Y1 = mod_inverse(M1,mod1);
    ll Y2 = mod_inverse(M2,mod2);
    ll Y3 = mod_inverse(M3,mod3);
    //cout << mod_inverse(15,7) << endl;
    //cout << M1 << ' ' << Y1 << endl;
    //cout << M2 << ' ' << Y2 << endl;
    //cout << M3 << ' ' << Y3 << endl;
    For(i,1,k){
        ll C1 = C(i,n,mod1);
        ll C2 = C(i,n,mod2);
        ll C3 = C(i,n,mod3);
        //cout << (M1*C1*Y1) % mod << endl;
        //cout << (M2*C2*Y2) % mod << endl;
        //cout << (M3*C3*Y3) % mod << endl;
        ll cur = ((M1*C1*Y1)%mod) + ((M2*C2*Y2)%mod) + ((M3*C3*Y3)%mod);
        cur %= mod;
        //cout << cur % mod << endl;
        ans += cur % mod;
    }
    cout << ans << endl;
}
