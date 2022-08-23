#include <bits/stdc++.h>
#define ll long long
#define For(i,a,b) for(long long i = a; i <= b; ++i)
#define maxn 10005
#define INF 1e18
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;

struct AZNET
{
    int u,v;
    int id;
},e[3][maxn];

int t,n,m;

ll a[maxn],b[maxn];

int cnt[3];

void make_set(int i)
{
    p[i] = i;
    h[i] = 0;
}

int Find(int i)
{
    while(i != p[i]) i = p[i];
    return i;
}

bool Union(int u,int v)
{
    int x = Find(u);
    int y = Find(v);
    if(x == y) return false;
    if(h[x] < h[y]) p[x] = y;
    else
    {
        p[y] = x;
        if(h[x] == h[y]) h[x]++;
    }
    return true;
}

void Solve()
{
    For(i,1,n) make_set(i);
}

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        For(i,1,n-1) cin >> a[i];
        For(i,1,n-1) cin >> b[i];
        cnt[1] = cnt[2] = 0;
        For(i,1,m)
        {
            int u,v,id;
            cin >> u >> v >> id;
            e[id][++cnt[id]] = {u,v,id};
        }
        int t1,t2 = 0;
        int tmp = 0;
        ll ans = INF;
        For(i,1,n) make_set(i);
        For(i,1,cnt[1])
            if(Union(e[1][i].u,e[1][i].v)) t1++;
        For(i,1,cnt[2])
            if(Union(e[2][i].u,e[2][i].v)) t2++;
        For(i,0,t1)
            if(n-1 - i <= t2) ans = min(ans,a[i] + b[n-1-i]);
        For(x,0,t1)
            if(n-1-x <= t2 && ans == a[x] + b[n-1-x])
            {
                For(i,1,n) make_set(i);
                For(i,1,cnt[2])
                    Union(e[2][i].u,e[2][i].v);
                vector<pii> New;
                int dem = 0;
                For(i,1,cnt[1])
                    if(Union(e[1][i].u,e[1][i].v))
                        New.push_back(i);
                For(i,1,n) make_set(i);
                for(int p : New) Union(e[1][p].u,e[1][p].v);
                int cur = New.size();
                For(i,1,cnt[1])
                {
                    if(cur == x) break;
                    if(Union(e[1][i].u,e[1][i].v))
                    {
                        cur++;
                        New.push_back(i);
                    }
                }

            }

    }

}
