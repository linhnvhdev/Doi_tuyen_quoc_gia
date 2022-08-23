#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e9+1
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int n;
ll a[maxn];
ll SumSet[(1<<20)];

bool OK[(1<<20)];

void Sub1()
{
    for(int i = 1;i < (1<<n);i++)
        For(j,0,n-1) SumSet[i] += a[j+1]*Bit(i,j);
    ll ans = 0;
    For(i,1,(1<<n)-1)
        For(j,i+1,(1<<n)-1)
            if((i&j) == 0 && SumSet[i] == SumSet[j])
                OK[i ^ j] = true;
    For(i,1,(1<<n)-1) ans += OK[i];
    cout << ans << endl;
}

vector<pair<ll,ll> > A,B;
vector<ll> X,Y;

void Sub2()
{
    int N = n/2;
    int M = n - n/2;
    for(int i = 0;i < (1<<N);i++)
    {
        ll cur = 0;
        For(j,0,M-1) if(Bit(i,j)) cur += a[j+1];
        A.push_back({i,cur});
    }
    for(int i = 0;i < (1<<M);i++)
    {
        ll cur = 0;
        For(j,0,M-1) if(Bit(i,j)) cur += b[j + n + 1];
        B.push_back({i,cur});
    }
    for(int i = 0;i < A.size();i++)
    {
        for(int j = i + 1;j < A.size();j++)
        {
            if((A[i].fi & A[j].fi) == 0)
                X.push_back(A[i].se - A[i].se);
        }
    }
}

int main()
{
    fast_read;
    freopen("SUBSETS.inp","r",stdin);
    freopen("SUBSETS.out","w",stdout);
    cin >> n;
    For(i,1,n) cin >> a[i];
    if(n <= 10) Sub1();
    else Sub2();
}
