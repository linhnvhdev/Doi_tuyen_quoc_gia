#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
#define INF 1e18
#define pii pair<ll,ll>
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int n;
ll k;
pii p[maxn],newp[maxn],newp2[maxn];
ll x[maxn],y[maxn],ans = INF,ss = INF;

ll dist(pii p1,pii p2)
{
    return abs(p2.fi - p1.fi) + abs(p2.se - p1.se);
}

void checksuongsuong()
{
    sort(x+1,x+1+n);
    sort(y+1,y+1+n);
    ll midx = x[(n+1)/2],midy = y[(n+1)/2];
    ll cost = 0;
    For(i,1,n)
    {
        cost += abs(midx - x[i]);
        cost += abs(midy - y[i]);
        if(cost > k) break;
    }
    if(cost <= k)
    {
        cout << 0 << endl;
        For(i,1,n)
        {
            cout << midx << ' ' << midy << endl;
        }
        exit(0);
    }
}

void Sub1()
{
    For(i,1,n) newp[i] = p[i];
    sort(newp+1,newp+1+n);
    ll ans1 = 0;
    For(i,1,n-1)
    {
        if(k == 0) break;
        ll d = dist(newp[i],newp[i+1]);
        //cout << d << endl;
        if(d == 0) continue;
        if(d > k)
        {
            d = k;
            ll new_x = min(newp[i].fi + d,newp[i+1].fi);
            d -= (new_x - newp[i].fi);
            newp[i].fi = new_x;
            if(d > 0)
            {
                if(newp[i].se > newp[i+1].se) newp[i].se -= d;
                else newp[i].se += d;
            }
            break;
        }
        if(d == k)
        {
            newp[i] = newp[i+1];
            break;
        }
        else if(d == 1)
        {
            if(newp[i].fi < newp[i+1].fi) newp[i].fi = newp[i+1].fi;
            else newp[i].se = newp[i+1].se;
            k--;
        }
    }
    For(i,1,n)
        For(j,i+1,n)
            ans1 += dist(newp[i],newp[i+1]);

    For(i,1,n) newp2[i] = {p[i].se,p[i].fi};
    sort(newp2+1,newp2+1+n);
    ll ans2 = 0;
    For(i,1,n-1)
    {
        if(k == 0) break;
        ll d = dist(newp2[i],newp2[i+1]);
        if(d == 0) continue;
        if(d > k)
        {
            ll new_x = min(newp2[i].fi + d,newp2[i+1].fi);
            d -= (new_x - newp2[i].fi);
            newp2[i].fi = new_x;
            if(d > 0)
            {
                if(newp2[i].se > newp2[i+1].se) newp2[i].se -= d;
                else newp2[i].se += d;
            }
            break;
        }
        if(d == k)
        {
            newp2[i] = newp2[i+1];
            break;
        }
        else if(d == 1)
        {
            if(newp2[i].fi < newp2[i+1].fi) newp2[i].fi = newp2[i+1].fi;
            else newp2[i].se = newp2[i+1].se;
            k--;
        }
    }
    For(i,1,n)
        For(j,i+1,n)
            ans2 += dist(newp2[i],newp2[i+1]);
    if(ans1 < ans2)
    {
        cout << ans1 << endl;
        For(i,1,n) cout << newp[i].fi << ' ' << newp[i].se << endl;
    }
    else
    {
        cout << ans2 << endl;
        For(i,1,n) cout << newp2[i].se << ' ' << newp2[i].fi << endl;
    }
}

int main()
{
    fast_read;
    freopen("TIGERSUGAR2.inp","r",stdin);
    freopen("TIGERSUGAR2.out","w",stdout);
    cin >> n >> k;
    For(i,1,n)
    {
        cin >> x[i] >> y[i];
        p[i] = {x[i],y[i]};
    }
    checksuongsuong();
    if(n <= 1000) Sub1();
}
