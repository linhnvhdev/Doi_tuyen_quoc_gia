#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define fi first
#define se second
#define ll long long
using namespace std;

int m,n;
vector<int> a[maxn];
int ans = 0;
int nchain = 0,hchain[maxn],chainIndx[maxn],cnt[maxn],parent[maxn],nchild[maxn];

void dfs(int u,int p)
{
    nchild[u] = 1;
    for(int v:a[u]){
        if(v == p) continue;
        parent[v] = u;
        dfs(v,u);
        nchild[u] += nchild[v];
    }
}

void make_chain(int u,int p)
{
    //cout << "wibu hay hien nguyen hinh "<< u << endl;
    if(!hchain[nchain]) hchain[nchain] = u;
    chainIndx[u] = nchain;
    cnt[nchain]++;
    //cout << "chuoi "<<nchain << ' ' << cnt[nchain] << endl;
    int nd = -1;
    for(int v : a[u]){
        if(v == p) continue;
        if(nd == -1 || nchild[v] > nchild[nd]) nd = v;
    }
    //cout << nd << endl;
    if(nd != -1) make_chain(nd,u);
    for(int v: a[u]){
        if(v == p || v == nd) continue;
        nchain++;
        make_chain(v,u);
    }
}

int main()
{
    freopen("BAI3.inp","r",stdin);
    freopen("BAI3.out","w",stdout);
    scanf("%d%d",&n,&m);
    For(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    dfs(1,0);
    make_chain(1,0);
    //For(i,1,n) cout <<"* "<< i << ' ' <<  nchild[i] << endl;
    //For(i,0,nchain) cout <<"# "<< i << ' ' << cnt[i] << endl;
    sort(cnt,cnt+1+nchain);
    int ans = -1;
    Forr(i,nchain,max(nchain-m+1,0))
        ans += cnt[i];
    cout << ans << endl;
    return 0;
}
