#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define Bit(x,i) ((x>>i)&1)
using namespace std;

int T;
string x,y;

int main()
{
    scanf("%d",&T);
    while(T--){
        cin >> x >> y;
        int n = x.size(), m = y.size(),vt = -1;
        Forr(i,m-1,0)
            if(y[i] == '1'){
                vt = m - i;
                break;
            }
        //cout << "# " << vt << endl;
        if(vt == -1){
            cout << 0 << endl;
            continue;
        }
        int test = 0;
        Forr(i,n - vt,0){
            if(x[i] == '1'){
                test = n - vt - i;
                break;
            }
        }
        cout << test << endl;
    }
}
