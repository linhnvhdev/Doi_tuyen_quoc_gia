#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 10005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
#define pii pair<int,int>
using namespace std;

int n,k,s,m,cnt = 0;
int spe[maxn];

vector<int> a[maxn];

map<string,int> mp;

string S,T;
string b[10005];

int txt[maxn];
bool done[maxn];

bool used[10001][10001];

void Sub1()
{
    bool used[1005];
    memset(used,false,sizeof(used));
    For(i,1,s) used[spe[i]] = true;
    int ans = 0;
    For(i,1,n)
        For(u,1,n)
            Forv(j,a[u])
            {
                int v = a[u][j];
                if(used[u] || used[v]) used[u] = used[v] = true;
            }
    vector<string>  special;
    For(i,1,cnt)
    {
        ans += used[i];
        if(used[i]) special.push_back(b[i]);
    }
    cout << ans << endl;
    sort(special.begin(),special.end());
    Forv(i,special) cout << special[i] << ' ' ;
    exit(0);
}

void Sub2()
{
    queue<int> q;
    vector<string> special;
    For(i,1,s)
    {
        q.push(spe[i]);
        txt[spe[i]] = k;
    }
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        if(txt[u] < k) continue;
        for(int i = 0; i < a[u].size();i++)
        {
            int v = a[u][i];
            if(used[u][v] || txt[v] >= k) continue;
            txt[v]++;
            used[u][v] = used[v][u] = true;
            if(txt[v] == k) q.push(v);
        }
    }
    For(i,1,n) if(txt[i] >= k) special.push_back(b[i]);
    cout << special.size() << endl;
    sort(special.begin(),special.end());
    Forv(i,special) cout << special[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SPECONE.inp","r",stdin);
    freopen("SPECONE.out","w",stdout);
    cin >> n >> k >> s >> m;
    For(i,1,s)
    {
        cin >> S;
        if(mp[S] == 0) mp[S] = ++cnt;
        spe[i] = mp[S];
        b[spe[i]] = S;
    }
    For(i,1,m)
    {
        cin >> S >> T;
        if(mp[S] == 0) mp[S] = ++cnt;
        if(mp[T] == 0) mp[T] = ++cnt;
        int d1 = mp[S],d2 = mp[T];
        b[d1] = S;
        b[d2] = T;
        a[d1].push_back(d2);
        a[d2].push_back(d1);
    }
    if(k == 1 && n <= 100 && m <= 1000) Sub1();
    else Sub2();
}
