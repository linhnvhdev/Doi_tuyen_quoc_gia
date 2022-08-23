#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Bit(x, i) ((x>>i) & 1)
using namespace std;
int n, k, a[100001][21], ok;
void Sub1()
{
    int ans = 1e9;
    For(x,0,(1<<k) - 1)
    {
        int cur_ans = 0;
        For(i,1,n)
        {
            int d = 0;
            For(j,1,k)
                d += 1 - abs(a[i][j] - Bit(x, j - 1));
            cur_ans = max(d, cur_ans);
        }
        //cout<<x<<" "<<cur_ans<<endl;
        if(ans > cur_ans)
        {
            //cout<<"OK"<<endl;
            ok = x;
            ans = cur_ans;
        }
    }
    For(i,1,k)
        printf("%d", Bit(ok, i - 1));
}
void Test()
{
    For(i,1,n)
    {
        int d = 0;
        For(j,1,k)
            d += a[i][j];
        if(d >= k - d)printf("0");
        else
            printf("1");
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    For(i,1,n)
        For(j,1,k)
        {
            char c;
            scanf(" %c", &c);
            a[i][j] = c - '0';
        }
    if((1<<k) * n * k <= 45000000)Sub1();
    else
        Test();
}
