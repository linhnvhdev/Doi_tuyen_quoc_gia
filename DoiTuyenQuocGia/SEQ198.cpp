#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define Bit(x,i) ((x >> i)&1)
using namespace std;

int m;

int a[maxn];

bool check(vector<int> &t, int d)
{
    int vt = lower_bound(t.begin(),t.end(),d) - t.begin();
    if(vt != t.size() && t[vt] == d) return false;
    return true;
}

void Sub1()
{
    int ans = 1e9;
    for(int i = 0;i < (1<<m);i++)
    {
        bool ok = true;
        vector<int> t;
        For(j,0,m-1)
        {
            if(!Bit(i,j)) continue;
            if(check(t,a[j+1] - 1) && check(t,a[j+1] - 8) && check(t,a[j+1] - 9))
            {
                t.push_back(a[j+1]);
            }
            else
            {
                ok = false;
                break;
            }
        }
        if(ok) ans = min(ans,m - (int)t.size());
    }
    cout << ans << endl;
}

int main()
{
    cin >> m;
    For(i,1,m) cin >> a[i];
    sort(a+1,a+1+m);
    if(m <= 20) Sub1();
}
