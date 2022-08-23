#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 400005
#define ull long long
#define fi first
#define se second
using namespace std;

int n;
ull L,R;

ull curdis = -(1ull<<63) ,curx = 0;

ull a[maxn];

void update(ull x,ull mid,ull y)
{
    if(mid < L || mid > R) return;
    ull dis = min(abs(x - mid),abs(y - mid));
    //cerr << x << ' ' << mid << ' ' << y <<endl << ' ' << dis << endl;
    if(curdis <= dis){
        if(curdis == dis) curx = max(curx,mid);
        else curx = mid;
        curdis = dis;
    }
    //cerr << x << ' ' << mid << ' ' << y << ' ' << curdis << ' ' << curx << endl;
}

ull Solve()
{
    if(L >= a[n])
        return R;
    if(R <= a[1])
        return L;
    int vt1 = lower_bound(a+1,a+1+n,L) - a;
    int vt2 = lower_bound(a+1,a+1+n,R) - a;
    if(L <= a[1])
        update(-(1ull<<63),L,a[1]);
    else{
        update(a[vt1-1],L,a[vt1]);
        update(L,(L+a[vt1]+1)/2,a[vt1]);
        update(L,(L+a[vt1])/2,a[vt1]);
    }
    //cerr << curdis <<' ' << curx<< endl;
    if(R >= a[n])
        update(a[n],R,(1ull<<63));
    else{
        update(a[vt2-1],R,a[vt2]);
        update(a[vt2-1],(R+a[vt2-1])/2,R);
    }
    //cerr << curdis << ' ' << curx << endl;
    //cerr << a[1] << ' ' << a[2] << ' ' << (a[1] + a[2] + 1) << endl;
    if(n == 2){
        update(a[1],(a[1] + a[2] + 1)/2,a[2]);
        update(a[n],a[n],a[n]);
        return curx;
    }
    For(i,2,n-1){
        //cerr << (a[i-1]) << ' ' << (a[i-1] + a[i] + 1)/2;
        update(a[i-1],(a[i-1]+a[i]+1)/2,a[i]);
        update(a[i],a[i],a[i]);
        update(a[i],(a[i] + a[i+1] + 1)/2,a[i+1]);
    }
    return curx;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("MAXDIS.inp","r",stdin);
    freopen("MAXDIS.out","w",stdout);
    cin >> n >> L >> R;
    For(i,1,n) cin >> a[i];
    sort(a+1,a+1+n);
    cout << Solve();
    return 0;
}
