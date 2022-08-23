/*
    Sub1: n <= 5 : Duyệt toàn bộ phương án :)
    Sub2: n <= 7 : 2 nửa a và b là độc lập => duyet từng nửa 1
    Sub3: n <= 57:
    Bt: Cho bậc của đt, dựng lại đồ thị
    Thuật tham giải quyết: đỉnh lớn nhất ghép với đỉnh lớn nhất tiếp theo
    Lặp{
        Sắp xếp đỉnh theo bậc(giảm);
        Lấy đỉnh lớn nhất xếp với các đỉnh tiếp theo
        Cập nhập lại bậc
    }
    => O(n^2*log2(n))
    => Áp dụng vào Sub3
    với mảng a,b chính là mảng bậc
    lấy nửa trên của đt xây dựng với a ghép với nửa dưới đt xd với b => mảng cần tìm
*/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 58
#define Bit(x,i) ((x >> i)&1)
#define fi first
#define se second
using namespace std;

int n,a[maxn],b[maxn];
int A[maxn][maxn],B[maxn][maxn];
pair<int,int>  D[maxn];
int cnt = 0;

int main()
{
    freopen("matrix.inp","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&a[i]);
    For(i,1,n) scanf("%d",&b[i]);
    For(i,1,n) D[i] = {a[i],i};
    For(i,1,n){
        sort(D+1,D+1+n);
        if(D[n].fi == 0) break;
        Forr(i,n-1,1){
            if(D[n].fi == 0) break;
            if(D[i].fi == 0 && D[n].fi != 0){
                cout << "NO\n";
                return 0;
            }
            D[i].fi--;
            D[n].fi--;
            A[D[i].se][D[n].se] = A[D[n].se][D[i].se] = 1;
        }
    }
    For(i,1,n) D[i] = {b[i],i};
    For(i,1,n){
        sort(D+1,D+1+n);
        if(D[n].fi == 0) break;
        Forr(i,n-1,1){
            if(D[n].fi == 0) break;
            if(D[i].fi == 0 && D[n].fi != 0){
                cout << "NO\n";
                return 0;
            }
            D[i].fi--;
            D[n].fi--;
            B[D[i].se][D[n].se] = B[D[n].se][D[i].se] = 1;
        }
    }
    printf("YES\n");
    For(i,1,n){
        For(j,1,n){
            if(i == j) printf("0 ");
            if(i < j) printf("%d ",A[i][j]);
            if(i > j) printf("%d ",B[i][j]);
        }
        printf("\n");
    }
}
