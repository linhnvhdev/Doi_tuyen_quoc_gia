#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int in() {int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';if(n) x=-x;return x;}
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
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
const int N=400010;
int n,m,a[N],t[4*N],pre[N],ans[N];
struct oo {int u,v,l,r,id;} q[N];
bool cmp(oo u,oo v)
{
    return u.r<v.r;
}
void update(int s,int l,int r,int u,int x)
{
    if(l>u||r<u) return;
    if(l==r)
    {
        t[s]=x;
        return;
    }
    int mid=(l+r)/2;
    update(2*s,l,mid,u,x);
    update(2*s+1,mid+1,r,u,x);
    t[s]=min(t[2*s],t[2*s+1]);
}
int Find(int s,int l,int r,int k)
{
    if(l==r) return l;
    int mid=(l+r)/2;
    if(t[2*s]<k) return Find(2*s,l,mid,k);
    return Find(2*s+1,mid+1,r,k);
}
int get(int s,int l,int r,int u,int v,int k)
{
    if(l>v||r<u) return 0;
    if(l>=u&&r<=v)
    {
        if(t[s]<k) return Find(s,l,r,k);
        return 0;
    }
    int mid=(l+r)/2;
    int A=get(2*s,l,mid,u,v,k);
    if(A) return A;
    return get(2*s+1,mid+1,r,u,v,k);
}
int main()
{
    freopen("COLORS.inp","r",stdin);
    freopen("COLORS.out","w",stdout);
    n=in(),m=in();
    forinc(i,1,n) a[i]=in();
    forinc(i,1,m) q[i]={in(),in(),in(),in(),i};
    sort(q+1,q+m+1,cmp);
    int j=1;
    forinc(i,1,m)
    {
        while(j<=n&&j<=q[i].r)
        {
            update(1,1,n,a[j],j);
            ++j;
        }
        ans[q[i].id]=get(1,1,n,q[i].u,q[i].v,q[i].l);
    }
    forinc(i,1,m)
    {
        if(!ans[i]) cout<<"OK\n";
        else cout<<ans[i]<<"\n";
    }
}
