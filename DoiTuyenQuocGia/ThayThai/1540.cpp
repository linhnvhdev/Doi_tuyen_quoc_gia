#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 50005
#define ll long long
#define x first
#define y second
#define INF 1e18
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int t;
int n;
ll a[maxn],k;

vector<ll> uoc;
ll b[20];

void phantich(ll k)
{
    for(int i = 2;i <= sqrt(k);i++)
    {
        if(k % i == 0)
        {
            ll tmp = 1;
            while(k % i == 0)
            {
                tmp *= i;
                k /= i;
            }
            uoc.push_back(tmp);
        }
    }
    if(k != 1) uoc.push_back(k);
}

void Sub2()
{
    uoc.clear();
    phantich(k);
    memset(b,0,sizeof(b));
    if(k == 1)
    {
        ll ucln = a[1];
        For(i,2,n) ucln = __gcd(ucln,a[i]);
        if(ucln == 1) cout << "YES\n";
        else cout <<"NO\n";
        return;
    }
    For(i,1,n)
    {
        for(int j = 0;j < uoc.size();j++)
            if(a[i] % uoc[j] == 0)
                b[j] = __gcd(b[j],a[i]);
    }
    bool ok = true;
    for(int i = 0;i < uoc.size();i++)
    {
        if(b[i] == 0 || k % b[i] != 0)
        {
            ok = false;
            break;
        }
    }
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        For(i,1,n) scanf("%lld",&a[i]);
        scanf("%lld",&k);
        Sub2();
    }
}
