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

int q;
int curr = 1,curd = 0;

char s[3];

ll Solve(ll x,ll y,ll color)
{
    int d1 = log2(x);
    int d2 = log2(y);
    int c = 1;
    while(x != y)
    {
        if(x > y)
        {
            x /= 2;
            c++;
        }
        else if(y > x)
        {
            y /= 2;
            c++;
        }
    }
    if((d1 % 2) != (d2 % 2)) return c/2;
    int curcolor = (d1)%2;
    if(color == curcolor) return (c+1)/2;
    else return c/2;
}

int main()
{
    scanf("%d",&q);
    while(q--)
    {
        ll x,y;
        scanf("%s",&s);
        if(s[1] == 'i') swap(curr,curd);
        if(s[1] == 'r')
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",Solve(x,y,curr));
        }
        if(s[1] == 'b')
        {
            scanf("%lld%lld",&x,&y);
            printf("%lld\n",Solve(x,y,curd));
        }
    }
}
