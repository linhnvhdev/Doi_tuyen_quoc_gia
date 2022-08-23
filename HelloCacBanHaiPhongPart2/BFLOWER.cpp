/**
    f[l][r][p: 0/1][t]: Hái hoa ở đoạn (l,r) ,đứng ở l(0) hay r(1), thời điểm t
    cur = (p == 0) ? l : r;
    f[l-1][r][0][t'] (t' = t+(x[cur] - x[
    Gọi Delta[i] là khoảng cách giữa 2 hoa

**/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 105
#define ll long long
#define fi first
#define se second
#define INF 1e18
using namespace std;

int main()
{
    freopen("BARIC.inp","r",stdin);
    freopen("BARIC.out","w",stdout);

}
