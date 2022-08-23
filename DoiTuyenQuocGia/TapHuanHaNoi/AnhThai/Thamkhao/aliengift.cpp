#include <bits/stdc++.h>
#define task "aliengift"

using namespace std;

const int N = 1e5 + 5;
const long long oo = 1e18;

long long it[8][4 * N], lz[8][4 * N];
int mask[8] = {0, 1, 2, 4, 5, 8, 9, 10}, res;

void down(int k, bool L)
{
    if (lz[res][k] == -oo) return;
    long long cur = lz[res][k];
    lz[res][k] = -oo;
    it[res][k] = max(it[res][k], cur);
    if (L) return;
    lz[res][k * 2] = max(lz[res][k * 2], cur);
    lz[res][k * 2 + 1] = max(lz[res][k * 2 + 1], cur);
}

long long get(int k, int l, int r, int in)
{
    down(k, l == r);
    if (l == r) return it[res][k];
    int m = (l + r) >> 1;
    if (in > m) return get(k * 2 + 1, m + 1, r, in);
    return get(k * 2, l, m, in);
}

void upd(int k, int l, int r, int u, int v, long long c)
{
    down(k, l == r);
    if (r < u || v < l) return;
    if (u <= l && r <= v)
    {
        lz[res][k] = c;
        down(k, l == r);
        return;
    }
    int m = (l + r) >> 1;
    upd(k * 2, l, m, u, v, c);
    upd(k * 2 + 1, m + 1, r, u, v, c);
    it[res][k] = max(it[res][k * 2], it[res][k * 2 + 1]);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen(task".inp", "r", stdin);
	//freopen(task".out", "w", stdout);
	int n, a[4];
	long long cur[8];
	cin >> n;
	for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 4 * N; ++j)
            it[i][j] = lz[i][j] = -oo;
	for (res = 0; res < 8; ++res) upd(1, 1, n, 1, 1, 0);
	long long M, ans = -oo;
	for (int i = 1, l, h; i <= n; ++i)
    {
        cin >> l >> h;
        for (int j = 0; j < 4; ++j) cin >> a[j];
        for (res = 0; res < 8; ++res) cur[res] = get(1, 1, n, i);
        for (res = 0; res < 8; ++res)
        {
            M = -oo;
            for (int j = 0; j < 8; ++j)
            {
                if (mask[j] & mask[res]) continue;
                M = max(M, cur[j]);
            }
            for (int j = 0; j < 4; ++j)
                if ((mask[res] >> j) & 1) M += a[j];
            upd(1, 1, n, i + l, i + h, M);
            if (!res && !M) continue;
            ans = max(ans, M);
        }
        cout << i << ' ' << ans << endl;
    }
    cout << ans;
	return 0;
}
