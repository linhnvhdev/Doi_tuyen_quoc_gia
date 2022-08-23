#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define INF 1e15
#define Bit(x,i) ((x >>i)&1)
using namespace std;

ll a[4],r[4],n[4];
ll cnt[maxn];

void Sub1()
{
    For(i,1,3)
        For(j,0,n[i]-1) cnt[++cnt[0]] = a[i] + j*r[i];
    sort(cnt+1,cnt+1+cnt[0]);
    cnt[0] = unique(cnt+1,cnt+1+cnt[0]) - cnt - 1;
    cout << cnt[0] << endl;
    exit(0);
}

ll bcnn(ll x,ll y)
{
    return (x*y)/__gcd(x,y);
}

void Sub2()
{
    ll ans = 0;
    For(i,1,7){
        ll S = 1, R = 1,N = INF;
        bool ok = true;
        For(j,0,2){
            if(!Bit(i,j)) continue;
            ll P = min(S + (N-1)*R,a[j+1] + r[j+1]*(n[j+1]-1));
            for(int k = 1; k <= r[j+1]; k++,S += R)
                if(S % r[j+1] == a[j+1] % r[j+1]) break;
            if(S % r[j+1] != a[j+1] % r[j+1]){
                ok = false;
                break;
            }
            R = bcnn(R,r[j+1]);
            for(;S < a[j+1]; S += R);
            if(P < S){
                ok = false;
                break;
            }
            N = (P - S + R)/R;
        }
        if(!ok) continue;
        if(__builtin_popcount(i) % 2 == 1)
            ans += N;
        else ans -= N;
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PRO3.inp","r",stdin);
    freopen("PRO3.out","w",stdout);
    bool sub2 = true;
    For(i,1,3){
        cin >> a[i] >> r[i] >> n[i];
        //if(a[i] > 100 || r[i] > 100) sub2 = false;
    }
    Sub2();
}
