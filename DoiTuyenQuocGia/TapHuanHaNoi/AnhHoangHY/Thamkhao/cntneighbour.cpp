#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){return l+rng()%(r-l+1);}
#define forinc(a,b,c) for(int a=b;a<=c;++a)
#define fordec(a,b,c) for(int a=b;a>=c;--a)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define mp make_pair
#define ii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define vt vector<int>
#define vpi vector<pair<int,int>>
#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define task "CONNECTEDNEIGHBOURS"
template<typename X,typename Y>void Min(X &x,Y y){x=(x>y)?y:x;}
template<typename X,typename Y>void Max(X &x,Y y){x=(x<y)?y:x;}
template<typename X>void read(X &x){x=0;int n=0;char c=getchar();for(;!isdigit(c);c=getchar())n+=(c=='-');for(;isdigit(c);c=getchar())x=x*10+c-'0';x=(n&1)?-x:x;}
template<typename X,typename... Y>void read(X &x,Y&... y){read(x);read(y...);}
const int N=1e5+5;
int n,m,k,f[N];
vector<int> ad[N],g[N];
int id[N];
int root(int x){return id[x]<0?x:id[x]=root(id[x]);}
void uni(int u,int v){
    u=root(u),v=root(v);
    if(u==v) return;
    if(id[u]>id[v]) swap(u,v);
    forv(x,g[v]){
        forv(j,ad[x]){
            if(root(j)==u) f[x]++,f[j]++;
        }
        g[u].pb(x);
    }
    id[u]+=id[v];
    id[v]=u;
}
main(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    read(n,m,k);
    forinc(i,1,m){
        int u,v;
        read(u,v);
        ad[u].pb(v);ad[v].pb(u);
    }
    reset(id,-1);
    forinc(i,1,n) g[i].pb(i);
    forinc(i,1,k){
        int u,v;
        read(u,v);
        uni(u,v);
    }
    int q;
    read(q);
    while(q--){
        char x=getchar();
        while(x==' '||x=='\n') x=getchar();
        if(x=='?'){
            int u;
            read(u);
            cout<<f[u]<<'\n';
        }
        else if(x=='T'){
            int u,v;
            read(u,v);
            uni(u,v);
        }
        else{
            int u,v;
            read(u,v);
            if(root(u)==root(v)) f[u]++,f[v]++;
            else ad[u].pb(v),ad[v].pb(u);
        }
    }
}
