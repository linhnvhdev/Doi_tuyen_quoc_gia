#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int k,n,m;
int c[maxn],M;

map<int,int> mp;

int main()
{
    //freopen("PLANTTREE.inp","r",stdin);
    //freopen("PLANTTREE.out","w",stdout);
    fast_read;
    cin >> k >> n >> m;
    For(i,1,n)
    {
        cin >> c[i] >> M;
        mp[M]++;
    }
    cout << mp.size()+1;
}
