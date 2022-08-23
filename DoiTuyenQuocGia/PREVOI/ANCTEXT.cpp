#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 300005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

const int maxcs = 500000;
int T;
string S,s[maxn];

int n,pre[maxn],q;

int child[maxcs+5][27],cnt = 0;

int last[maxcs*27],leaf[maxcs*27];

int d[maxcs*27];

void Add(int id,string s)
{
    int u = 0;
    for(int i = 0;i < s.size();i++)
    {
        int x = s[i] - 'a';
        if(child[u][x] == 0) child[u][x] = ++cnt;
        u = child[u][x];
        d[u] = min(d[u],id);
    }
    leaf[u] = min(leaf[u],id);
    last[id] = u;
}

int get(int l,int r)
{
    //cout << S.substr(l-1,r-l+1) << endl;
    int u = 0;
    bool nhohon = false;
    int ans = -1;
    For(i,l-1,r-1)
    {
        int x = S[i] - 'a';
        //cout << u << ' ' << leaf[u] << ' ' << ans << endl;
        if(child[u][x] != 0)
        {
            //cout << ":))\n";
            u = child[u][x];
        }
        else
        {
            //cout << ":((\n";
            nhohon = true;
            Forr(j,x-1,0)
            {
                if(child[u][x] != 0)
                {
                    u = child[u][x];
                    break;
                }
            }
        }
        if(nhohon) ans = d[u];
        else
            if(leaf[u] != 1e9)
                ans = leaf[u];
    }
    return ans;
}

void Sub()
{
    For(i,0,maxcs) leaf[i] = 1e9;
    For(i,1,n) s[i] = s[pre[i]] + s[i];
    For(i,1,n)
        Add(i,s[i]);
    cin >> q;
    For(i,1,q)
    {
        int l,r;
        cin >> l >> r;
        cout << get(l,r) << '\n';
    }
}

bool sub1 = true;

void Sub1()
{
    For(i,1,n) s[i] = s[pre[i]] + s[i];
    cin >> q;
    For(i,1,q)
    {
        int l,r,best = -1;
        cin >> l >> r;
        string t = S.substr(l-1,r-l+1);
        //cout << t << endl;
        For(i,1,n)
        {
            if(s[i].compare(t) <= 0)
            {
                //cout << s[i] << ' ' << t << ' ' << s[i].compare(t) << endl;
                if(best == -1) best = i;
                else
                {
                    if(s[best].compare(s[i]) < 0)
                        best = i;
                }
            }
        }
        cout << best << endl;
    }
}

int main()
{
    fast_read;
    freopen("ANCTEXT.inp","r",stdin);
    freopen("ANCTEXT.out","w",stdout);
    cin >> T;
    while(T--)
    {
        cin >> S >> n;
        if(S.size() > 2000) sub1 = false;
        For(i,1,n)
        {
            cin >> pre[i] >> s[i];
            if(s[i].size() > 2000) sub1 = false;
        }
        if(n <= 2000 && q <= 2000 && sub1) Sub1();
    }
}
