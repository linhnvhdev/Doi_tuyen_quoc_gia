#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 500005
#define ll long long
#define INF 1e18
#define pii pair<int,int>
using namespace std;

int n;
string s;

int a[maxn];

vector<int> adj[maxn];

int in[maxn],out[maxn];

int main()
{
    fast_read;
    cin >> s;
    n = s.size();
    ll ans = 0;
    For(i,0,n-1)
    {
        if(s[i] == '<')
            adj[i+1].push_back(i+2),in[i+2]++;
        else
            adj[i+2].push_back(i+1),in[i+1]++;
    }
    queue<pair<int,int> > tp;
    For(i,1,n+1) if(in[i] == 0) tp.push({i,0});
    while(!tp.empty())
    {
        int u = tp.front().fi;
        a[u] = tp.front().se;
        tp.pop();
        for(int v : adj[u])
        {
            in[v]--;
            if(in[v] == 0)
                tp.push({v,a[u]+1});
        }
    }
    ans = 0;
    For(i,1,n+1) ans += a[i];
    cout << ans << endl;
}
