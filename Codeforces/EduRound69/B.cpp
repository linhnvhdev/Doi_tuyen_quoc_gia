#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 200005
using namespace std;

int n,a[maxn];

int main()
{
    scanf("%d",&n);
    int maxp = 0,vt = 0;
    For(i,1,n){
        scanf("%d",&a[i]);
        if(maxp < a[i]){
            maxp = a[i];
            vt = i;
        }
    }
    int left = vt - 1,right = vt + 1,cur_h = maxp;
    a[0] = -1e9,a[n+1] = -1e9;
    while(left > 0 || right <= n){
        int t = max(a[left],a[right]);
        //cout << left << ' ' << right << ' ' << t << ' ' << cur_h << endl;
        if(t >= cur_h){
            cout <<"NO\n";
            return 0;
        }
        cur_h = t;
        if(t == a[left])
            left--;
        else right++;
    }
    cout << "YES\n";
    return 0;
}
