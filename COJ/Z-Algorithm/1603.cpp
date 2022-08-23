#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
using namespace std;

int m,n,z[maxn];
string s;

void FindZ()
{
    for(int i = 0,l = 0,r = 0;i < n;i++){
        if(i > r){
            l = r = i;
            while(r < n && s[r] == s[r-l]) r++;
            r--;
            z[i] = r - l + 1;
        }
        else{
            if(z[i-l] < r - i + 1) z[i] = z[i-l];
            else{
                l = i;
                while(r < n && s[r] == s[r-l]) r++;
                r--;
                z[i] = r - l + 1;
            }
        }
    }
}

bool check(int k)
{
    //cout << "******** " << k << endl;
    int vt = k;
    while(vt + k < n){
        if(z[vt + k] + vt + k != n) return false;
        if(z[vt] - z[vt + k] != k) return false;
        vt = vt + k;
    }
    return (vt + z[vt] == n);
}

int main()
{
    cin >> m >> s;
    n = s.size();
    FindZ();
    //For(i,1,n) cout << i << ' ' << z[i] << endl;
    int ans = 1e9;
    For(i,1,m)
        if(z[i] + i == n && check(i)){
            ans = i;
            break;
        }
    if(ans != 1e9)cout << s.substr(0,ans);
    else cout << "NO\n";
}
