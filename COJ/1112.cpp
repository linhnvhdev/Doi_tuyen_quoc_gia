#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
#define x first.first
#define h first.second
#define id second
using namespace std;

pair<pair<int,int>,int> p[maxn];
int n,d[maxn];

int main()
{
    scanf("%d",&n);
    For(i,1,n){
        scanf("%d%d",&p[i].x,&p[i].h);
        p[i].id = i;
    }
    sort(p+1,p+1+n);
    stack<int> stk;
    d[p[n].id] = 1;
    stk.push(n);
    //For(i,1,n) cout << p[i].id << ' ' << p[i].x << ' ' << p[i].h << endl;
    Forr(i,n-1,1){
        d[p[i].id] = 1;
        while(!stk.empty() && p[i].x + p[i].h > p[stk.top()].x){
            d[p[i].id] += d[p[stk.top()].id];
            stk.pop();
        }
        stk.push(i);
    }
    For(i,1,n-1) printf("%d ",d[i]);
    printf("%d",d[n]);
}
