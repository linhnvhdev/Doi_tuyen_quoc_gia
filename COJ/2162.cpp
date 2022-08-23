#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
using namespace std;

int n;
char s[maxn];
int d1[maxn],d2[maxn];

int main()
{
    cin >> n >> s;
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
    cout << max(d1[max_element(d1,d1+n)-d1]*2-1,d2[max_element(d2,d2+n)-d2]*2);
}
/*
10
aaccbaabcc
*/
