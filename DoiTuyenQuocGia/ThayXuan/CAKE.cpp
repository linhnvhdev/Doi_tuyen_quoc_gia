#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0; i < a.size();i++)
#define maxn 50000
#define ll long long
#define fi first
#define se second
#define INF 1e9
#define pii pair<int,int>
using namespace std;

map<string,int> mp;

void init(int n)
{
    string st = "";
    Forr(i,n,1) st += char(i + '0');
    queue<string> q;
    mp[st] = 0;
    q.push(st);
    string s,s2;
    while(!q.empty())
    {
        s = q.front();
        int step = mp[s];
        q.pop();
        For(i,0,n-1)
        {
            s2 = s;
            reverse(s2.begin()+i,s2.begin()+n);
            if(mp.find(s2) == mp.end())
            {
                mp[s2] = step + 1;
                q.push(s2);
            }
        }
    }
}

int t,n;
pair<int,int> a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAKE.inp","r",stdin);
    freopen("CAKE.out","w",stdout);
    For(i,1,8) init(i);
    cin >> t;
    string s;
    while(t--)
    {
        s = "";
        cin >> n;
        For(i,1,n)
        {
            cin >> a[i].fi;
            a[i].se = i;
        }
        sort(a+1,a+1+n);
        For(i,0,n-1) s += "#";
        For(i,1,n) s[a[i].se-1] = char(i+'0');
        cout << mp[s] << '\n';
    }
}
