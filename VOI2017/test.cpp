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

map<string,int> mp,mp2;

void Init(map<string,int> &mp,string st)
{
    queue<string> q;
    q.push(st);
    string u,g,p,r,s,v;
    mp[st] = 0;
    while(!q.empty())
    {
        u = q.front();
        int cur_step = mp[u];
        if(cur_step == 2) break;
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

map<string,int>::iterator it;

bool ok[maxn];

int main()
{
    fast_read;
    freopen("VO17SORT.inp","r",stdin);
    freopen("VO17SORT.out","w",stdout);
    cin >> t;
    string st = "",ed = "";
    while(t--)
    {
        cin >> n;
        if(!ok[n])
        {
            ed = "";
            For(j,1,n) ed += char('0' + j);
            Init(mp,ed);
        }
        ok[n] = true;
        For(i,1,n) cin >> a[i];
        st = "";
        For(i,1,n) st += char('0' + a[i]);
        if(mp.find(st) != mp.end())
            cout << mp[st] << '\n';
        else
        {
            mp2.clear();
            Init(mp2,st);
            int ans = 5;
            for(it = mp.begin();it != mp.end();it++)
            {
                string x = it->fi;
                if(mp2.find(x) != mp2.end())
                    ans = min(ans,it->se + mp2[x]);
            }
            if(ans == 5) cout << "5 or more\n";
            else cout << ans << '\n';
        }
    }
}
