#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 10005
#define Bit(x,i) ((x >> i) & 1)
#define fi first
#define se second
using namespace std;

int n,m,s;

map<pair<int,int>,int> mp;
vector<int> a[maxn];
int d[maxn],ok[maxn];

int main()
{
    scanf("%d%d%d",&n,&m,&s);
    For(i,1,m){
        int u,v;
        scanf("%d%d",&u,&v);
        if(mp[{u,v}] != 0) continue;
        mp[{u,v}]++;
        a[u].push_back(v);
    }
    priority_queue<pair<int,int> > pq;
    pq.push({0,s});
    For(i,1,n) d[i] = 1e9;
    d[s] = 0;
    ok[s] = 1;
    while(!pq.empty()){
        int u = pq.top().se;
        int cur_d = -pq.top().fi;
        pq.pop();
        if(d[u] < cur_d) continue;
        //cout << "check " << u << ' ' << du << endl;
        for(int i = 0;i < a[u].size();i++){
            int v = a[u][i];
            if(d[u] + 1 < d[v]){
                d[v] = d[u] + 1;
                ok[v] = ok[u];
                pq.push({-d[v],v});
            }
            else if(d[u] + 1 == d[v])
                ok[v] += ok[u];
        }
    }
    int ans = 0;
    //For(i,1,n) cout << " % " << i << ' ' <<d[i] << ' ' << ok[i] << endl;
    For(i,1,n) if(i != s && ok[i] >= 2) ans++;
    cout << ans << endl;
}
