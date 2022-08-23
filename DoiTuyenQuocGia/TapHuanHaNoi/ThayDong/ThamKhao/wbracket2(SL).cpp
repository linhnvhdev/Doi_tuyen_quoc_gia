
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
        return (ok && (open == 0));
    if(f[id][open + N][ok] != -1)
        return f[id][open + N][ok];
    lli &ret = f[id][open + N][ok];
    ret = 0;
    ret = (ret + dequy(id+1, open + 1, ok))%mod;
    ret = (ret + dequy(id+1, open - 1, (ok || ((open - 1) < 0))))%mod;
    return ret;
}

int main(){
    fileNX
    toiuuhoa
    sonin >> n >> k;

    n*=2;
    a.resize(n);
    memset(f, -1, sizeof f);
    dequy(0, 0, 0);
    trace(0, 0, 0);

    sonout << a;

    return 0;
}
