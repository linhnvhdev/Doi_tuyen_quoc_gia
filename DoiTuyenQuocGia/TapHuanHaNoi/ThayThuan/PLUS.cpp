#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define fast_read ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define maxn 100005
#define ll long long
#define fi first
#define se second
using namespace std;

ll a,b;
int step = 0;

int ans[5005];

void print(int t)
{
    if(t == 1) cout << "A+=A\n";
    if(t == 2) cout << "B+=B\n";
    if(t == 3) cout << "B+=A\n";
    if(t == 4) cout << "A+=B\n";
}

int main()
{
    fast_read;
    cin >> a >> b;
    int step = 0;
    while(a != b && step < 5000)
    {
        ll d = __gcd(a,b);
        a /= d;
        b /= d;
        if(a % 2 == b % 2)
        {
            ll c = min(a,b);
            if(c == a)
            {
                ans[++step] = 3;//B += A
                ans[++step] = 1;//A += A
            }
            else
            {
                ans[++step] = 4; //A+=B
                ans[++step] = 2; //B+=B
            }
            a+=c;
            b+=c;
        }
        else
        {
            if(a % 2 == 1)ans[++step] = 1;
            else ans[++step] = 2;
            if(a%2 == 1) a*=2;
            else b*=2;
        }
    }
    cout << step << endl;
    For(i,1,step)
        print(ans[i]);
}
