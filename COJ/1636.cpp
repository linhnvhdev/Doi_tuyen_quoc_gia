/**
    for(int i = -1,cur = (1<<n)-1;cur != 0;)
    {
        int min_len,best_j,best_len = INF;
        string min_str,best_str;
        for(int j = 0;j < n;j++)
        {
            if(Bit(cur,j))
            {
                if(i == -1)
                {
                    min_len = len[cur][j];
                    min_str = s[j];
                }
                else
                {
                    min_len = len[cur][j] - over[i][j];
                    min_str = s[j].substr(over[i][j],l[j] - over[i][j];
                }
            }
            if((min_len < best_len) || (min_len == best_len && min_str < best_str))
            {
                best_j = j;
                best_len = min_len;
                best_str = min_str;
            }
        }
        cout << best_str;
        i = best_j;
        cur ^= (1<<best_j);
    }
**/


#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 20
#define pii pair<int,int>
#define fi first
#define se second
#define INF 1e9
#define ll long long
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n,m;
string s[maxn],a[maxn],ans;
int dp[1<<16][20],d[maxn][maxn],vet[1<<16][20];
int ss[maxn][maxn];

bool used[maxn];

int combine(string s1,string s2,string &S)
{
    int minlen = min(s1.size(),s2.size());
    int res = -INF;
    int l1 = s1.size();
    int l2 = s2.size();
    S = s1 + s2;
    For(i,1,minlen)
        if(s1.compare(l1 - i,i,s2,0,i) == 0 && res < i)
        {
            res = i;
            S = s1 + s2.substr(i);
        }
    return res;
}

int sosanh(string s1,string s2)
{
    int len = min(s1.size(),s2.size());
    For(i,0,len-1)
    {
        if(s1[i] < s2[i]) return -1;
        if(s1[i] > s2[i]) return 1;
    }
    if(s1.size() > s2.size()) return -1;
    if(s1.size() < s2.size()) return 1;
    return 0;
}

int main()
{
    //freopen("test.out","w",stdout);
    int m = 0;
    cin >> n;
    For(i,1,n) cin >> a[i];
    For(i,1,n)
        For(j,1,n)
            if(i != j && a[i].find(a[j]) != a[i].npos)
                used[j] = true;
    For(i,1,n) if(!used[i]) s[++m] = a[i];
    if(m == 0)
    {
        cout << a[1] << endl;
        return 0;
    }
    n = m;
    string S;
    For(i,0,n-1)
        For(j,0,n-1)
            d[i][j] = combine(s[i+1],s[j+1],S);
    For(i,0,n-1)
        For(j,0,n-1) ss[i][j] = sosanh(s[i+1],s[j+1]);
    For(mask,1,(1<<n)-1)
        For(i,0,n-1)
            dp[mask][i] = 1e9;
    For(i,0,n-1)
        dp[(1<<i)][i] = s[i+1].size();
    for(int mask = 1;mask < (1<<n);mask++)
    {
        For(i,0,n-1)
        {
            if(Bit(mask,i))
                For(j,0,n-1)
                    if(j != i && Bit(mask,j))
                    {
                        int pre_mask = mask ^ (1<<i);
                        int add = (d[i][j] == -INF) ? s[i+1].size() : s[i+1].size() - d[i][j];
                        if(dp[mask][i] > dp[pre_mask][j] + add)
                            dp[mask][i] = dp[pre_mask][j] + add;
                    }
        }
    }
    //cout << dp[(1<<n)-1] << endl;
    for(int i = -1,cur = (1<<n)-1;cur != 0;)
    {
        int min_len,best_j,best_len = 1e9;
        string min_str,best_str;
        for(int j = 0;j < n;j++)
        {
            if(Bit(cur,j))
            {
                if(i == -1)
                {
                    min_len = dp[cur][j];
                    min_str = s[j+1];
                }
                else
                {
                    if(d[i][j] == -1e9)
                    {
                        min_len = dp[cur][j];
                        min_str = s[j+1];
                    }
                    else
                    {
                        min_len = dp[cur][j] - d[i][j];
                        //cerr << s[j+1].size() << ' ' << d[i][j] << endl;
                        min_str = s[j+1].substr(d[i][j],s[j+1].size() - d[i][j]);
                    }
                }
            }
            if((min_len < best_len) || (min_len == best_len && min_str < best_str))
            {
                best_j = j;
                best_len = min_len;
                best_str = min_str;
            }
        }
        cout << best_str;
        i = best_j;
        cur ^= (1<<best_j);
    }
    cout << '\n';
}
