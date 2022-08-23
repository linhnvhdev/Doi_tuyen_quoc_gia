#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,m;
ll x[28];
string s;

ll a[3][28];

int cs[28],d = 0;

bool avail[27],used[10],bg[28];
ll ans = 0;

void check()
{
    cerr << "#############\n";
    For(j,1,d) cerr << char(cs[j] + 'A') << ' ' << x[j] << endl;
    cerr << "*********\n";
}

void dfs(int i)
{
    if(i == d+1){
        ll vt = 0,vp = 0;
        For(j,1,d) vt += a[1][cs[j]]* x[j];
        For(j,1,d) vp += a[2][cs[j]]* x[j];
        //check();
        if(vt == vp){
            //check();
            //cerr << vt << ' ' << vp << endl;
            ans++;
        }
        return;
    }
    For(j,0,9){
        if(!used[j]){
            //if(cs[i] == 'Z' - 'A') cerr << cs[i] << ' ' << bg[cs[i]] << endl;
            if(bg[cs[i]] && j == 0) continue;
            //if(cs[i] == 26) cerr << j << ' ' << bg[cs[i]] << endl;
            x[i] = j;
            used[j] = true;
            dfs(i+1);
            used[j] = false;
            //x[i] = -1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ARTIFACT.inp","r",stdin);
    freopen("ARTIFACT.out","w",stdout);
    cin >> n >> m;
    For(i,1,n){
        cin >> s;
        ll lt10 = 1;
        for(int i = (s.size() - 1) ;i >= 0;i--){
            a[1][s[i] - 'A'] += lt10;
            lt10 *= 10;
            avail[s[i] - 'A'] = true;
        }
        if(s.size() > 1) bg[s[0] - 'A'] = true;
    }
    For(i,1,m){
        cin >> s;
        long long lt10 = 1;
        for(int i = (s.size() - 1) ;i >= 0;i--){
            a[2][s[i] - 'A'] += lt10;
            lt10 *= 10;
            avail[s[i] - 'A'] = true;
        }
        if(s.size() > 1) bg[s[0] - 'A'] = true;
        //cerr << s[0] << ' ' << bg[s[0] -'A'] << endl;
    }
    For(i,0,26) if(avail[i]) cs[++d] = i;
    //cerr << endl;
    dfs(1);
    cout << ans << endl;
}
