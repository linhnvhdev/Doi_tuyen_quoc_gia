#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
using namespace std;

string l,r;
ll ans = 0;

ll convert(string s)
{
    ll test = 0;
    for(int i = 0;i < s.size();i++) test = test * 10 + (s[i] - '0');
    return test;
}

string convert2(int t)
{
    string test = "";
    while(t > 0){
        int cs = t % 10;
        t /= 10;
        test = char(cs + '0') + test;
    }
    return test;
}

bool Checknhe(ll s)
{
    int scs = 0,luckynumber = 0;
    while(s > 0){
        scs++;
        int cs = s%10;
        if(cs == 4) return false;
        if(cs == 6 || cs == 8) luckynumber++;
        s/=10;
    }
    if(scs % 2 == 1) return false;
    return (luckynumber == scs/2);
}

void Sub1()
{
    ll L = 0,R = 0;
    L = convert(l);
    R = convert(r);
    For(i,L,R)
        if(Checknhe(i)) ans++;
    cout << ans << endl;
}

int main()
{
    freopen("BAI2.inp","r",stdin);
    freopen("BAI2.out","w",stdout);
    cin >> l >> r;
    if(l.size() <= 7 && r.size() <= 7) Sub1();
}
