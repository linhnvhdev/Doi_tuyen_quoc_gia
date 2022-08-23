/**

(*)
{
    For(x,0,n)
        For (y,x,n)
            For(z,y,n)
            {
                string p1 = u.substr(0,x);
                string p2 = u.substr(x,y-x);
                string p3 = u.substr(y,z-y);
                string p4 = u.substr(z,n-z);
                string v = p1 + p3 + p2 + p4;
            }
}

map<string,int> bfs(string s)
{
    map<string,int> res;
    res[s] = 0;
    queue<string> q;
    q.push(s);
    while(!q.empty())
    {
        string u = q.front(); q.pop();
        For(string v : adj[u])(*)
        {
            if(res.find(v) == res.end())
            {j
                res[v] = res[u] + 1;
                if(res[v] < 2) q.push(v);
            }
        }
    }
    return res;
}
**/


/// Code nay duoc sinh ra chi de quay xo so :)
#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 5005
#define ll long long
#define INF 1e18
using namespace std;

int t,n;
map<string,int> res;
int a[maxn];

void bfs(string s)
{
    res.clear();
    res[s] = 0;
    queue<string> q;
    q.push(s);
    while(!q.empty())
    {
        string u = q.front(); q.pop();
        For(x,0,n)
        For(y,x,n)
        For(z,y,n)
        {
            string p1 = u.substr(0,x);
            string p2 = u.substr(x,y-x);
            string p3 = u.substr(y,z-y);
            string p4 = u.substr(z,n-z);
            string v = p1 + p3 + p2 + p4;
            if(res.find(v) == res.end())
            {
                res[v] = res[u] + 1;
                if(res[v] < 4) q.push(v);
            }
        }
    }
}

int main()
{
    fast_read;
    freopen("kittens.inp","r",stdin);
    freopen("kittens.out","w",stdout);
    cin >> t;
    while(t--)
    {
        cin >> n;
        For(i,1,n) cin >> a[i];
        string st = "",ed = "";
        For(i,1,n) st += char(a[i] + '0');
        For(i,1,n) ed += char(i + '0');
        cerr << st << ' ' << ed << endl;
        bfs(st);
        if(res.find(ed) != res.end()) cout << res[ed] << endl;
        else cout <<"5 or more\n";
    }
}
