#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1000005
#define ll long long
#define INF 1e18
using namespace std;

int MAX = 1e7;
int n;
ll a[maxn];
int used[10000005];

ll lcm(ll a,ll b)
{
    return a*b/__gcd(a,b);
}

int main()
{
    cin >> n;
    ll maxa = 0;
    ll ans = INF;
    pair<int,int> best;
    For(i,1,n)
    {
        cin >> a[i];
        maxa = max(maxa,a[i]);
        if(used[a[i]])
        {
            if(ans > a[i])
            {
                ans = a[i];
                best = {used[a[i]],i};
            }
        }
        else used[a[i]] = i;
    }
    ll curmin,A;
    For(g,1,maxa)
    {
        curmin = -1;
        For(i,1,maxa/g)
        {
            A = g*i;
            if(used[A])
            {
                if(curmin != -1)
                {
                    if(lcm(A,curmin) < ans)
                    {
                        ans = lcm(A,curmin);
                        best = {used[A],used[curmin]};
                    }
                    else break;
                }
                else curmin = A;
            }
        }
    }
    //cout << ans << endl;
    cout << min(best.fi,best.se) << ' ' << max(best.fi,best.se) << endl;
}
