#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
#define fi first
#define se second
using namespace std;

const int add = 2500000;
int n,m,a[maxn][maxn],s[maxn][maxn],cnt = 0;
int p[maxn][maxn];
pair<int,int> d[2][5000005];

int gett(int i,int j,int k,int l)
{
    return s[k][l] - s[k][j-1] - s[i-1][l] + s[i-1][j-1];
}

int main()
{
    scanf("%d",&n);
    For(i,1,n)
        For(j,1,n){
            scanf("%d",&a[i][j]);
            //a[i][j] = 1;
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
            p[i][j] = ++cnt;
        }
    ll ans = 0;
    For(i,1,n)
        For(j,1,n){
            //cout << " ######## " << i << ' ' << j << endl;
            For(k,1,i){
                For(l,1,j){
                    //cout <<"! " <<  min(k,i) << ' ' << min(l,j) << ' ' << max(k,i) << ' ' << max(l,i) << ' ' << gett(k,l,i,j) << endl;
                    int tong = gett(k,l,i,j) + add;
                    if(d[0][tong].fi != p[i][j]) d[0][tong] = {p[i][j],1};
                    else d[0][tong].se++;
                }
                For(l,j,n){
                    //cout <<"! " <<  min(k,i) << ' ' << min(l,j) << ' ' << max(k,i) << ' ' << max(l,i) << ' ' << gett(k,j,i,l) << endl;
                    int tong = gett(k,j,i,l) + add;
                    if(d[1][tong].fi != p[i][j]) d[1][tong] = {p[i][j],1};
                    else d[1][tong].se++;
                }
            }
            For(k,i+1,n){
                For(l,1,j-1){
                    //cout <<"%% " <<  i+1 << ' ' << l << ' ' << ' ' << k << ' ' << j-1 << endl;
                    int tong = gett(i+1,l,k,j-1) + add;
                    //cout << tong - add << ' ' << d[1][tong].fi << ' ' << d[1][tong].se << endl;
                    if(d[1][tong].fi != p[i][j]) continue;
                    else ans += d[1][tong].se;
                }
                For(l,j+1,n){
                    int tong = gett(i+1,j+1,k,l) + add;
                    if(d[0][tong].fi != p[i][j]) continue;
                    else ans += d[0][tong].se;
                }
            }
        }
    cout << ans << endl;
    return 0;
}
