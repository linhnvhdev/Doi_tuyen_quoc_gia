#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

const int base = 128;
const int mod = 1e9 + 7;

int k,n,m;
string s,t;
int ans[maxn],cnt = 0;
ll h1[maxn],h2[maxn],p[maxn];

ll get_hash(ll h[maxn],int i,int j)
{
    if(i > j) return 0;
    return ((h[j] - h[i-1]*p[j-i+1]) % mod + mod) % mod;
}

bool check(int l,int mid)
{
    return(get_hash(h1,l+1,mid+1) == get_hash(h2,1,mid-l+1));
}

int Chat(int i,int j)
{
    int l = i,r = j;
    while(r - l > 1){
        int mid = (r + l)/2;
        if(check(i,mid)) l = mid;
        else r = mid;
    }
    if(s[l] != t[l - i]) return l;
    else if(s[r] != t[r - i]) return r;
    else return -1;
}

void Solve()
{
    p[0] = 1;
    For(i,1,n) p[i] = p[i-1]*base%mod;
    For(i,1,n) h1[i] = (h1[i-1]*base + s[i-1]) % mod;
    For(i,1,m) h2[i] = (h2[i-1]*base + t[i-1]) % mod;
    //For(i,1,n) cout << h1[i] << endl;
    //cout << get_hash(h1,4,5) << ' ' << get_hash(h2,2,3) << endl;
    For(i,0,n - m){
        int j = i + m - 1;
        int vt = Chat(i,j);
        if(vt == -1 || vt + k > j || s[vt + k] == t[vt + k - i]) continue;
        else
            if(get_hash(h1,vt+1+1,vt+k-1+1) == get_hash(h2,vt + 1 - i + 1,vt + k - 1 - i + 1)
                && get_hash(h1,vt + k + 1 + 1,j + 1) == get_hash(h2,vt + k + 1 + 1 - i,m))
                    ans[++cnt] = i;
    }
    printf("%d\n",cnt);
    For(i,1,cnt-1) printf("%d ",ans[i]+1);
    if(cnt != 0) printf("%d\n",ans[cnt]+1);
}

int main()
{
    //freopen("VIRUS.inp","r",stdin);
    //freopen("VIRUS.out","w",stdout);
    cin >> s >> t >> k;
    n = s.size();
    m = t.size();
    Solve();
}
