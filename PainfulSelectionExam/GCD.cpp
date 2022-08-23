#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; i++)
#define Forr(i,a,b) for(int i = a; i >= b; i--)
#define maxn 100005
#define Bit(x, i) ((x >> i) & 1)
#define ll long long
using namespace std;

int n, a[maxn], q, len, prime[maxn];
vector<int> p[maxn];
bool used[maxn];
ll bit[350][maxn];

void updatebit(int vt,int mul,int val)
{
    for(int i = vt;i <= n/len; i += (i &(-i)))
        bit[i][mul] += val;
}

ll getbit(int vt,int mul)
{
    ll tmp = 0;
    for(int i = vt;i > 0;i -=(i&(-i)))
        tmp += bit[i][mul];
    return tmp;
}

void Init()
{
    For(i, 1, 100000) prime[i] = 1;
    prime[1] = 0;
    For(i,2,100000)
        if(prime[i]){
            p[i].push_back(i);
            for(int j = i * 2; j <= 100000; j += i){
                prime[j] = 0;
                p[j].push_back(i);
            }
        }
}

void Update(int t, int g, int val)
{
    int sz = p[g].size();
    For(x, 1, (1 << sz) - 1)
    {
        int Mul = 1;
        For(i, 0, sz - 1)
            if(Bit(x,i))
                Mul *= p[g][i];
        updatebit(t+1,Mul,val);
    }
}

int Cnt(int r, int mul)
{
    int ans = 0, t = (r - 1) / len;
    ans += getbit(t,mul);
    /**For(i, 0, t - 1)
        ans += c[i][mul];**/
    For(i, t * len + 1, r)
        if(a[i] % mul == 0)ans++;
    return ans;
}

int Query(int r, int g)
{
    int sz = p[g].size(), ans = r;
    if(g == 1) return r;
    For(x, 1, (1 << sz) - 1){
        int Mul = 1, J = 0;
        For(i,0, sz - 1)
            if(Bit(x, i) == 1){
                Mul *= p[g][i];
                J++;
            }
        if(J % 2 == 1) ans -= Cnt(r, Mul);
        else
            ans += Cnt(r, Mul);
    }
    return ans;
}

int main()
{
    //freopen("GCD.inp", "r", stdin);
    //freopen("GCD.out", "w", stdout);
    scanf("%d", &n);
    len = sqrt(n);
    Init();
    For(i,1,n) scanf("%d",&a[i]);
    For(i,1,n)
        Update((i - 1) / len, a[i], 1);
    scanf("%d", &q);
    while(q--)
    {
        int type;
        scanf("%d", &type);
        if(type == 1){
            int x, y;
            scanf("%d%d", &x, &y);
            Update((x - 1) / len, a[x], -1);
            Update((x - 1) / len, y, 1);
            a[x] = y;
        }
        else{
            int l,r,g;
            scanf("%d%d%d",&l,&r,&g);
            printf("%d\n", Query(r,g) - Query(l-1,g));
        }
    }
}
