#include <bits/stdc++.h>

using namespace std;

const int maxN = 6e4 + 1, oo = 1e9 + 7;

int n, m, k, f[250][maxN + 5], ans, it[maxN * 8 + 5], id[maxN * 2 + 5];

void build(int k, int l, int r)
{
    if (l == r)
    {
        id[l] = k;
        return;
    }
    int m = (l + r) >> 1;
    build(k * 2, l, m);
    build(k * 2 + 1, m + 1, r);
}

void upd(int k, int v)
{
    k = id[k];
    while (k)
    {
        if (it[k] != -1) return;
        it[k] = v;
        k >>= 1;
    }
}

int get(int k, int l, int r, int u, int v)
{
    if (v < l || r < u) return oo;
    if (u <= l && r <= v) return it[k] == -1 ? oo : it[k];
    int m = (l + r) >> 1;
    return min(get(k * 2, l, m, u, v), get(k * 2 + 1, m + 1, r, u, v));
}

void solve()
{
    cin >> n >> m >> k;
    char c;
    if (n <= m)
        for (int i = 1, cur; i <= n; ++i)
        {
            cur = 0;
            for (int j = 1; j <= m; ++j)
            {
                cin >> c;
                if (c == 'A') ++cur;
                else --cur;
                f[i][j] = f[i - 1][j] + cur;
            }
        }
    else
        for (int i = 1, cur; i <= n; ++i)
        {
            cur = 0;
            for (int j = 1; j <= m; ++j)
            {
                cin >> c;
                if (c == 'A') ++cur;
                else --cur;
                f[j][i] = f[j][i - 1] + cur;
            }
        }
    if (n > m) swap(n, m);
    ans = 0;
    for (int i = 0, cur, res; i < n; ++i)
        for (int j = n; j > i; --j)
        {
            memset(it, -1, sizeof(it));
            upd(maxN, 0);
            for (int l = 1; l <= m; ++l)
            {
                cur = f[j][l] - f[i][l] + maxN;
                res = get(1, 1, maxN * 2 - 1, cur - k, cur + k);
                if (res != oo) ans = max(ans, (l - res) * (j - i));
                upd(cur, l);
            }
        }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("abrec.inp", "r", stdin);
    freopen("abrec.out", "w", stdout);
    build(1, 1, maxN * 2 - 1);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}
