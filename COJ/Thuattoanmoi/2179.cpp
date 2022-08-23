#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Bit(x, i) ((x>>i) & 1)
#define maxN 1000001
#define ll long long
#define fi first
#define se second
/*
    khi thêm / bớt cốc bia x thì t cần đếm số bia i trên kệ (i != x) sao cho a[i], a[x]
nguyên tố cùng nhau
    ta giải bài toán ngược lại là đếm số cốc bia i trên kệ (i != x) sao cho a[i], a[x] ko nt cùng nhau
    gọi p1,p2,...pk là thừa số của a[x]
    => kq = tổng (-1)^j * cnt[tích các p[j]] (j = 0, (1<<k) - 1)

*/
using namespace std;
int n, q, f[maxN], a[maxN], used[maxN];
ll ans = 0, cnt[maxN];

int numone[128],leftone[128];
int mul[128] = {1};

void Init()
{
    for(int i = 1;i < (1<<7);i++)
        For(j,0,6)
            if(Bit(i,j)){
                leftone[i] = j;
                numone[i]++;
            }
}

void Update(int x)
{
    int k = 0, p[9], t = a[x];
    ll sum = 0;
    while(t > 1)
    {
        p[k] = f[t];// f[t] là ước nguyên tố nhỏ nhất của t
        while(t % p[k] == 0)t /= p[k];
        k++;
    }
    For(mask,0,(1<<k) - 1)
    {
        if(mask != 0) mul[mask] = p[leftone[mask]]*mul[mask^(1<<leftone[mask])];
        if(used[x])cnt[mul[mask]]--;
        numone[mask] % 2 == 0 ? sum -= cnt[mul[mask]] : sum += cnt[mul[mask]];
        if(!used[x])cnt[mul[mask]]++;
    }
    used[x] ? ans += sum : ans -= sum;
    used[x] = !used[x];
}

int main()
{
    Init();
    scanf("%d%d", &n, &q);
    For(i,2,maxN - 1)
        if(f[i] == 0)
        {
            f[i] = i;
            for(int j = 2; i * j < maxN; j++)
                if(f[i * j] == 0)
                    f[i * j] = i;
        }
    For(i,1,n)
        scanf("%d", &a[i]);
    while(q--)
    {
        int x;
        scanf("%d", &x);
        Update(x);
        printf("%lld\n",ans);
    }
}
/*
10 11
12 5 7 23 4 25 10 11 20 29 30
1
2
3
1
5
2
9
2
4
7
8

0 1 3 6 3 6 3 5 8 13
*/
