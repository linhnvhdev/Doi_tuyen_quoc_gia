#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
#define fi first
#define se second
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int child[1000005][2],sz = 0;

string A,B;
int n,m;
int x[maxn];

string kt[maxn];

void Add(string s)
{
    //cout << s << endl;
    int u = 0;
    for(int i = 0;i < s.size();i++){
        int k = s[i]-'0';
        if(!child[u][k]) child[u][k] = ++sz;
        u = child[u][k];
    }
    //kt[u] = s;
    //cout << " " << u << endl;
}

string ans = "";

int len;

void dfs(int u,int i)
{
    //cout << u << ' ' << i << ' ' << len << ' ' << kt << endl;
    if(i >= len) return;
    //cout << child[u][0] << ' ' << child[u][1] << endl;
    if(!child[u][0] || !child[u][1]){
        ans = "";
        //cout << ":)\n";
        For(j,1,i-1) ans += char(x[j] + '0');
        if(!child[u][0]) ans += '0';
        else ans +='1';
        len = i;
        //cout << ans << ' ' << len << endl;
        return;
    }
    x[i] = 0;
    dfs(child[u][0],i+1);
    x[i] = 1;
    dfs(child[u][1],i+1);
}

void check()
{

}

int main()
{
    cin >> A >> B;
    n = A.size(); m = B.size();
    len = max(m,n);
    string xd = "";
    if(n == 1 && m == 1 && A[0] != B[0]){
        cout << "00" << endl;
        return 0;
    }
    string Xd = "";
    Forr(i,n-1,0){
        Xd = A[i] + Xd;
        Add(Xd);
    }
    Xd = "";
    Forr(i,m-1,0){
        Xd = B[i] + Xd;
        Add(Xd);
    }
    check();
    //cout << sz << endl;
    dfs(0,1);
    cout << ans << endl;

}
/**
10
7 2 6 8 5 11 3 4 12 17
**/
