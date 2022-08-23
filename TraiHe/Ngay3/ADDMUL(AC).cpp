#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 100500, mod = 1e9 + 7;

int n, q, arr[N];
ll a[N << 2], b[N << 2], t[N << 2], p[N << 2];
void push(int v, int l1, int l2){
	if(p[v] == -1){
		t[v << 1] = (t[v << 1] * a[v] + b[v] * l1) % mod;
 		t[v << 1 | 1] = (t[v << 1 | 1] * a[v] + b[v] * l2) % mod;
 		if(p[v << 1] == -1){
 			a[v << 1] = a[v << 1] * a[v] % mod;
 			b[v << 1] = (b[v << 1] * a[v] + b[v]) % mod;
 		}else
 			p[v << 1] = (p[v << 1] * a[v] + b[v]) % mod;

 		if(p[v << 1 | 1] == -1){
 			a[v << 1 | 1] = a[v << 1 | 1] * a[v] % mod;
 			b[v << 1 | 1] = (b[v << 1 | 1] * a[v] + b[v]) % mod;
 		}else
 			p[v << 1 | 1] = (p[v << 1 | 1] * a[v] + b[v]) % mod;
    }else{
		p[v << 1] = p[v];
		t[v << 1] = p[v] * l1 % mod;
		p[v << 1 | 1] = p[v];
		t[v << 1 | 1] = p[v] * l2 % mod;
	}
	p[v] = -1, a[v] = 1, b[v] = 0;
}
void build(int v, int tl, int tr){
	if(tl == tr){
		t[v] = p[v] = arr[tl];
		return;
	}
	int tm = (tl + tr) >> 1;
	build(v << 1, tl, tm);
	build(v << 1 | 1, tm + 1, tr);
	t[v] = (t[v << 1] + t[v << 1 | 1]) % mod;
	p[v] = -1, a[v] = 1, b[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int k, int tt){
	if(r < tl || tr < l)
		return;
	if(l <= tl && tr <= r){
		if(tt == 1){
			t[v] = (t[v] + 1ll * (tr - tl + 1) * k) % mod;
			if(p[v] != -1)
				p[v] = (p[v] + k) % mod;
			else
				b[v] = (b[v] + k) % mod;
		}
		if(tt == 2){
			t[v] = t[v] * k % mod;
			if(p[v] != -1)
				p[v] = p[v] * k % mod;
			else
				a[v] = a[v] * k % mod, b[v] = b[v] * k % mod;
		}
		if(tt == 3){
			t[v] = 1ll * (tr - tl + 1) * k % mod;
			p[v] = k;
		}
		return;
	}
	int tm = (tl + tr) >> 1;
	push(v,tm - tl + 1, tr - tm);
	upd(v << 1, tl, tm, l, r, k, tt);
	upd(v << 1 | 1, tm + 1, tr, l, r, k, tt);
	t[v] = (t[v << 1] + t[v << 1 | 1]) % mod;
}
int get(int v, int tl, int tr, int l, int r){
	if(r < tl || tr < l)
		return 0;
	if(l <= tl && tr <= r)
		return t[v];
	int tm = (tl + tr) >> 1;
	push(v,tm - tl + 1, tr - tm);
	return (get(v << 1, tl, tm, l, r) + get(v << 1 | 1, tm + 1, tr, l, r)) % mod;
}
int main()
{
	scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	build(1, 1, n);
	while(q--){
		int type, l, r, k;
		scanf("%d%d%d", &type, &l, &r);
		if(type < 4){
			scanf("%d", &k);
			upd(1, 1, n, l, r, k, type);
		}else
			printf("%d\n", get(1, 1, n, l, r));
	}
	return 0;
}
