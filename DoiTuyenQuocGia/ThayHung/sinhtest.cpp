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
    freopen("SUBSEQ.inp","w",stdout);
    int n = 100000;
    int k = random(0,1e9);
    cout << n << ' ' << k << endl;
    For(i,1,n) cout << random(-1e9,1e9) << ' ' ;
    cout << endl;
}
