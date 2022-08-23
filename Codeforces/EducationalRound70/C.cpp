#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define Bit(x,i) ((x>>i)&1)
using namespace std;

char s[maxn];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",&s);
        int n = strlen(s);
        int maxa = 0,maxd = 0,maxw = 0,maxs = 0,curad = 0,curws = 0;
        int da = 0,dd = 0,ds = 0,dw = 0;
        For(i,0,n-1){
            if(s[i] == 'A') {curad--; da++;}
            if(s[i] == 'D') {curad++; dd++;}
            if(s[i] == 'W') {curws--; dw++;}
            if(s[i] == 'S') {curws++; ds++;}
            if(curad >= 0) maxd = max(maxd,curad);
            if(curad < 0) maxa = max(maxa,-curad);
            if(curws >= 0) maxs = max(maxs,curws);
            if(curws < 0) maxw = max(maxw,-curws);
        }
        int ans = (maxd + maxa + 1)*(maxs + maxw + 1);
        if(da > 1 || dd > 1) ans = min(ans,(maxd + maxa)*(maxs + maxw + 1));
        if(dw > 1 || ds > 1) ans = min(ans,(maxd + maxa + 1)*(maxs + maxw));
        cout << ans << endl;
    }
}
