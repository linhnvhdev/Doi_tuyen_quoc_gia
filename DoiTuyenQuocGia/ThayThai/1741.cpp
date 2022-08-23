#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define INF 1e18
#define Bit(x,i) ((x >> i)&1)
#define ll long long
using namespace std;

ll X,Y,ans = 0;
map<ll,int> mp;

void Sub2()
{
    int ans = 0;
    For(i,1,63)
    {
        if((1ll << i) > Y) break;
        For(j,0,63)
        {
            ll addA = 0,cur = 0;
            int curt = 1;
            For(k,0,i-1) addA += (1ll << k);
            if(addA > Y/(1ll << j)) break;
            while(true){
                if(curt == 1)
                {
                    cur = cur*(1ll << i) + addA;
                    if(cur >= X && cur <= Y)
                    {
                        //cout << i << ' ' << j << ' ' << cur << endl;
                        if(mp[cur] == 0) ans++;
                    }
                    curt = 0;
                    if(Y / (1ll<<j) < cur) break;
                }
                else
                {
                    cur = cur*(1ll << j);
                    if(j != 0 && cur >= X && cur <= Y)
                    {
                        //cout << i << ' ' << j << ' ' << cur << endl;
                        if(mp[cur] == 0) ans++;
                    }
                    curt = 1;
                    if(Y / (1ll<<i) < cur) break;
                }
                mp[cur]++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    cin >> X >> Y;
    Sub2();
}
