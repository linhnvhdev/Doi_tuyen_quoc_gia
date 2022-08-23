#include <bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

const int mod = 1e9+7;
const int base = 128;

int n,k;

ll p[maxn];
ll h[55][maxn];
int maxs = 0;

string s[55];

ll get_hash(ll h[maxn],int i,int j)
{
    return ((h[j] - h[i-1]*p[j-i+1])%mod+mod)%mod;
}

bool check(int len)
{
    vector<pair<ll,int> > v;
    For(i,1,n)
        For(j,1,(int) s[i].size() - len + 1)
            v.push_back({get_hash(h[i],j,j+len-1),i});
    sort(v.begin(),v.end());
    v.resize(unique(v.begin(),v.end()) - v.begin());
    int cnt = 1;
    for(int i = 1;i < v.size();i++)
    {
        if(v[i].fi == v[i-1].fi)
            cnt++;
        else
            cnt = 1;
        if(cnt >= k) return true;
    }
    return false;
}

int Sub12()
{
    int l = 0,r = maxs;
    while(r - l > 1)
    {
        int mid = (r+l)/2;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(check(r)) return r;
    return l;
}

ll sums;

int main()
{
    fast_read;
    freopen("VO17TV.txt","r",stdin);
    freopen("VO17TV.txt","w",stdout);
    cin >> n >> k;
    p[0] = 1;
    For(i,1,100000) p[i] = p[i-1]*base%mod;
    For(i,1,n)
    {
        cin >> s[i];
        For(j,1,(int)s[i].size())
            h[i][j] = (h[i][j-1]*base + s[i][j-1])%mod;
        maxs = max(maxs,(int)s[i].size());
        sums += s[i].size();
    }
    cout << Sub12() << endl;
    return 0;
}
