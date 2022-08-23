#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2000005
#define ll long long
using namespace std;

int n;
string s,s2;
int d1[maxn],d2[maxn];

int main()
{
    while(cin >> s){
        n = s.size();
        for(int i = 0,l = 0,r = -1;i < n;i++){
            int k = (i > r) ? 1 : min(d1[l + r - i],r - i + 1);
            while(0 <= i-k && i+k < n && s[i-k] == s[i+k]) k++;
            d1[i] = k--;
            if(i + k > r){
                r = i  + k;
                l = i - k;
            }
        }
        for(int i = 0,l = 0,r = -1;i < n;i++){
            int k = (i > r) ? 0 : min(d2[l + r - i + 1],r - i + 1);
            while(0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]) k++;
            d2[i] = k--;
            if(i + k > r){
                r = i  + k;
                l = i - k - 1;
            }
        }
        For(i,0,n-1) cout << i << ' ' << d1[i] << ' ' << d2[i] << endl;
        For(i,0,n-1){
            if(i + d2[i] == n){
                cout << s;
                Forr(j,i - d2[i] - 1,0) cout << s[j];
                cout << '\n';
                break;
            }
            if(i + d1[i] == n){
                cout << s;
                Forr(j,i - d1[i],0) cout << s[j];
                cout << '\n';
                break;
            }
        }
    }
    return 0;
}
