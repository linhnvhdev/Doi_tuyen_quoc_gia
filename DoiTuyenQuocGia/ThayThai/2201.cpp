/**
    Xét bài toán :
        Tìm các nghiệm nguyên dương của phương trình sau: x^2 + y^2 = z^2
    PT thuộc lớp pt diophante bậc hai 2 ẩn
    Bộ 3 số nguyên dương (x,y,z) t/m (1) gọi là bộ b3 pitago
    Nhận xét:
        Nếu bộ 3 (x,y,z) là nghiệm của (1) thì sẽ có vô số các bộ 3 có dạng (kx,ky,kz) với k = 1,2,... cx là bộ 3 pitago
    Nếu bộ 3 (x,y,z) thì bộ ba (x1,y1,z1) có
        với x1 = x/d,y1 = y/d,z1 = z/d; cx là bộ 3 pitago
    Gọi bộ 3 (x,y,z) là nguyên thủy nếu gcd(x,y,z) = 1;
    Từ các suy luận ở trên ta thấy rằng chỉ cần tìm các bộ 3 (x,y,z) nguyên thủy
    Định lí sau cho biết công thức nghiệm của các bộ 3 pitago nguyên thủy
    Nếu bộ 3 (x,y,z) là bộ 3 Pitago nguyên thủy thì x,y ko cùng tính chẵn lẻ
    {
        x = 2*mn;
        y = m^2 - n^2
        z = m^2 + n^2
    }
    Đảo lại, nếu m,n là 2 số ng dương và t/m tính chất trên thì bộ 3 cx là bộ 3 pitago nguyên thủy
    Với mỗi bộ 3 Pitago nguyên thủy ta xét tất cả các hệ số k
    k = (1,2,...maxc/z)
    Số tam giác vuông ứng với bộ 3 Pitago ứng với kx,ky,kz là
                                                   A  B  C
    cntA[A]*cntB[B]*cntC[c] + cntA[B]*cntB[A]*cntC[c];
**/


#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 300005
#define ll long long
using namespace std;

int na,nb,nc,a[maxn],b[maxn],c[maxn],A,B,C,MAX;
ll ans = 0;
int cntA[30000005],cntB[30000005],cntC[30000005];

int main()
{
    scanf("%d%d%d",&na,&nb,&nc);
    For(i,1,na)
    {
        scanf("%d",&a[i]);
        cntA[a[i]]++;
    }
    For(i,1,nb)
    {
        scanf("%d",&b[i]);
        cntB[b[i]]++;
    }
    For(i,1,nc)
    {
        scanf("%d",&c[i]);
        MAX = max(MAX,c[i]);
        cntC[c[i]]++;
    }
    For(m,1,sqrt(MAX))
    {
        For(n,1,m-1)
        {
            if((m % 2 == n % 2 ) || __gcd(m,n) != 1) continue;
            A = 2*m*n;
            B = m*m - n*n;
            C = m*m + n*n;
            //if(cntC[C] != 0) cerr << A << ' ' << B << ' ' << C << endl;
            if(C > MAX) continue;
            For(k,1,MAX / C)
            {
                if(!cntC[k*C]) continue;
                ans += 1ll*cntA[k*A]*cntB[k*B]*cntC[k*C];
                ans += 1ll*cntA[k*B]*cntB[k*A]*cntC[k*C];
                cerr << k*A << ' ' << k*B << ' ' << k*C << endl;
            }
        }
    }
    cout << ans << endl;
}
