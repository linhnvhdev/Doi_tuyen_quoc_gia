#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,c[maxn],m;
pair<int,int> tv[maxn];
int d[maxn],x[maxn],cur[maxn];
bool used[maxn];

int main()
{
    freopen("BALLOC.inp","r",stdin);
    freopen("BALLOC.out","w",stdout);
    scanf("%d%d",&n,&m);
    For(i,1,n) scanf("%d",&c[i]);
    For(i,1,m){
        scanf("%d%d",&tv[i].fi,&tv[i].se);
        x[tv[i].fi]++;
        x[tv[i].se + 1]--;
    }
    sort(tv+1,tv+1+m);
    priority_queue<pair<int,int> > pq;
    int pos = 1,ans = m;
    For(i,1,n){
        while(pos <= m && tv[pos].fi <= i){
            pq.push({tv[pos].se,tv[pos].fi});
            pos++;
        }
        cur[i] = cur[i-1] + x[i];
        if(cur[i] > c[i]){
            int D = cur[i] - c[i];
            while(!pq.empty()){
                int le = pq.top().se;
                int ri = pq.top().fi;
                pq.pop();
                cur[i]--;
                x[ri+1]++;
                D--;
                ans--;
                if(D == 0) break;
            }
        }
    }
    cout << ans << endl;
}
