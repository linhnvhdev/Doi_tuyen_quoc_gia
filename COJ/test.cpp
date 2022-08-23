#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 400005
#define ll long long
using namespace std;

int n,H,S,D,a[maxn],b[maxn];

int main()
{
    scanf("%d%d%d%d",&n,&H,&S,&D);
    For(i,1,n) scanf("%d",&a[i]);
    int T = (H + D) / S + 1;
    deque<int> dq;
    Forr(i,n,1){
        while(!dq.empty() && i - dq.front() >= T) dq.pop_front();
        while(!dq.empty() && a[dq.back()] >= a[i]) dq.pop_back();
        dq.push_back(i);
        b[i] = a[dq.front()];
    }
    ll ans = H*a[1];
    int cur = a[1];
    cout << ans << endl;
    For(i,2,n){
        ans += cur * S;
        if(b[i] >= cur){
            ans += 1ll*H*(b[i] - cur);
            cur = b[i];
        }
        else{
            ans += 1ll*D*(cur - b[i]);
            cur = b[i];
        }
        cout << i << ' ' << cur << ' ' << ans << endl;
    }
    ans += 1ll*S*cur + 1ll*D*cur;
    cout << ans <<endl;
}
/*
3
4 5 6
10 9 11
*/
