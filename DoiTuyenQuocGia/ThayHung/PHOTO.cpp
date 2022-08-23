#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >=b ;i--)
#define maxn 100005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
using namespace std;

int n;
int f[maxn][6],a[maxn];

bool cmp(int x,int y)
{
    int cnt = 0;
    For(i,1,5) cnt += (f[x][i] < f[y][i]);
    return (cnt >= 3);
}

int main()
{
    freopen("PHOTO.inp","r",stdin);
    freopen("PHOTO.out","w",stdout);
    scanf("%d",&n);
    For(i,1,5)
        For(j,1,n)
        {
            int stt;
            scanf("%d",&stt);
            f[stt][i] = j;
        }
    For(i,1,n) a[i] = i;
    sort(a+1,a+1+n,cmp);
    For(i,1,n) printf("%d ",a[i]);
}
