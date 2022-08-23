#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<int,int>
#define debug4(i,j,k,l) cerr << i << ' ' << j << ' ' << k << ' ' << l << '\n';
#define debug3(i,j,k) cerr << i << ' ' << j << ' ' << k << '\n';
#define debug2(i,j) cerr << i << ' ' << j<< '\n';
#define debug1(i) cerr << i << '\n';
using namespace std;
struct bignum {vector<int> a;int sign;int size(){if(a.empty())return 0;int ans=(a.size()-1)*9;int ca=a.back();while(ca)    ans++,ca/=10;return ans;}bignum operator ^(const bignum &v){bignum ans=1,a=*this,b=v;while(!b.isZero()){    if(b%2)	ans*=a;    a*=a,b/=2;}return ans;}string to_string(){stringstream ss;ss << *this;string s;ss >> s;return s;}int sumof(){string s = to_string();int ans = 0;for(auto c : s)  ans += c - '0';return ans;}bignum() :sign(1) {}bignum(long long v) {*this = v;}bignum(const string &s) {read(s);}void operator=(const bignum &v) {sign = v.sign;a = v.a;}void operator=(long long v) {sign = 1;a.clear();if (v < 0)    sign = -1, v = -v;for (; v > 0; v = v / 1000000000)    a.push_back(v % 1000000000); } bignum operator+(const bignum &v) const {if (sign == v.sign) {    bignum res = v;    for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {	if (i == (int) res.a.size())	    res.a.push_back(0);	res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);	carry = res.a[i] >= 1000000000;	if (carry)	    res.a[i] -= 1000000000;    }    return res;}return *this - (-v);} bignum operator-(const bignum &v) const {if (sign == v.sign) {  if (abs() >= v.abs()) {bignum res = *this;for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) { res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0); carry = res.a[i] < 0; if (carry)res.a[i] += 1000000000;}res.trim();return res; }    return -(v - *this);}return *this + (-v);}void operator*=(int v) {if (v < 0) sign = -sign, v = -v;for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {if (i == (int) a.size())a.push_back(0);long long cur = a[i] * (long long) v + carry;carry = (int) (cur / 1000000000); a[i] = (int) (cur % 1000000000);}trim();}bignum operator*(int v) const {bignum res = *this;res *= v;return res;}void operator*=(long long v) {if (v < 0) sign = -sign, v = -v;for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {if (i == (int) a.size())a.push_back(0);long long cur = a[i] * (long long) v + carry;carry = (int) (cur / 1000000000);a[i] = (int) (cur % 1000000000);}trim(); }bignum operator*(long long v) const {bignum res = *this;res *= v;return res; }friend pair<bignum, bignum> divmod(const bignum &a1, const bignum &b1) {int norm = 1000000000 / (b1.a.back() + 1);bignum a = a1.abs() * norm;bignum b = b1.abs() * norm;bignum q, r;q.a.resize(a.a.size());for (int i = a.a.size() - 1; i >= 0; i--) { r *= 1000000000; r += a.a[i]; int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()]; int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1]; int d = ((long long) 1000000000 * s1 + s2) / b.a.back(); r -= b * d;    while (r < 0)	r += b, --d;    q.a[i] = d;}q.sign = a1.sign * b1.sign;r.sign = a1.sign;q.trim();r.trim();return make_pair(q, r / norm); }bignum operator/(const bignum &v) const {return divmod(*this, v).first; } bignum operator%(const bignum &v) const {return divmod(*this, v).second;  } void operator/=(int v) {if (v < 0)    sign = -sign, v = -v;for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {    long long cur = a[i] + rem * (long long) 1000000000;    a[i] = (int) (cur / v);    rem = (int) (cur % v);}trim(); }bignum operator/(int v) const {bignum res = *this;res /= v;return res;}int operator%(int v) const {if (v < 0)    v = -v;int m = 0;for (int i = a.size() - 1; i >= 0; --i)    m = (a[i] + m * (long long) 1000000000) % v;return m * sign;}void operator+=(const bignum &v) {*this = *this + v;}void operator-=(const bignum &v) {*this = *this - v;}void operator*=(const bignum &v) {*this = *this * v;}void operator/=(const bignum &v) {*this = *this / v; } bool operator<(const bignum &v) const {if (sign != v.sign)   return sign < v.sign;if (a.size() != v.a.size())   return a.size() * sign < v.a.size() * v.sign;for (int i = a.size() - 1; i >= 0; i--)    if (a[i] != v.a[i])	return a[i] * sign < v.a[i] * sign;return false; }bool operator>(const bignum &v) const {return v < *this; } bool operator<=(const bignum &v) const {return !(v < *this); } bool operator>=(const bignum &v) const {return !(*this < v); } bool operator==(const bignum &v) const {return !(*this < v) && !(v < *this); } bool operator!=(const bignum &v) const {return *this < v || v < *this; } void trim() {while (!a.empty() && !a.back())    a.pop_back();if (a.empty())    sign = 1; } bool isZero() const {return a.empty() || (a.size() == 1 && !a[0]);}bignum operator-() const {bignum res = *this;res.sign = -sign;return res;  }bignum abs() const {bignum res = *this;res.sign *= res.sign;return res; } long long longValue() const {long long res = 0;for (int i = a.size() - 1; i >= 0; i--)    res = res * 1000000000 + a[i];return res * sign;  }friend bignum gcd(const bignum &a, const bignum &b) {return b.isZero() ? a : gcd(b, a % b); } friend bignum lcm(const bignum &a, const bignum &b) {return a / gcd(a, b) * b; } void read(const string &s) {sign = 1;a.clear();int pos = 0;while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {   if (s[pos] == '-')	sign = -sign;    ++pos;}for (int i = s.size() - 1; i >= pos; i -= 9) {   int x = 0;   for (int j = max(pos, i - 9 + 1); j <= i; j++)	x = x * 10 + s[j] - '0';    a.push_back(x);}trim(); } friend istream& operator>>(istream &stream, bignum &v) {string s;stream >> s;v.read(s);return stream;  } friend ostream& operator<<(ostream &stream, const bignum &v) {if (v.sign == -1)    stream << '-';stream << (v.a.empty() ? 0 : v.a.back());for (int i = (int) v.a.size() - 2; i >= 0; --i)    stream << setw(9) << setfill('0') << v.a[i];return stream;  }static vector<int> convert_1000000000(const vector<int> &a, int obignum_digits, int new_digits) {vector<long long> p(max(obignum_digits, new_digits) + 1);p[0] = 1;for (int i = 1; i < (int) p.size(); i++)   p[i] = p[i - 1] * 10;vector<int> res;long long cur = 0;int cur_digits = 0;for (int i = 0; i < (int) a.size(); i++) {cur += a[i] * p[cur_digits]; cur_digits += obignum_digits;    while (cur_digits >= new_digits) {	res.push_back(int(cur % p[new_digits]));	cur /= p[new_digits];	cur_digits -= new_digits;    }}res.push_back((int) cur);while (!res.empty() && !res.back())    res.pop_back();return res;} typedef vector<long long> vll; static vll karatsubaMultiply(const vll &a, const vll &b) {int n = a.size();vll res(n + n);if (n <= 32) {for (int i = 0; i < n; i++)for (int j = 0; j < n; j++)res[i + j] += a[i] * b[j];return res;}int k = n >> 1;vll a1(a.begin(), a.begin() + k);vll a2(a.begin() + k, a.end());vll b1(b.begin(), b.begin() + k);vll b2(b.begin() + k, b.end()); vll a1b1 = karatsubaMultiply(a1, b1);vll a2b2 = karatsubaMultiply(a2, b2);for (int i = 0; i < k; i++)a2[i] += a1[i];for (int i = 0; i < k; i++)b2[i] += b1[i]; vll r = karatsubaMultiply(a2, b2);for (int i = 0; i < (int) a1b1.size(); i++)r[i] -= a1b1[i];for (int i = 0; i < (int) a2b2.size(); i++)r[i] -= a2b2[i]; for (int i = 0; i < (int) r.size(); i++)res[i + k] += r[i];for (int i = 0; i < (int) a1b1.size(); i++)res[i] += a1b1[i];for (int i = 0; i < (int) a2b2.size(); i++)res[i + n] += a2b2[i];return res;} bignum operator*(const bignum &v) const {vector<int> a6 = convert_1000000000(this->a, 9, 6);vector<int> b6 = convert_1000000000(v.a, 9, 6);vll a(a6.begin(), a6.end());vll b(b6.begin(), b6.end());while (a.size() < b.size())a.push_back(0);while (b.size() < a.size())b.push_back(0);while (a.size() & (a.size() - 1))a.push_back(0), b.push_back(0);vll c = karatsubaMultiply(a, b);bignum res;res.sign = sign * v.sign;for (int i = 0, carry = 0; i < (int) c.size(); i++) {long long cur = c[i] + carry;res.a.push_back((int) (cur % 1000000));carry = (int) (cur / 1000000);}res.a = convert_1000000000(res.a, 6, 9);res.trim();return res;}};

int n;
string s[maxn*maxn],t[maxn];

bignum pw2[105];

int main()
{
    fast_read;
    freopen("BR.inp","r",stdin);
    freopen("BR.out","w",stdout);
    cin >> n;
    bignum ans = 0;
    int cnt = n,m = 0;
    For(i,1,n)
    {
        cin >> s[i];
        int sz = s[i].size();
        int j = 1;
        while(j < sz && s[i][j] == s[i][j-1])
            s[++cnt] = s[i][j++];
        s[i] = s[i].substr(j-1);
        m = max(m,(int)s[i].size());
    }
    For(i,1,cnt)
    {
        int sz = s[i].size();
        bignum cur = 1;
        For(i,1,m-sz) cur*=2;
        Forr(j,sz-1,0)
        {
            if(s[i][j] == 'B') ans += cur;
            else ans -= cur;
            cur *= 2;
        }
    }
    c//err << ans << endl;
    if(ans > 0) cout << 'B';
    else cout << 'R';
}
