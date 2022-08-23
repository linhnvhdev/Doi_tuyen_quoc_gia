/*
    f[i] = min(f[i-c+1]...f[i-1]) + y[i]
    => deque
*/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
using namespace std;

int n,q,dq[maxn];
string y;
int a[maxn],f[maxn];

int main()
{
    //freopen("tmachine.inp","r",stdin);
    //freopen("tmachine.out","w",stdout);
    scanf("%d%d",&n,&q);
    cin >> y;
    for(int i = 0;i < y.size();i++) a[i+1] = y[i] - '0';
    while(q--){
        memset(f,0,sizeof(f));
        memset(dq,0,sizeof(f));
        int s,t,c;
        scanf("%d%d%d",&s,&t,&c);
        if(s > t) swap(s,t);
        f[s] = a[s];
        int fr = 1,bk = 1;
        dq[bk] = s;
        For(i,s+1,t){
            //cerr << q << " ** " << i << ' ' << a[i] << ' ' << dq[fr] << ' ' << dq[bk] << endl;
            f[i] = f[dq[fr]] + a[i];
            while(fr <= bk && i - dq[fr] >= c) fr++;
            while(fr <= bk && f[i] <= f[dq[bk]]) bk--;
            dq[++bk] = i;
        }
        /*For(i,s+1,t){
            cerr << q << " ** " << i << ' ' << a[i] << ' ' << dq.front() << endl;
            f[i] = f[dq.front()] + a[i];
            while(!dq.empty() && i - dq.front() >= c) dq.pop_front();
            while(!dq.empty() && f[i] <= f[dq.back()]) dq.pop_back();
            dq.push_back(i);
        }*/
        printf("%d\n",f[t]);
    }
}
