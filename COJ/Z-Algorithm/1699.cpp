#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
using namespace std;

string s;
int n;
int z[maxn];

int main()
{
    cin >> s;
    n = s.size();
    z[0] = n;
    for(int i = 1,l = 0,r = 0;i < n;i++){
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
                z[i] = r - i + 1;
            }
        }
    }
    ll ans = 0;
    For(i,1,n) ans += z[i-1];
    cout << ans << '\n';
}
