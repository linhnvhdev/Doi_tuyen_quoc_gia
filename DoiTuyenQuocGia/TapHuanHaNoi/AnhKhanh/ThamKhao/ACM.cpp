#include <bits/stdc++.h>
#define task "acm"

using namespace std;

const int N = 30005, B = 1 << 11;

long long a[N][B], f[3][B];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen(task".inp", "r", stdin);
	freopen(task".out", "w", stdout);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0, res = 1; j < 11; ++j, res <<= 1)
            cin >> a[i][res];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j < B; ++j)
        {
            a[i][j] = a[i][j ^ (j & (-j))] + a[i][j & (-j)];
            f[0][j] = max(f[0][j], a[i][j]);
        }
    for (int i = 1; i < 3; ++i)
        for (int pre = 0; pre < B; ++pre)
            for (int cur = 1; cur < B; ++cur)
            {
                if (pre & cur) continue;
                f[i][pre | cur] = max(f[i][pre | cur], f[i - 1][pre] + f[0][cur]);
            }
    cout << f[2][B - 1];
	return 0;
}
