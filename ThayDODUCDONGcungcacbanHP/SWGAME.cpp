/*
    I dont care about you chẵn
    Sub cuối : QHĐ
    F[i][ok](ok: loại hay chưa) = f[i-2][ok] + abs(vt[i] - vt[j]);
                                = f[i-1][0] với ok = 1
    (1) bắt đầu từ 1
    (2) bắt đầu từ 2
    (3) bắt đầu từ 3
    xử lí hàm qhđ:
    ll DP(int i,int ok){
        if(F[i][ok] > -1) return F[i][ok];
        if(i == 1) return INF;
        if(i == 0) return 0;
        int test = DP(i-2,ok) + abs(v[i] - v[i-1])
        if(ok > 0) test = min(test,DP(i-1,0));
        F[i][ok] = test;
        return test;
    }
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
using namespace std;

int n;
ll L,R;
int a[maxn],vt[maxn],t[maxn],d = 0,cnt = 0;
ll f[maxn][2];

ll dis(int i,int j)
{
    if(i < j) return min(L*(j - i),R*(n + i - j));
    else return min(L*(n + j - i),R*(i - j));
}


ll Dis(int i,int j)
{
    return min(dis(i,j),dis(j,i));
}

ll Sub1()
{
    if(cnt <= 1) return 0;
    if(cnt == 2) return Dis(t[1],t[2]);
    if(cnt == 3) return min(Dis(t[1],t[2]),min(Dis(t[2],t[3]),Dis(t[1],t[3])));
}

ll dp(int i,int ok)
{
    if(f[i][ok] > -1) return f[i][ok];
    if(i == 1) return 1e18;
    if(i == 0) return 0;
    ll tmp = dp(i-2,ok) + Dis(t[i],t[i-1]);
    if(ok == 1) tmp = min(tmp,dp(i-1,0));
    f[i][ok] = tmp;
    return tmp;
}

int main()
{
    freopen("SWGAME.inp","r",stdin);
    freopen("SWGAME.out","w",stdout);
    scanf("%d%d%d",&n,&L,&R);
    For(i,1,n) scanf("%lld",&a[i]);
    For(i,1,n) if(a[i] % 2 == 1) vt[++cnt] = i;
    if(cnt == 1){
        cout << 0 << endl;
        return 0;
    }
    For(i,1,cnt) t[i] = vt[i];
    if(n == 3){
        printf("%lld\n",Sub1());
        return 0;
    }
    ll ans = 1e18;
    if(cnt % 2 == 0){
        ll test = 0;
        for(int i = 1;i <= cnt;i += 2)
            test += Dis(t[i],t[i+1]);
        ans = min(ans,test);
        test = 0;
        for(int i = 2;i <= cnt; i += 2)
            test += Dis(t[i],t[(i % cnt) + 1]);
        ans = min(ans,test);
    }
    else{
        memset(f,-1,sizeof(f));
        For(i,1,cnt) t[i] = vt[i];
        //cerr << dp(cnt,1) <<endl;
        ans = min(ans,dp(cnt,1));

        t[1] = vt[cnt];
        For(i,1,cnt-1) t[i+1] = vt[i];
        memset(f,-1,sizeof(f));
        //cerr << dp(cnt,1) <<endl;
        ans = min(ans,dp(cnt,1));

        memset(f,-1,sizeof(f));
        t[1] = vt[cnt-1];
        t[2] = vt[cnt];
        For(i,1,cnt - 2) t[i+2] = vt[i];
        //cerr << dp(cnt,1) <<endl;
        ans = min(ans,dp(cnt,1));
    }
    cout << ans << endl;
}
