#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 105
#define Bit(x,i) ((x >> i) & 1)
#define fi first
#define INF 1e9
#define se second
using namespace std;

string s,t;
int n,m,d[maxn][maxn];
int a[maxn][maxn];

void Init()
{
    For(k,0,n)
        For(i,0,n)
            For(j,0,n)
                if(d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
}

int main()
{
    cin >> s >> t;
    scanf("%d",&m);
    n = 26;
    For(i,0,n)
        For(j,0,n) d[i][j] = INF;
    For(i,0,n) d[i][i] = 0;
    For(i,1,m){
        char c1,c2;
        int w;
        cin >> c1 >> c2 >> w;
        d[c1-'a'][c2-'a'] = min(d[c1-'a'][c2-'a'],w);
    }
    if(s.size() != t.size()){
        cout << -1 << endl;
        return 0;
    }
    Init();
    int ans = 0;
    string Sans = "";
    for(int i = 0;i < s.size();i++){
        int x = s[i] - 'a',y = t[i] - 'a',curmin = INF,minc = -1;
        for(int j = 0;j < 26;j++)
            if(d[x][j] != INF && d[y][j] != INF && d[x][j] + d[y][j] < curmin){
                curmin = d[x][j] + d[y][j];
                minc = j;
            }
        if(minc == -1){
            cout << -1 << endl;
            return 0;
        }
        ans += curmin;
        Sans += char(minc + 'a');
    }
    cout << ans << endl << Sans << endl;
}
