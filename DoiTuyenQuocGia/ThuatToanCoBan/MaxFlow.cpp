#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;++i)
#define INF 1e15+1
#define maxM 205
#define ll long long
using namespace std;
int m,n;
ll cap[maxM][maxM],a[maxM][maxM];
ll max_flow(int s,int t)
{
    if(s==t)return 0;
    ll total_flow=0,prev[maxM];
    while(true)
    {
        fill(prev,prev+1+n,-1);
        int q[maxM],qf=0,qb=0;
        q[qb++]=s;
        while(qf<qb)
        {
            int u=q[qf++];
            if(u==t)break;
            for(int i=1;i<=a[u][0];i++)
            {
                int v=a[u][i];
                if(prev[v]==-1&&cap[u][v]>0)
                {
                    prev[v]=u;
                    q[qb++]=v;
                }
            }
        }
        if(prev[t]==-1)return total_flow;
        ll path_cap=INF;
        for(int i=t;i!=s;i=prev[i])path_cap=min(path_cap,cap[prev[i]][i]);
        for(int i=t;i!=s;i = prev[i])
        {
            int j=prev[i];
            cap[j][i]-=path_cap;
            cap[i][j]+=path_cap;
        }
        total_flow+=path_cap;
    }
}
void add_edge(int u,int v,int w)
{
    cap[u][v]+=1ll*w;
    a[u][++a[u][0]]=1ll*v;
    a[v][++a[v][0]]=1ll*u;
}
int main()
{
    scanf("%d%d",&m,&n);
    For(i,1,m)
    {
        ll u,v,w;
        scanf("%lld%lld%lld",&u,&v,&w);
        add_edge(u,v,w);
    }
    printf("%lld",max_flow(1,n));
}
/*
12 15
15 6 100
6 11 2
11 7 100
7 12 4
12 8 100
8 13 8
13 9 100
9 14 3
14 10 100
10 15 10
11 10 100
12 9 100
*/
