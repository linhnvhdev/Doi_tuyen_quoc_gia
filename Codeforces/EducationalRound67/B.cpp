#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
using namespace std;

int n,m;
string s,t;

int a[200005][27],b[27];

int Solve()
{
    int ans = 0;
    For(j,0,26){
        if(b[j] == 0) continue;
        int l = 0,r = n-1;
        //cout << char(j + 'a') << ' ' << b[j] << endl;
        while(r - l > 1){
            int mid = (r+l)/2;
            //cout << "$$$ " << l << ' ' << r << ' ' << mid << ' ' << a[mid][j] << ' ' << b[j] << endl;
            if(a[mid][j] >= b[j]) r = mid;
            else l = mid;
        }
        //cout << " ^^^^ " << r << endl;
        ans = max(ans,r);
    }
    return ans;
}

int main()
{
    scanf("%d",&n);
    cin >> s;
    s = 'A' + s;
    n++;
    For(i,1,n-1){
        For(j,0,26) a[i][j] = a[i-1][j];
        a[i][s[i]-'a']++;
    }
    scanf("%d",&m);
    For(i,1,m){
        memset(b,0,sizeof(b));
        cin >> t;
        for(int i = 0;i < t.size();i++) b[t[i] - 'a']++;
        printf("%d\n",Solve());
    }
}
