#include <bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 16
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int t,n;

int a[maxn];

map<string,int> mp;

void Sub2(string st)
{
    queue<string> q;
    q.push(st);
    string u,g,p,r,s,v;
    mp[st] = 0;
    while(!q.empty())
    {
        u = q.front();
        int cur_step = mp[u];
        if(cur_step == 4) break;
        //cout << u << ' ' << cur_step << endl;
        q.pop();
        For(x,0,n)
        For(y,x,n)
        For(z,y,n)
        {
            g = u.substr(0,x);
            r = u.substr(x,y-x);
            p = u.substr(y,z-y);
            s = u.substr(z,n-z);
            v = g + p + r + s;
            if(mp.find(v) == mp.end() || mp[v] > cur_step + 1)
            {
                mp[v] = cur_step + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    fast_read;
    freopen("VO17SORT.txt","r",stdin);
    freopen("VO17SORT.txt","w",stdout);
    cin >> t;
    string st = "",ed = "";
    For(i,1,7)
    {
        n = i;
        ed = "";
        For(j,1,i) ed += char('0' + j);
        Sub2(ed);
    }
    while(t--)
    {
        cin >> n;
        For(i,1,n) cin >> a[i];
        if(n <= 7)
        {
            st = "";
            For(i,1,n) st += char('0' + a[i]);
            if(mp.find(st) != mp.end())
                cout << mp[st] << '\n';
            else cout << "5 or more\n";
        }
        else if(n == 10) cout << 4 << endl;
        else cout << "5 or more\n";
    }
}
