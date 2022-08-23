#include<bits/stdc++.h>
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1000005
#define ll long long
#define INF 1e9
#define pii pair<int,int>
using namespace std;

int random(int l,int r)
{
    return l + (1ll*rand()*rand() + rand())%(r-l+1);
}

bool used[maxn];

int main()
{
    srand(time(NULL));
    freopen("AMN.inp","w",stdout);
    int n = 10;
    int m = 10;
    int u = random(1,10);
    int v = random(1,10);
    cout << n <<' ' << m << ' ' << u << ' ' << v << endl;
    For(i,1,n)
    {
        For(j,1,m)
        {
            int a = 1;
            a = random(1,n*m);
            while(used[a])
                a = random(1,n*m);
            used[a] = true;
            cout << a << ' ';
        }
        cout << endl;
    }
}
