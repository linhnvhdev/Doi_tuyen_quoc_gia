#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 400010
using namespace std;

int H,S,D,n,a[maxn];
int b[maxn],worker[maxn];

int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    scanf("%d%d%d%d",&n,&H,&S,&D);
    int T = (H+D)/S + 1;
    For(i,1,n) scanf("%d",&a[i]);
    deque<int> dq;
    a[n+1] = a[n];
    Forr(i,n+1,1){
        while(!dq.empty() && dq.front() - i >= T)dq.pop_front();
        while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        b[i] = a[dq.front()];
    }
    //For(i,1,n) cerr << i << " ** " << b[i] << endl;
    ll ans = 0,cur = 0;
    For(i,1,n){
        ans += cur*S;
        //cerr << "## " << i << ' ' << a[i]<< ' ' << b[i] << endl;
        //cerr << "truoc " << ans << ' ' << cur <<  endl;
        if(a[i] >= cur){
            ans += 1ll*H*(a[i] - cur);
            cur = a[i];
        }
        else if(b[i] < cur){
            ans += 1ll*D*(cur - b[i]);
            cur = b[i];
        }
        //cerr << "sau " << ans << ' ' << cur << endl;
        worker[i] = cur;
    }
    ans += 1ll*cur*(S + D);
    cout << ans << endl;
    For(i,1,n-1) printf("%d ",worker[i]);
    printf("%d\n",worker[n]);
}
