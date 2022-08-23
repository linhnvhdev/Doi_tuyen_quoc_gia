/// Impressive Tree
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

ll n,R,G,B;
ll Rn = 0,Gn = 0,Bn = 0;
int hang = 0;
int tt[maxn],cnt = 0;
ll lt3[maxn];

int main()
{
    cin >> R >> G >> B >> n;
    for(ll i = 1; n > 0; i*= 3){
        hang++;
        if(n < i) break;
        n -= i;
    }
    hang--;
    //cout << n << ' ' << hang << endl;
    ll thuong = n,du;
    while(hang--){
        du = thuong % 3;
        thuong = (thuong % 3 == 0) ? thuong/3 : thuong/3+1;
        if(du != 0) tt[++cnt] = du;
        else tt[++cnt] = 3;
    }
    ll Rn = R, Gn = G,Bn = B;
    //Forr(i,cnt,1) cout << tt[i] << ' ' ;
    //cout << endl;
    Forr(i,cnt,1){
        ll r,g,b;
        if(tt[i] == 1){
            r = Rn + Gn;
            g = Bn;
            b = Gn;
        }
        if(tt[i] == 2){
            r = Bn;
            g = Gn + Bn;
            b = Rn;
        }
        if(tt[i] == 3){
            r = Gn;
            g = Rn;
            b = Bn + Rn;
        }
        Rn = r;
        Gn = g;
        Bn = b;
    }
    cout << Rn << ' ' << Gn << ' ' << Bn << endl;
}

