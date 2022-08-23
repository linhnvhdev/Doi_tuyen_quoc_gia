#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1000005
#define ll long long
#define INF 1e9
#define pii pair<int,int>
using namespace std;

int n,m,p;
ll a[maxn],sum[maxn];
int r[maxn];

struct data {
    int x1, y1, x2, y2;
    ll sum;
    bool operator < (const data &other) const {
        return sum < other.sum;
    }
};

map<data,bool> mp;

priority_queue<data> pq;

int t(int i,int j)
{
    return (i-1)*m+j;
}

ll get_sum(int i,int j,int u,int v)
{
    return sum[t(u,v)] - sum[t(i-1,v)] - sum[t(u,j-1)] + sum[t(i-1,j-1)];
}

bool cmp(int x,int y)
{
    return x > y;
}

int random(int l,int r)
{
    return l + (1ll*rand()*rand() + rand())%(r-l+1);
}

int main()
{
    ///srand(time(NULL));
    fast_read;
    cin >> n >> m >> p;
    For(i,1,n)
        For(j,1,m)
        {
            cin >> a[t(i,j)];
            sum[t(i,j)] = sum[t(i-1,j)] + sum[t(i,j-1)] - sum[t(i-1,j-1)] + a[t(i,j)];
        }
    ll ans = 0;
    int cnt = 0;
    pq.push({1,1,n,m,get_sum(1,1,n,m)});
    while(cnt <= 5*p && !pq.empty())
    {
        cnt++;
        data s = pq.top();
        pq.pop();
        if(mp.count(s) != 0) continue;
        mp[s] = 1;
        int x1 = s.x1,x2 = s.x2,y1 = s.y1,y2 = s.y2;
        if(s.sum % p == 0)
        {
            ans = max(ans,s.sum);
            cout << ans << endl;
            return 0;
        }
        if(x1 < x2) pq.push({x1+1,y1,x2,y2,get_sum(x1+1,y1,x2,y2)});
        if(x1 < x2) pq.push({x1,y1,x2-1,y2,get_sum(x1,y1,x2-1,y2)});
        if(y1 < y2) pq.push({x1,y1+1,x2,y2,get_sum(x1,y1+1,x2,y2)});
        if(y1 < y2) pq.push({x1,y1,x2,y2-1,get_sum(x1,y1,x2,y2-1)});
    }
    cout << ans << endl;
}
