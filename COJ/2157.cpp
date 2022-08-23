#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 100005
using namespace std;

string S;
int f[105][105];

bool check(int i,int j,int l)
{
    for(int t = i,vt = 0;t <= j;t++){
        if(S[t] != S[i + vt]) return false;
        vt++;
        if(vt == l) vt = 0;
    }
    return true;
}

int Solve(int i,int j)
{
    if(i == j) return 1;
    int d = j - i + 1,ans = j - i + 1;
    if(f[i][j] != -1) return f[i][j];
    For(k,i,j-1) ans = min(ans,Solve(i,k) + Solve(k+1,j));
    for(int l = 1;l <= d/2;l++){
        if(d % l != 0) continue;
        if(check(i,j,l)) ans = min(ans,Solve(i,i+l-1));
    }
    f[i][j] = ans;
    return ans;
}

int main()
{
    while(1){
        cin >> S;
        if(S == "*") return 0;
        int n = S.size();
        For(i,0,n)
            For(j,0,n) f[i][j] = -1;
        cout << Solve(0,n-1) << endl;
    }
}

