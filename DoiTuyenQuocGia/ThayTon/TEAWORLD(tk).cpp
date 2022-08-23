#include <bits/stdc++.h>
using namespace std;
#define whole(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define ins insert
#define ft first
#define sd second
#define _(a) #a << " : " << (a)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
//----------------------------------------------------------
const int inf = 1e9, maxn = 1e6 + 1;
const ll inff = 1e18;
const ld eps = 1e-9, pi = acos (-1);
const int maxm = 1e3 + 1;
int n, k, m;
struct vec;
typedef vec point;
struct vec
{
	ld x, y, z;
	vec () {}
	vec (ld xx, ld yy, ld zz)
	{
		x = xx, y = yy, z = zz;
	}
	vec (point a, point b)
	{
		x = b.x - a.x;
		y = b.y - a.y;
		z = b.z - a.z;
	}
	ld operator * (vec a)
	{
		return a.x * x + a.y * y + a.z * z;
	}
};
ld length (vec a)
{
	return sqrt (a.x * a.x + a.y * a.y + a.z * a.z);
}
ld angle (vec a, vec b)
{
	ld prod = a * b, la = length (a), lb = length (b);
	ld g = prod / (la * lb);
	if (g < 0) g += eps;
	else g -= eps;
	return acos (g);
}
struct sphere
{
	point o;
	ld r;
	sphere () {}
	sphere (point oo, ld rr)
	{
		o = oo, r = rr;
	}
	bool contain (point a)
	{
		ld d = length (vec (o, a));
		return d <= r;
	}
};
struct shop
{
	point p;
	ld e;
};
bool equal (double x, double y)
{
	return abs (x - y) <= eps;
}
point mid_point (point a, point b)
{
	return point ((a.x + b.x) / 2, (a.y + b.y) / 2, (a.z + b.z) / 2);
}
void print (point a)
{
	cout << a.x << ' ' << a.y << ' ' << a.z << '\n';
}

ld get_min_dist (point a, point b, point c)
{
	while (!(equal(a.x, b.x) and equal (a.y, b.y) and equal (a.z, b.z)))
	{
		point m = mid_point (a, b);
		ld cma = angle (vec (m, c), vec (m, a));
		ld cmb = angle (vec (m, c), vec (m, b));
		if (cma < cmb) b = m;
		else a = m;
	}
	return length (vec (a, c));
}

bool sphere_in_between (point &a, point &b, sphere &c)
{
	bool a_in = c.contain (a), b_in = c.contain (b);
	if (a_in and b_in) return 0;
	else if (a_in ^ b_in) return 1;
	return get_min_dist (a, b, c.o) <= c.r;
}

point s;
shop shop_list [16];
sphere sphere_list [maxm];
vector <int> between[16];
int cnt[maxn] = {};
ld res = 0;

void attempt (int id, int s_cnt, ld en_sum)
{
	//cout << id << ' ' << s_cnt << ' ' << en_sum << '\n';
	if (k >= s_cnt)  res = max (res, en_sum);
	for (int i = id + 1; i <= n; ++i)
	{
		int h = s_cnt;
		for (int j : between[i])
		{
			++cnt[j];
			if (cnt[j] == 1) ++h;
		}
		attempt (i, h, en_sum + shop_list[i].e);
		for (int j : between[i])
			--cnt[j];
	}
}

void input ()
{
	cin >> m >> n >> k;
	ld x, y, z, g;
	for (int i = 1; i <= m; ++i)
	{
		cin >> x >> y >> z >> g;
		sphere_list[i] = sphere (point (x, y, z), g);
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >> x >> y >> z >> g;
		shop_list[i] = shop {point (x, y, z), g};
	}
	cin >> x >> y >> z;
	s = point (x, y, z);
}

void solve ()
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (sphere_in_between (s, shop_list[i].p, sphere_list[j]))
				between[i].pb (j);
	attempt (0, 0, 0);
	cout << res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie (NULL);
	cout.tie (NULL);
	freopen ("teaworld.inp", "r", stdin);
	freopen ("teaworld.out", "w", stdout);
	input ();
	solve ();
}

