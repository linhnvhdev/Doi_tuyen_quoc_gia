#include <bits/stdc++.h>

using namespace std;

const int MaxN = 1000005;

int n, k;
pair<long long, long long> a[MaxN];

bool check(long long Time)
{
    int i = 1, dem = 0;
    while (i <= n)
    {
        long long Min = a[i].first + (Time / (2 * a[i].second));
        int j = i;
        while (j <= n && a[j].first <= Min)
        {
            Min = min(Min, a[j].first + Time / (2 * a[j].second));
            j++;
        }
        while (j <= n && Min >= a[j].first - Time / (2 * a[j].second))
        {
            j++;
        }
        dem++;
        i = j;
    }
    return dem <= k;
}

long long BS(long long Left, long long Right)
{
    while (Left <= Right)
    {
        long long Mid = (Left + Right) / 2;
        if (check(Mid))
        {
            Right = Mid - 1;
        }
        else
        {
            Left = Mid + 1;
        }
    }
    return Left;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("ANTS.inp", "r", stdin);
    freopen("ANTS.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].second;
    }
    sort(a + 1, a + n + 1);
    cout << BS(0, (long long)1e15);
    return 0;
}
