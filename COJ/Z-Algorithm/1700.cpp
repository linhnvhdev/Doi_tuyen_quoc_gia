#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
using namespace std;

string s;
int n,z[maxn];

bool used[maxn];
int p[maxn];

void FindZ()
{
    z[0] = n;
    for(int i = 1,l = 0,r = 0;i < n;i++){
        if(i > r){
            l = r = i;
            while(r < n && s[r] == s[r-l]){
                p[r] = max(p[r],r - l + 1);
                r++;
            }
            r--;
            z[i] = r - l + 1;
        }
        else{
            if(z[i-l] < r - i + 1){
                z[i] = z[i-l];
                p[i+z[i]] = max(p[i+z[i]],z[i]);
            }
            else{
                l = i;
                while(r < n && s[r] == s[r-l]){
                    p[r] = max(p[r],r - l + 1);
                    r++;
                }
                r--;
                z[i] = r - l + 1;
            }
        }
    }
}

int main()
{
    cin >> s;
    n = s.size();
    FindZ();
    //For(i,0,n-1) cout << i << ' ' << z[i] << endl;
    //For(i,1,n) cout << "****** " << i << ' ' << z[i] << ' ' << p[i] << endl;
    int firstans = p[n-1];
    int ans = -1e9;
    if(firstans == 0) ans = -1e9;
    else ans = (p[firstans-1] == 0) ? -1e9 : p[firstans-1];
    if(p[n-1] != 0)
        For(i,1,n-2)
            if(p[i] == firstans) ans = firstans;
    if(ans == -1e9) cout << "Just a legend";
    else cout << s.substr(0,ans) << endl;
}
