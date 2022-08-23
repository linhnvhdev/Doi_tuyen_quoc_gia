#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define fi first
#define se second
#define maxn 100005
using namespace std;

int n,a[maxn];

int main()
{
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int turn = 0;
    int i = n,j = 1;
    for(int k = 1;k <= n-1;k++){
        if(turn == 0) i--;
        else j++;
        turn = (turn+1)%2;
        //cout << i << ' ' << j << endl;
    }
    //cout << i << ' ' <<j << ' ';
    cout << a[i] << endl;
}
/*
15
1 8 2 7 6 3 5 6 4 3 2 1 10 6 9
*/
