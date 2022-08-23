#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int T,n;

int main()
{
    freopen("HOSPITAL.inp","r",stdin);
    freopen("HOSPITAL.out","w",stdout);
    scanf("%d",&T);
    For(Case,1,T)
    {
        printf("Case #%d:\n",Case);
        scanf("%d",&n);
        priority_queue<ll> pq[101];
        For(i,1,n)
        {
            char type;
            ll t,s,r;
            cin >> type;
            if(type == 'P')
            {
                scanf("%lld%lld%lld",&t,&s,&r);
                ll St = s - r*t;
                pq[r].push(St);
            }
            else
            {
                scanf("%lld",&t);
                ll ans = 0,rmax = 0,id;
                For(j,0,100)
                {
                    if(pq[j].empty()) continue;
                    ll St = pq[j].top();
                    if(St + j*t >= ans)
                    {
                        ans = St + j*t;
                        rmax = j;
                        id = j;
                    }
                }
                printf("%lld %lld\n",ans,rmax);
                pq[id].pop();
            }
        }
    }
}
