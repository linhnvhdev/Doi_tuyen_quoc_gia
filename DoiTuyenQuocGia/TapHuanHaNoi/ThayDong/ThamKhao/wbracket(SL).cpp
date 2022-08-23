#include <bits/stdc++.h>
#define nmax 125
#define N 202
#define oo 10000000007
#define reset(x) memset(x, 0, sizeof x)
#define F first
#define S second
#define sonin cin
#define sonout cout
#define PB(x) push_back(x)
#define debug(x) cout << "Loli -> " << #x << " : " << x << "\n"
#define filename "WBRACKET"
#define fileNX freopen(filename".inp", "r", stdin); freopen(filename".out", "w", stdout);
#define fileN freopen(filename".inp", "r", stdin);
#define fileX freopen(filename".out", "w", stdout);
#define toiuuhoa ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define SZ(a) (int) a.size()
#define FOU(x,a,b) for (lli x=a;x<=b;x++)
#define FOD(x,a,b) for (lli x=a;x>=b;x--)
#define FOA(a,b) for(auto &a:b)
#define ALLvec(a) a.begin(),a.end()
#define REU(x,a,b) for (lli x=a;x<b;x++)
#define RED(x,a,b) for (lli x=a;x>b;x--)
#define AutoCinAry(a,b,x) for(int a = 1; a<=b; a++) cin >> x[i];
#define dembit1(x) __builtin_popcount(x)
#define bit(x,i) (x>>(i-1)&1ll)
#define on(x,i) (x|(1ll<<(i-1)))
#define off(x,i) (x&~(1ll<<(i-1)))
#define EL cout << "\n";
#define EX exit(0);
#define Ary(x, i, j, a) x[(i - 1) * a + j]
#define epsinon 1e-8
using namespace std;
typedef long long lli;
typedef long double ldo;
typedef double dou;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli, lli> pii;
typedef vector<pii> vpi;

lli mod = 1e18 + 11;

lli n, k;
lli f[nmax][nmax*2][2];
string a;

lli dequy(lli id, lli open, lli ok){
    if(id == n)
        return (ok || (open != 0));
    if(f[id][open + N][ok] != -1)
        return f[id][open + N][ok];
    lli &ret = f[id][open + N][ok];
    ret = 0;
    ret = (ret + dequy(id+1, open + 1, ok))%mod;
    ret = (ret + dequy(id+1, open - 1, (ok || ((open - 1) < 0))))%mod;
    return ret;
}
void trace(lli id, lli open, lli ok){
    if(id == n)
        return;
    if(dequy(id + 1, open + 1, (ok)) < k){
        a[id] = ')';
        k = k - dequy(id + 1, open + 1, (ok));
        trace(id + 1, open - 1, (ok || ((open - 1) < 0)));
    } else {
        a[id] = '(';
        trace(id + 1, open + 1, (ok));
    }
}

int main(){
    fileNX
    toiuuhoa
    sonin >> n >> k;

    a.resize(n);
    memset(f, -1, sizeof f);
    dequy(0, 0, 0);
    trace(0, 0, 0);

    sonout << a;

    return 0;
}
