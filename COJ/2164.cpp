#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
using namespace std;

string s;
int n;
int d1[maxn],d2[maxn],d3[maxn],d4[maxn],ans = 0;

int main()
{
    cin >> s;
    n = s.size();
    for(int i = 0, l = 0,r = -1;i < n; i++){
        int k = (i > r) ? 1 : min(d1[r + l - i],r - i + 1);
        if(i <= r) ans += min(d3[r+l-i],r-i+1);
        int cur = s[i] - '0';
        if(cur % 3 == 0){
            ans++;
            d3[i]++;
        }
        while(0 <= i - k && i + k < n && s[i - k] == s[i + k]){
            cur += (s[i-k]-'0')*2;
            if(cur % 3 == 0 && s[i-k] != '0'){
                d3[i]++;
                ans++;
            }
            k++;
        }
        d1[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
        cout << d3[i] << endl;
    }
    for(int i = 0, l = 0,r = -1;i < n; i++){
        int k = (i > r) ? 0 : min(d2[r+l-i+1],r-i+1);
        if(i <= r) ans += min(d4[r+l-i+1],r-i+1);
        int cur = 0;
        while(0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]){
            cur += (s[i-k-1]-'0')*2;
            if(cur % 3 == 0 && s[i-k-1] != '0'){
                d4[i]++;
                ans++;
            }
            k++;
        }
        d2[i] = k--;
        if(i + k > r){
            l = i - k - 1;
            r = i + k;
        }
        cout << "% "<<d4[i] << endl;
    }
    cout << ans << '\n';
}
