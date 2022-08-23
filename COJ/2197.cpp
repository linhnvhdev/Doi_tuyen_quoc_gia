/**
    Gọi S[i][j] là các tiền tố của các hậu tố thứ i có độ dài là 2^j
    Xét j = 0 -> log2n ở bước thứ i ta sẽ sắp xếp các s[i][j] theo thứ tự từ điển và lưu thứ tự của s[i][j] trong mảng p[i][j]
    Lưu ý 2 xâu = thì 2 P = nhau
    Gsử  đã có thứ tự  ở bước j  khi đó ở bước j + 1 có đc = vc ghép s[i][j] và s[i + 2^j][j] -> s[i][j+1]
    việc sắp xếp các s[i][j+1] là dựa trên (p[i][j],p[i+2^j][j])
    => sa[p[i][m]] = i với i = 0 -> n-1
**/


#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,logn = 0,p[maxn][17],id[maxn];
string s,s2;
pair<pair<int,int>,int> L[maxn];

int main()
{
    cin >> s;
    n = s.size();
    while((1ll << logn) < n) logn++;
    for(int i = 0;i < n;i++)
        p[i][0] = s[i];
    For(j,1,logn){
        /// L[i] = {{p[i][j-1],p[i+(1<<(j-1))][j-1]},i};
        For(i,0,n-1)
            L[i] = {{p[i][j-1],(i + (1<<(j-1)) < n) ? p[i+(1<<(j-1))][j-1] : -1},i};
        sort(L,L+n);
        For(i,0,n-1) p[L[i].se][j] = (i > 0 && L[i].fi == L[i-1].fi) ? p[L[i-1].se][j] : i;
    }
    For(i,0,n-1) id[p[i][logn]] = i;
    For(i,0,n-1) printf("%d\n",id[i]);
    return 0;
}
