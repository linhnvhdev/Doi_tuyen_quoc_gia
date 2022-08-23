/**
    ta dùng hsg
    tập hợp các điểm thẳng hàng là những điểm cùng hệ số góc
    sort hsg
    Gọi k là số phần tử gồm các hsg =
    thì số 3 điểm thẳng hàng là k*(k-1)/2;
**/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 2005
#define INF 1e9
#define Bit(x,i) ((x >> i) & 1)
#define point pair<int,int>
using namespace std;

int n;

int x[maxn],y[maxn],cnt = 0;
double d[maxn*maxn];
double esp = 1e-9;

int main()
{
    scanf("%d",&n);
    For(i,1,n)
        scanf("%d%d",&x[i],&y[i]);
    ll ans = 0;
    For(i,1,n){
        cnt = 0;
        For(j,i+1,n){
            if(x[i] == x[j]) d[++cnt] = INF;
            int n1 = x[j] - x[i],n2 = y[j] - y[i];
            d[++cnt] = (double) n2/n1;
        }
        sort(d+1,d+1+cnt);
        int cntd = 1;
        For(j,2,cnt){
            if(d[j] - d[j-1] < esp) cntd++;
            else{
                ans -= 1ll*cntd*(cntd-1)/2;
                cntd = 1;
            }
        }
        ans -= 1ll*cntd*(cntd-1)/2;
    }
    ans += 1ll*n*(n-1)*(n-2)/6ll;
    cout << ans << endl;
}
