#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 500005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,k;
int a[maxn],cur[maxn],nxt[maxn];

vector<int> vt1;

ll check(int pos)
{
    ll tmp = 1;
    For(i,2,k){
        tmp += (nxt[pos] - pos) >= 0 ? nxt[pos] - pos : nxt[pos] + n - pos;
        pos = nxt[pos];
    }
    return tmp;
}

int main()
{
    freopen("codeforce.inp","r",stdin);
    freopen("codeforce.out","w",stdout);
    scanf("%d%d",&n,&k);
    For(i,1,n) scanf("%d",&a[i]);
    Forr(i,n,1){
        nxt[i] = cur[a[i]+1];
        cur[a[i]] = i;
        if(a[i] == 1) vt1.push_back(i);
    }
    Forr(i,n,1){
        nxt[i] = cur[a[i]+1];
        cur[a[i]] = i;
    }
    ll ans = INF;
    for(int i = 0;i < vt1.size();i++)
        ans = min(ans,check(vt1[i]));
    cout << ans << endl;
}
