#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define ll long long
/*
    bài toán chia kẹo euler: đếm số cách chia k cái kẹo giống nhau cho n đứa trẻ
    x1 + x2 + ... + xk = n
    *) x[i] > 0 => kq = C(n - 1, k - 1)
    *) x[i] >= 0 <=> (x1 + 1) + (x2 + 1) + .. +(xk + 1) = k + n
        quy về bài toán bên trên = C(n - 1, k + n - 1)

    A / B % mod = a * (B ^ -1) % mod với (B ^ -1) = B ^ (mod - 2)
*/
using namespace std;
ll f[100001][451];
int n, k;
const ll mod = 1e9 + 7;
int main()
{
    memset(f,0,sizeof(f));
    scanf("%d%d", &n, &k);
    f[0][0] = 1;
    int max_j = sqrt(2 * k);
    For(j,1,max_j)f[0][j] = 0;
    For(s,1,k)
        For(j,1,max_j)
        {
            if(s < n + 1)f[s][j] = (f[s][j] + (f[s - j][j - 1] + f[s - j][j])) % mod;
            else
                f[s][j] = (f[s][j] + (f[s - j][j - 1] + f[s - j][j] - f[s - (n + 1)][j - 1])) % mod;
        }
    printf("%lld", f[k][n]);
}
