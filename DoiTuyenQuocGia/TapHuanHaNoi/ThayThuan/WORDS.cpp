#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
using namespace std;

int n;
int a[105][105],k;
int child[10*maxn][3],cnt = 0;
int leaf[10*maxn],maxlen = 0;

string s;

void Add(string s)
{
    int u = 0;
    Forv(i,s)
    {
        int x = s[i] - '0';
        if(child[u][x] == 0) child[u][x] = ++cnt;
        u = child[u][x];
    }
    leaf[u] = 1;
}

int get(int x,int y,int len)
{
    int u = 0;
    For(i,y,y+len-1)
    {
        int kt = a[x][i];
        if(child[u][kt] == 0) return 0;
        u = child[u][kt];
    }
    return leaf[u];
}

int main()
{
    cin >> n;
    For(i,1,n)
        For(j,1,n)
            cin >> a[i][j];
    cin >> k;
    For(i,1,k)
    {
        cin >> s;
        maxlen = max(maxlen,(int)s.size());
        Add(s);
    }
    int ans = 0;
    For(i,1,n)
        For(j,1,n)
        {
            For(k,1,maxlen)
            {
                if(j + k - 1 > n) break;
                ans += get(i,j,k);
            }
        }
    cout << ans << endl;
}
