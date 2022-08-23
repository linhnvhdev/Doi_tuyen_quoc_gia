#include <bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int q,T,n,k;

string s[maxn];

ll a[maxn];
int sumcs[maxn];

bool cmp(int x,int y)
{
    if(sumcs[x] != sumcs[y]) return sumcs[x] < sumcs[y];
    return s[x].compare(s[y]) < 0;
}

int main()
{
    fast_read;
    freopen("VO17BACH.txt","r",stdin);
    freopen("VO17BACH.txt","w",stdout);
    cin >> q;
    For(i,1,100000)
    {
        int x = i;
        while(x > 0)
        {
            s[i] = char(x % 10 + '0') + s[i];
            sumcs[i] += x % 10;
            x /= 10;
        }
    }
    while(q--)
    {
        cin >> T >> n >> k;
        For(i,1,n) a[i] = i;
        sort(a+1,a+1+n,cmp);
        if(T == 1) cout << a[k] << '\n';
        else For(i,1,n) if(a[i] == k) {cout << i << '\n'; break;}
    }
}
