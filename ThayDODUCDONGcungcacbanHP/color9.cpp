#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 105
#define Bit(x,i) ((x >> i)&1)
#define fi first
#define se second
using namespace std;

int m,n,k;
char c[maxn][maxn];
int a[maxn][maxn];

int check2(int i,int j)
{
    int temp = 0;
    if(a[i][j] == 1) return 0;
    if(a[i][j] == a[i-1][j]) temp++;
    if(a[i][j] == a[i][j-1]) temp++;
    return temp;
}

int check3(int i,int j)
{
    int temp = 0;
    if(a[i][j] == 1) return 0;
    if(i > 2 && a[i][j] == a[i-1][j] && a[i][j] == a[i-2][j]) temp++;
    if(j > 2 && a[i][j] == a[i][j-1] && a[i][j] == a[i][j-2]) temp++;
    if(a[i][j] == a[i-1][j] && a[i][j] == a[i-1][j-1]) temp++;
    if(a[i][j] == a[i-1][j] && a[i][j] == a[i-1][j+1]) temp++;
    if(a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j-1]) temp++;
    if(a[i][j] == a[i+1][j] && a[i][j] == a[i+1][j+1]) temp++;
    return temp;
}

void Sub1()
{
    int cur = 0;
    For(i,1,m)
        For(j,1,n) if(!a[i][j]) cur++;
    cout << cur << endl;
    exit(0);
}

void Sub2()
{
    int cur = 0;
    For(i,1,m)
        For(j,1,n) cur += check2(i,j);
    cout << cur << endl;
    exit(0);
}

void Sub3()
{
    int cur = 0;
    For(i,1,m)
        For(j,1,n) cur += check3(i,j);
    cout << cur << endl;
    exit(0);
}

int main()
{
    //freopen("color9.inp","r",stdin);
    //freopen("color9.out","w",stdout);
    scanf("%d%d%d",&m,&n,&k);
    For(i,0,m+1)
        For(j,0,n+1) a[i][j] = 1e9;
    For(i,1,m)
        For(j,1,n){
            cin >> c[i][j];
            a[i][j] = c[i][j] - '0';
        }
    if(k == 1) Sub1();
    if(k == 2) Sub2();
    if(k == 3) Sub3();
}
