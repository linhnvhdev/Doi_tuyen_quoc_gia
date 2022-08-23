#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 400010
using namespace std;

int n,k;
string S;

string Solve()
{
    if(k == 0) return S;
    if(n == 1) return "0";
    S[0] = '1'; k--;
    for(int i = 1;i < n && k > 0;i++){
        if(S[i] == '0') continue;
        S[i] = '0';
        k--;
    }
    return S;
}

int main()
{
    cin >> n >> k >> S;
    cout << Solve();
}
