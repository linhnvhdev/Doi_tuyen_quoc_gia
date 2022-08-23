#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 2000005
#define Bit(x,i) ((x>>i)&1)
using namespace std;

string s;
int a[11][11][11],n;

int Counter(int i,int j)
{
    int cur = 0,ans = 0;
    //cout << "######## "<<i << ' ' << j <<endl;
    for(int k = 1;k < n; k++){
        //cout << ":))";
        int x = s[k] - '0';
        //cout << n << ' ' << k << ' ' << x << endl;
        ans += a[i][j][(x - cur + 10) % 10] - 1;
        //cout << "* " << (x - cur + 10)%10 << ' ' <<a[i][j][(x - cur + 10) % 10] << endl;
        if(a[i][j][(x - cur + 10) % 10] == 1000) return -1;
        cur = x;
    }
    return ans;
}

int main()
{
    cin >> s;
    n = s.size();
    For(i,0,9)
        For(j,0,9)
            For(k,0,9) a[i][j][k] = 1000;
    For(i,0,9)
        For(j,0,9)
            For(stepi,0,9)
                For(stepj,0,9){
                    if(stepi + stepj == 0) continue;
                    a[i][j][(i*stepi + j*stepj)%10] = min(a[i][j][(i*stepi + j*stepj)%10],stepi + stepj);
                }
    /*For(i,0,9)
        For(j,0,9){
            cout << " ############## " << i << ' ' << j << endl;
            For(k,0,9) cout << k << ' ' << a[i][j][k] << endl;
        }*/
    For(i,0,9){
        For(j,0,9){
            printf("%d ",Counter(i,j));
            //cout << i << ' ' << j << ' ' << counter(i,j) << endl;
        }
        printf("\n");
    }
}
