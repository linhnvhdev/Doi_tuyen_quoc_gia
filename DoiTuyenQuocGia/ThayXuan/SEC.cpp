#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 500005
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int m,n,t,cnt = 0;
int child[maxn][3];
int d[maxn];
int leaf[maxn];

void Add(int t)
{
    int u = 0,k;
    For(i,1,t)
    {
        cin >> k;
        if(child[u][k] == 0) child[u][k] = ++cnt;
        u = child[u][k];
        d[u]++;
    }
    leaf[u]++;
}

int get(int t)
{
    //cerr << "##### " << t << endl;
    int u = 0,k;
    bool ok = true;
    int ans = 0;
    For(i,1,t)
    {
        cin >> k;
        if(!ok) continue;
        if(child[u][k] == 0)
        {
            ok = false;
        }
        else
        {
            u = child[u][k];
            ans += leaf[u];
        }
    }
    if(!ok) return ans;
    return ans + d[u] - leaf[u];
}

int main()
{
    fast_read;
    freopen("SEC.inp","r",stdin);
    freopen("SEC.out","w",stdout);
    cin >> m >> n;
    For(i,1,m)
    {
        cin >> t;
        Add(t);
    }
    For(i,1,n)
    {
        cin >> t;
        cout << get(t) << endl;
    }
}
