#define taskname "LCS"
#include <iostream>
#include <cstdio>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
const int maxM = 1e3 + 1;
const int maxN = 1e6 + 1;

int m, n, c[maxM], a[maxM], b[maxN];
vector<int> pos[maxM];
int f[maxM][maxM];

void Enter()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++) cin >> c[i];
    for (int j = 1; j <= n; j++) cin >> b[j];
}

void Init()
{
    unordered_map<int, int> mapA;
    int cnt = 0;
    for (int i = 1; i <= m; i++)
        if (mapA.emplace(c[i], cnt).second) cnt++;
    for (int i = 1; i <= m; i++)
        a[i] = mapA[c[i]];
    for (int j = 1; j <= n; j++)
    {
        unordered_map<int, int>::iterator fres = mapA.find(b[j]);
        if (fres != mapA.end())
        {
            b[j] = fres->second;
            pos[b[j]].push_back(j);
        }
    }
}

inline int FindNext(int Value, int From)
{
    vector<int>::iterator it = upper_bound(pos[Value].begin(), pos[Value].end(), From);
    if (it != pos[Value].end())
        return *it;
    else
        return maxN + 1;
}

void Optimize()
{
    for (int i = 0; i <= m; i++)
        f[i][0] = 0;
    for (int j = 1; j <= m; j++)
        f[0][j] = maxN + 1;
    for (int i = 1; i <= m; i++)
        for (int k = 1; k <= m; k++)
        {
            f[i][k] = min(f[i - 1][k], FindNext(a[i], f[i - 1][k - 1]));
            if (f[i][k] == maxN + 1)
            {
                fill(&f[i][k], &f[i][m + 1], maxN + 1);
                break;
            }
        }
}

void Print()
{
    int k = m;
    while (f[m][k] == maxN + 1) k--;
    cout << k << '\n';
    int i = m;
    vector<int>res;
    while (k > 0)
        if (f[i][k] == f[i - 1][k]) i--;
        else
        {
            res.push_back(c[i]);
            i--; k--;
        }
    for (vector<int>::reverse_iterator it = res.rbegin(); it != res.rend(); it++)
        cout << *it << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen(taskname".inp", "r", stdin);
    freopen(taskname".out", "w", stdout);
    Enter();
    Init();
    Optimize();
    Print();
}
