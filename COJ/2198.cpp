#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,m,logn = 0,p[2*maxn][19],id[2*maxn];
string s,S;
pair<pair<int,int>,int> L[2*maxn];

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >>  S;
    while((1ll << logn) < n) logn++;
    For(i,0,n-1) p[i][0] = S[i];
    //cout << m << ' ' << s << endl;
    For(j,1,logn){
        For(i,0,n-1)
            L[i] = {{p[i][j-1],(i+(1<<(j-1)) < n) ? p[i+(1<<(j-1))][j-1] : p[(i+(1<<(j-1)))%n][j-1]},i};
        sort(L,L+n);
        For(i,0,n-1) p[L[i].se][j] = (i > 0 && L[i].fi == L[i-1].fi) ? p[L[i-1].se][j] : i;
    }
    //For(i,0,m-1) cout <<"# "<< i << ' ' << p[i][logn] << endl;
    For(i,0,m-1) id[p[i][logn]] = i;
    int ans = 1e9,curmin = -1;
    For(i,0,n-1){
        //cout << i << ' ' << p[i][logn-1] << endl;
        if(p[i][logn] < ans){
            ans = p[i][logn];
            curmin = i;
        }
    }
    cout << curmin << endl;
}
