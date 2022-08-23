#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define INF 1e9+1
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

int n,m[maxn],MAX = -INF;
vector<int> a[maxn];
int cur_vt[maxn];

int main()
{
    freopen("PASIJANS.inp","r",stdin);
    freopen("PASIJANS.out","w",stdout);
    scanf("%d",&n);
    priority_queue<vector<int> > pq;
    For(i,1,n)
    {
        scanf("%d",&m[i]);
        MAX = max(MAX,m[i]);
        For(j,1,m[i])
        {
            int v;
            scanf("%d",&v);
            a[i].push_back(v);
        }
        vector<int> cur;
        Forv(j,a[i]) cur.push_back(-a[i][j]);
        while(cur.size() != MAX) cur.push_back(-INF);
        pq.push(cur);
    }
    vector<int> sq;
    while(!pq.empty())
    {
        vector<int> cur = pq.top();
        pq.pop();
        if(cur[0] == -INF) break;
        sq.push_back(-cur[0]);
        cur.erase(cur.begin());
        cur.push_back(-INF);
        pq.push(cur);
    }
    for(int v : sq) printf("%d ",v);
    return 0;
}
