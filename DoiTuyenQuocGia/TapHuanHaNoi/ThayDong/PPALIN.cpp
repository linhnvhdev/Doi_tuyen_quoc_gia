//{
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100004
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;
//}

string s;
int n,K;

int t[maxn][27],le[maxn][27],chan[maxn][27];

int get(int arr[maxn][27],int i,int j,int kt)
{
    return arr[j][kt] - arr[i-1][kt];
}

int main()
{
    fast_read;
    freopen("PPALIN.inp","r",stdin);
    freopen("PPALIN.out","w",stdout);
    cin >> s >> K;
    n = s.size();
    s = '0' + s;
    For(i,1,n)
    {
        For(j,0,26) le[i][j] = le[i-1][j];
        For(j,0,26) chan[i][j] = chan[i-1][j];
        if(i % 2 == 1)
            le[i][s[i] - 'a']++;
        if(i % 2 == 0)
            chan[i][s[i] - 'a']++;
    }
    int i = 1,j = i+1, ans = 1;
    while(i <= j && j <= n)
    {
        if(i == j) {j++; continue;}
        pii bestle = {-1e9,0};
        pii bestchan = {-1e9,0};
        For(k,0,26)
        {
            int Le = get(le,i,j,k);
            int Chan = get(chan,i,j,k);
            if(Le > bestle.fi) bestle = {Le,k};
            if(Chan > bestchan.fi) bestchan = {Chan,k};
        }
        int chk = (j-i+1) - bestchan.fi - bestle.fi;
        if(chk <= K) ans = max(ans,j-i+1);
        if(chk <= K) j++;
        else i++;
    }
    cout << ans << endl;
}
