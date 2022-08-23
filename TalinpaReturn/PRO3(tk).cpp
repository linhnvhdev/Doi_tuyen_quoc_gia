#include<bits/stdc++.h>

using namespace std;

#define int long long

int s[3];
int p[3];
int n[3];

int gcd(int a,int b)    {   return  b == 0 ? a : gcd(b,a % b);  }
int lcm(int a,int b)    {   return  a * b / gcd(a,b);   }

signed main()   {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("PRO3.inp","r",stdin);
    freopen("PRO3.out","w",stdout);

    for(int i = 0 ; i < 3 ; ++i)    {
        cin >> s[i];
        cin >> p[i];
        cin >> n[i];
    }

    int ans = 0;

    for(int i = 1 ; i < 8 ; ++i)    {
        int S = 1;
        int P = 1;
        int N = 1e15;
        for(int j = 0 ; j < 3 ; ++j)
            if (i >> j & 1)
            {

                int R = min(S + (N - 1) * P,s[j] + (n[j] - 1) * p[j]);
                for(int k = 0 ; k < p[j] ; ++k, S += P)
                    if (S % p[j] == s[j] % p[j])break;
                if (S % p[j] != s[j] % p[j])
                {
                    S = P = N = 0;
                    break;
                }
                P = lcm(P,p[j]);
                N = (R - S + P) / P;
                if (N < 1)
                {
                    N = 0;
                    break;
                }
            }
        //cout << "\n" << S << " " << P << " " << N;
        if (__builtin_popcount(i) & 1)
            ans += N;
        else
            ans -= N;
    }
    cout << ans << endl;
}
