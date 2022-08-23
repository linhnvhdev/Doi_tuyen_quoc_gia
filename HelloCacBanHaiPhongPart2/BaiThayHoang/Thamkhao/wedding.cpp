#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
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
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
const int N=4010;
int n,a[N],x[N][N],dd[N];
vector<int> ke[N];
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
void DFS(int s)
{
    int u=a[s];
    if(s==n)
    {
        if(x[u][1]|x[1][u]) return;
        forinc(i,1,n) cout<<a[i]<<" ";
        exit(0);
    }
    dd[u]=1;
    forv(v,ke[u]) if(!dd[v])
    {
        a[s+1]=v;
        DFS(s+1);
    }
    dd[u]=0;
}
int main()
{
    freopen("WEDDING.inp","r",stdin);
    freopen("WEDDING.out","w",stdout);
    read(n);
    n*=2;
    forinc(i,1,n)
    {
        int k;read(k);
        while(k--)
        {
            int j;read(j);
            x[i][j]=1;
        }
    }
    forinc(i,1,n) forinc(j,1,n) if(i!=j) if(!(x[i][j]|x[j][i])) ke[i].pb(j);
    a[1]=1;
    DFS(1);
}
