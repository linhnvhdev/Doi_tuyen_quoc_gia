#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define int long long
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
int m,n,f[1000];
struct oo {int x,y,z;};
oo R(oo u) {return {7-u.z,u.y,u.x};}
oo L(oo u) {return {u.z,u.y,7-u.x};}
oo D(oo u) {return {7-u.y,u.x,u.z};}
bool ss(oo u,oo v)
{
    return !(abs(u.x-v.x)+abs(u.y-v.y)+abs(u.z-v.z));
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("ROLLING.inp","r",stdin);
    freopen("ROLLING.out","w",stdout);
    cin>>m>>n;
    if(n%4==0) return cout<<m*(n/2)*7,0;
    int cur=n%4-1;
    oo s={6,2,3},_s;
    f[1]=6;
    forinc(i,1,cur) s=R(s),f[1]+=s.x;
    int cc=1;_s=s;
    bool o=1;
    while(1)
    {
        o^=1;
        s=D(s);
        int sl=s.x;
        forinc(i,1,cur)
        {
            if(o) s=R(s);
            else s=L(s);
            sl+=s.x;
        }
        if(o&&ss(s,_s)) break;
        ++cc;
        f[cc]=f[cc-1]+sl;
    }
    cout<<m*((n-n%4)/2)*7+(m/cc)*f[cc]+f[m%cc];
}
