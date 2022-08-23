#include <bits/stdc++.h>

using namespace std;

const long long oo = 1e18;

int n, l;
long long x[1005], f[1005][1005][2];

void CallF(int Left, int Right, int p, int t)
{
    if (f[Left][Right][p] != oo)
    {
        return;
    }
    int cur;
    if (p == 0)
    {
        cur = Left;
    }
    else
    {
        cur = Right;
    }
    if(Left - 1 >= 0)
    {
        CallF(Left - 1, Right, 0, t - 1);
        f[Left][Right][p] = min(f[Left][Right][p], f[Left - 1][Right][0] + t * abs(x[cur] - x[Left - 1]));
    }
    if (Right + 1 <= n)
    {
        CallF(Left, Right + 1, 1, t - 1);
        f[Left][Right][p] = min(f[Left][Right][p], f[Left][Right + 1][1] + t * abs(x[cur] - x[Right + 1]));
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("BFLOWERS.inp", "r", stdin);
    freopen("BFLOWERS.out", "w", stdout);
    cin >> n >> l;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
    }
    x[0] = l;
    sort(x, x + n + 1);
    int Be = lower_bound(x, x + n + 1, l) - x;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            f[i][j][0] = f[i][j][1] = oo;
        }
    }
    f[0][n][0] = f[0][n][1] = 0;
    CallF(Be, Be, 0, n);
    cout << f[Be][Be][0];
    return 0;
}
