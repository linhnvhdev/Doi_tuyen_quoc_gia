/*
    Lưu mỗi dây cung vào 1 pair(first < second)
    (1,5),(2,6),(3,8),(4,7),...
    (Sắp xếp theo thứ tự tăng)
    Xét lần lượt dây cung i
    Với mỗi dây cung i,đếm số dây cung j(j < i)giao với dây cung i
    dây cung i giao với dây cung j <=> second(j) thuộc (first(i),second(i))
    => BIT
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i<=b;i++)
#define Forr(i,a,b) for(int i = a;i>=b;i--)
#define maxn 100001
#define fi first
#define se second
#define ll long long
using namespace std;

int n,cnt = 0;
pair<int,int> a[3*maxn];
int bit[3*maxn];

void update(int vt)
{
    for(int i = vt;i <= 2*n;i += (i & (-i)))
        bit[i]++;
}

ll get(int vt)
{
    ll ans = 0;
    for(int i = vt;i > 0;i -= (i & (-i)))
        ans += bit[i];
    return ans;
}

int main()
{
    scanf("%d",&n);
    For(i,1,n){
        scanf("%d%d",&a[i].fi,&a[i].se);
        if(a[i].fi > a[i].se) swap(a[i].fi,a[i].se);
    }
    sort(a+1,a+1+n);
    ll ans = 0;
    For(i,1,n){
        ans += get(a[i].se) - get(a[i].fi);
        update(a[i].se);
    }
    cout << ans << endl;
    return 0;
}
