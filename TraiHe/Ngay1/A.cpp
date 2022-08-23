#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define point pair<int,int>
#define x first
#define y second
using namespace std;
int n, m, a[1001][1001], visit[1001][1001],sum[1001][1001];
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
point st, en;
//bool Ok(int i,int j)
//{
//    if(i == st.x && j == st.y)return false;
//    if(i == en.x && j == en.y)return false;
//    return true;
//}
int Dis(int i,int j,int u,int v)
{
    int ii = min(i, u);
    int jj = min(j, v);
    int uu = max(i, u);
    int vv = max(j, v);
    return sum[uu][vv] - sum[ii - 1][vv] - sum[uu][jj - 1] + sum[ii - 1][jj - 1];
}
bool Check(int i,int j)
{
    int a, b, c, d;
    a = st.x; b = j;
    c = en.x; d = j;
    if(Dis(st.x,st.y, a, b) + Dis(a, b, c, d) + Dis(c,d,en.x,en.y) == 0)return true;
    a = i; b = st.y;
    c = i; d = en.y;
    if(Dis(st.x,st.y, a, b) + Dis(a, b, c, d) + Dis(c,d,en.x,en.y) == 0)return true;
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    For(i,1,n)
        For(j,1,m)
        {
            char s;
            scanf(" %c", &s);
            if(s == '*')a[i][j] = 1;
            else a[i][j] = 0;
            if(s == 'S')st = {i, j};
            if(s == 'T')en = {i, j};
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
        }
    For(i,1,n)
        For(j,1,m)
            if(Check(i, j))
            {
                printf("YES");
                exit(0);
            }
    printf("NO");
}
/*
3 5
..*..
.S*T.
.....

3 3
*
*
*ST
*/
