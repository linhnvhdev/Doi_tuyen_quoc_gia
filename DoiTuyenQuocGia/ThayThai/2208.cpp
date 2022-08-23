#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxN 100005
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

int n, s[2 * maxN], cnt = 0, tmp[2 * maxN];
queue<int>q[maxN][2];
pii a[maxN];
ll ans = 0;

bool cmp(pii a, pii b)
{
    return a.fi < b.fi;
}

void Update(int id, int val)
{
    for(int i = id;i <= 2*n;i += (i&(-i)))
        tmp[i] += val;
}

int Get(int id)
{
    int cur = 0;
    for(int i = id;i > 0; i -= (i&(-i)))
        cur += tmp[i];
    return cur;
}

int main()
{
    scanf("%d", &n);
    For(i,1,2*n)
        scanf("%d",&s[i]);
    For(j,1,2*n)
    {
        int cur = abs(s[j]);
        if(s[j] < 0)
        {
            if(q[cur][1].empty())q[cur][0].push(j);
            else
            {
                int i = q[cur][1].front();
                q[cur][1].pop();
                a[++cnt] = {i, j};
            }
        }
        else
        {
            if(q[cur][0].empty())q[cur][1].push(j);
            else
            {
                int i = q[cur][0].front();
                q[cur][0].pop();
                a[++cnt] = {i, j};
            }
        }
    }
    sort(a + 1, a + 1 + cnt, cmp);
    For(i,1,2*n) Update(i, 1);
    For(i,1,n)
    {
        int u = a[i].fi, v = a[i].se;
        ans += 1ll * (Get(v - 1) - Get(u));
        Update(u, -1);
        Update(v, -1);
        if(s[u] > 0)ans++;
    }
    printf("%lld", ans);
}
