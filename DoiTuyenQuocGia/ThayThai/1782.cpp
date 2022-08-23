#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define INF 1e18
#define maxn 200005
#define Bit(x,i) ((x >> i)&1)
#define ll long long
#define fi first
#define se second
using namespace std;

struct bst{
    int l,r,val;
} t[4*maxn];

int n,a[maxn],p[maxn],cnt = 0;

int Find(int v)
{
    int cur = 0;
    while(true)
    {
        if(v > a[cur])
        {
            if(t[cur].r == 0) return cur;
            else cur = t[cur].r;
        }
        else
        {
            if(t[cur].l == 0) return cur;
            else cur = t[cur].l;
        }
    }
}

void add(int i,int v)
{
    int j = Find(v);
    p[i] = j;
    if(a[i] > a[j]) t[j].r = i;
    else t[j].l = i;
}

int main()
{
    scanf("%d",&n);
    For(i,1,n)
    {
        scanf("%d",&a[i]);
        add(i,a[i]);
    }
    For(i,2,n-1) printf("%d ",a[p[i]]);
    printf("%d\n",a[p[n]]);
}
