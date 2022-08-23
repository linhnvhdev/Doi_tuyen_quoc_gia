#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n;
int k,a[maxn],minval = 1e9,maxval;

bool check(int num)
{
    For(i,1,n)
    {
        ll Del = a[i] % num;
        if(Del > k) return false;
    }
    return true;
}

int main()
{
    cin >> n >> k;
    For(i,1,n)
    {
        scanf("%d",&a[i]);
        minval = min(minval,a[i]);
        maxval = max(maxval,a[i]);
    }
    if(maxval - minval <= k)
    {
        cout << minval << endl;
        return 0;
    }
    Forr(num,minval,1)
        if(check(num))
        {
            cout << num << endl;
            return 0;
        }
}
