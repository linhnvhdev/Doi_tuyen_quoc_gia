#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 30005
#define ll long long
using namespace std;

int n,m = 0;
ll a[maxn],b[maxn];

int main()
{
    cin >> n;
    For(i,1,n) cin >> a[i];
    For(i,1,n){
        int vt = lower_bound(b+1,b+1+m,a[i]) - b;
        m = max(m,vt);
        b[vt] = a[i];
    }
    cout << m << endl;
}
