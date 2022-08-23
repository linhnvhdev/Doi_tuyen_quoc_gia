#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
const int N=1010;
int m,n,deg[N],dd[N][N],D,fre[N];
pii a[N*N];
void add(int x,int y,int i)
{
    dd[x][i]=y;
    dd[y][i]=x;
}
void rev(int x,int y,int i)
{
    dd[x][i]=dd[y][i]=0;
}
void DFS(int u,int R,int B,int o)
{
    fre[u]=1;
    //cout<<u<<" "<<R<<" "<<B<<" "<<o<<endl;
    if(!o)
    {
        int v=dd[u][R];
        //cout<<u<<" "<<R<<" "<<v<<endl;
        if(v&&!fre[v])
        {
            rev(u,v,R);
            DFS(v,R,B,1);
            add(u,v,B);
        }
    }
    else
    {
        int v=dd[u][B];
        if(v&&!fre[v])
        {
            rev(u,v,B);
            DFS(v,R,B,0);
            add(u,v,R);
        }
    }
}
int main()
{
    freopen("LAMPS.inp","r",stdin);
    freopen("LAMPS.out","w",stdout);
    cin>>m>>n;
    int x,y;
    int id=0;
    while(cin>>x>>y)
    {
        y+=m;
        a[++id]={x,y};
        deg[x]++,deg[y]++;
        D=max({D,deg[x],deg[y]});
    }
    forinc(it,1,id)
    {
        int x=a[it].fi,y=a[it].se,ok=0;
        forinc(i,1,D) if(!dd[x][i]&&!dd[y][i])
        {
            //cout<<x<<" "<<y-m<<" "<<i<<endl;
            add(x,y,i);
            ok=1;break;
        }
        if(!ok)
        {
            int R=1,B=1;
            while(dd[x][R]) ++R;
            while(dd[y][B]) ++B;
            //cout<<x<<" "<<y-m<<" "<<R<<" "<<B<<endl;
            reset(fre,0);
            DFS(x,B,R,0);
            add(x,y,B);
        }
    }
    cout<<D<<"\n";
    forinc(u,1,m) forinc(i,1,D) if(dd[u][i]) cout<<u<<" "<<dd[u][i]-m<<" "<<i<<"\n";
}
