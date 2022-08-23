#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,q,X;
struct cricket{
    int x;
    ll t;
    int id;
} p[maxn],d[maxn];

vector<ll> g[maxn];

bool cmp(cricket u,cricket y)
{
    return u.t < v.t;
}

void compress()
{
    int cnt = 0;
    ll cp[maxn];
    For(i,1,n) cp[i] = p[i].x;
    sort(cp+1,cp+1+n);
    X = unique(cp+1,cp+1+n) - cp - 1;
    For(i,1,n){
        p[i].x = lower_bound(cp+1,cp+1+X,p[i].x) - cp;
        d[i].x = p[i].x;
    }
    //cout << MaxA << endl; For(i,1,n) cout << a[i] << endl;
}

int main()
{
    scanf("%d",&n);
    For(i,1,n){
        scanf("%d%lld",&p[i].x,&p[i].t);
        p[i].id = i;
        d[i] = {p[i].x,p[i].t + p[i].x,i};
    }
    compress();
    sort(d+1,d+1+n,cmp);
    sort(p+1,p+1+n,cmp);

}
/**

**/
