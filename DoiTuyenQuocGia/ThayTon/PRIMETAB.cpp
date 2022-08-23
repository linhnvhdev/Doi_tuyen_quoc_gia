#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e9+1
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

int m,n,q;

vector<int> a[maxn],sum[maxn];
int val[500][4*maxn];
int f[maxn][500];

bool prime[1000005];

void Sang()
{
    prime[1] = true;
    For(i,2,1000000)
        if(!prime[i])
            For(j,2,1000000/i)
                prime[i*j] = true;
}

int get_sum(int i,int j,int u,int v)
{
    return sum[u][v] - sum[i-1][v] - sum[u][j-1] + sum[i-1][j-1];
}

int check(int x,int y,int r,int c)
{
    For(i,x,y)
    {
        if(i + r - 1 > y) break;
        For(j,1,n)
        {
            int u = i + r - 1;
            int v = j + c - 1;
            if(v > n) break;
            if(get_sum(i,j,u,v) == r*c) return 1;
        }
    }
    return 0;
}

void Sub1()
{
    while(q--)
    {
        int x,y,r,c;
        scanf("%d%d%d%d",&x,&y,&r,&c);
        printf("%d\n",check(x,y,r,c));
    }
}

bool OK(int i,int j,int u,int v)
{
    int t = get_sum(i,j,u,v);
    return (t == (u-i+1)*(v-j+1));
}

void build(int node,int l,int r,int id)
{
    if(l == r)
    {
        //cout << node << ' ' << l << ' ' << r << ' ' << id << ' ' << f[l][id] << endl;
        val[id][node] = f[l][id];
        return;
    }
    int c = (l+r)/2;
    build(2*node,l,c,id);
    build(2*node+1,c+1,r,id);
    val[id][node] = max(val[id][2*node],val[id][2*node+1]);
}

int get(int node,int l,int r,int i,int j,int id)
{
    if(l > j || r < i) return 0;
    if(i <= l && r <= j) return val[id][node];
    int c = (l+r)/2;
    return max(get(2*node,l,c,i,j,id),get(2*node+1,c+1,r,i,j,id));
}

void Sub2()
{
    int t = (n < m) ? n : m;
    //int t = n;
    if(t == m)
    {
        //cerr << ":)";
        memset(f,-1,sizeof(f));
        For(i,1,m)
            For(k,1,t)
            {
                int u = i + k - 1;
                if(u > m) break;
                For(j,1,n)
                {
                    int l = j, r = n;
                    while(r - l > 1)
                    {
                        int mid = (l+r)/2;
                        if(OK(i,j,u,mid)) l = mid;
                        else r = mid;
                    }
                    int cur = -1;
                    if(OK(i,j,u,r)) cur = r - j + 1;
                    else if(OK(i,j,u,l)) cur = l - j + 1;
                    f[i][k] = max(f[i][k],cur);
                }
            }
        For(i,1,m) build(1,1,m,i);
        For(i,1,q)
        {
            int x,y,r,c;
            scanf("%d%d%d%d",&x,&y,&r,&c);
            int ans = get(1,1,m,x,y-r+1,r);
            if(ans >= c) printf("1\n");
            else printf("0\n");
        }
    }
    else
    {
        memset(f,-1,sizeof(f));
        For(i,1,m)
            For(j,1,n)
                For(k,1,n)
                {
                    int v = j + k - 1;
                    if(v > n) break;
                    int l = i, r = m;
                    while(r - l > 1)
                    {
                        int mid = (l+r)/2;
                        if(OK(i,j,mid,v)) l = mid;
                        else r = mid;
                    }
                    int cur = -1;
                    if(OK(i,j,r,v)) cur = r - i + 1;
                    else if(OK(i,j,l,v)) cur = l - i + 1;
                    f[i][k] = max(f[i][k],cur);
                }
        For(i,1,n) build(1,1,m,i);
        For(i,1,q)
        {
            int x,y,r,c;
            scanf("%d%d%d%d",&x,&y,&r,&c);
            int ans = get(1,1,m,x,y-r+1,c);
            if(ans >= r) printf("1\n");
            else printf("0\n");
        }
    }
}

int main()
{
    freopen("PRIMETAB.inp","r",stdin);
    freopen("PRIMETAB.out","w",stdout);
    Sang();
    scanf("%d%d%d",&m,&n,&q);
    For(i,1,n) sum[0].push_back(0);
    For(i,1,m)
    {
        sum[i].push_back(0);
        a[i].push_back(0);
        For(j,1,n)
        {
            int num;
            scanf("%d",&num);
            int add = !prime[num];
            a[i].push_back(add);
            sum[i].push_back(sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + add);
        }
    }
    Sub2();
}
