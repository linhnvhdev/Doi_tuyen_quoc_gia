#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 200010
using namespace std;

string s;
int a[maxn];
int lastcs[105][15];
bool used[105];

int main()
{
    memset(lastcs,false,sizeof(lastcs));
    memset(used,false,sizeof(used));
    cin >> s;
    int cs1 = 1e9,n = s.size();
    for(int i = 0;i < n;i++)
        a[i+1] = s[i] - '0';
    int ans = 1e9;
    for(int i = 16;i < 1000; i+=8)
        lastcs[i/10][i%10] = true;
    For(i,1,n){
        if(a[i] == 0 || a[i] == 8) ans = min(ans,a[i]);
        For(j,1,99)
            if(used[j] && lastcs[j][a[i]])
                ans = min(ans,j*10 + a[i]);
        For(j,0,9) if(used[j]) used[j*10 + a[i]] = true;
        used[a[i]] = true;
    }
    if(ans == 1e9) cout << "NO\n";
    else
        cout << "YES\n" << ans << endl;
}
