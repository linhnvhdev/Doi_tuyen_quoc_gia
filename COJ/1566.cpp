#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 500005
#define INF 1e18
using namespace std;

int n;
struct bike {
    int id,t;
    ll p;
} b[maxn];

ll f[maxn];

set<pair<ll,int> > s;

int main()
{
    scanf("%d",&n);
    For(i,1,n){
        scanf("%d%lld",&b[i].t,&b[i].p);
        b[i].id = i;
    }
    For(i,1,n) f[i] = INF;
    f[1] = b[1].p;
    s.insert({f[1],b[1].t});
    For(i,2,n){
        f[i] = f[i-1] + b[i].p;
        for(set<pair<ll,int> >::iterator it = s.begin();it != s.end();it++)
            f[i] = min(f[i],it->first);
        for(set<pair<ll,int> >::iterator it = s.begin();it != s.end();it++)
            if(it->second <= i) s.erase(it);
        s.insert({f[i],b[i].t});
    }
    cout << f[n] << endl;
}
