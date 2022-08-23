#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,q;
string s;

int sosanh(string a,string b)
{
    int N = a.size();
    int M = b.size();
    for(int i = 0;i < min(N,M) ;i++){
        if(a[i] < b[i]) return -1;
        if(a[i] > b[i]) return 1;
    }
    if(N < M) return -1;
    if(N == M) return 0;
    if(N > M) return 1;
}

string convert(ll num)
{
    string test = "";
    Forr(i,n-1,0)
        test += char(Bit(num,i) + '0');
    return test;
}

bool check(ll mid)
{
    string M = convert(mid);
    //cout << "! " << M << endl;
    if(sosanh(M,s) <= 0) return false;
    string M1 = "",M2 = M;
    for(int i = 0;i < (int) M.size()-1;i++){
        M1 += M[i];
        M2.erase(0,1);
        //cout << i << ' ' << M1 << ' ' << M2 << ' ' << sosanh(M1,M2) <<  endl;
        if(sosanh(M1,M2) >= 0) return false;
    }
    //cout << "ok\n";
    return true;
}

void Solve()
{
    ll l = 0,r = (1ll<<n)-1;
    while(r - l > 1){
        int mid = (l+r)/2;
        //cout << " #### " << mid << endl;
        if(check(mid)) r = mid;
        else l = mid;
    }
    if(check(l)) cout << convert(l) << endl;
    else if(check(r)) cout << convert(r) << endl;
    else cout << endl;
}

int main()
{
    scanf("%d",&q);
    For(i,1,q){
        cin >> s;
        n = s.size();
        Solve();
    }
}
/**
10
7 2 6 8 5 11 3 4 12 17
**/
