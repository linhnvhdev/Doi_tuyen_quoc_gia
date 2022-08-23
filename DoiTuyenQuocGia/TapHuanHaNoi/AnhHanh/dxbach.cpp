/// Code nay duoc sinh ra chi de quay xo so :)
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 100005
#define ll long long
#define INF 1e18
using namespace std;

int a[maxn],q, vt[maxn];

string ss[maxn];

int sum(int k)
{
    int tmp = 0;
    while(k > 0)
    {
        tmp += (k % 10);
        k /= 10;
    }
    return tmp;
}

bool cmp(int x,int y)
{
    int s1 = sum(x), s2 = sum(y);
    return (s1 < s2 || (s1 == s2 && ss[x].compare(ss[y]) < 0));
}

int main()
{
    fast_read;
    freopen("dxbach.inp","r",stdin);
    freopen("dxbach.out","w",stdout);
    cin >> q;
    while(q--)
    {
        int t,n,k;
        cin >> t >> n >> k;
        For(i,1,n) a[i] = i;
        For(i,1,n)
        {
            if(ss[i] != "") continue;
            int x = i;
            while(x > 0)
            {
                ss[i] = char('0' + x % 10) + ss[i];
                x /= 10;
            }
        }
        sort(a+1,a+1+n,cmp);
        For(i,1,n) vt[a[i]] = i;
        if(t == 0) cout << vt[k] << '\n';
        else cout << a[k] << '\n';
    }
}
