#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
using namespace std;

string s;
int n;
int a[maxn],cnt = 0;

void check()
{
    int cur = a[cnt-1],D = a[cnt];
    int d = a[cnt]/a[cnt-1];
    if(d <= 1) return;
    cnt--;
    For(i,1,d-1) a[++cnt] = cur;
    a[++cnt] = D - cur*(d-1);
}

void Tham()
{
    if(a[cnt] - a[cnt-1] <= 1){
        a[cnt-1] = a[cnt] + a[cnt-1];
        cnt--;
     }
    else if(a[cnt] - a[cnt-1] > 1){
        a[cnt-1]++;
        a[cnt]--;
        check();
    }
    cout << n << "=";
    For(i,1,cnt-1) printf("%d+",a[i]);
    printf("%d\n",a[cnt]);
}

int main()
{
    cin >> s;
    for(int i = 0,bang = 0;i < s.size();i++){
        if(s[i] - '0' >= 0 && s[i] - '0' <= 9){
            if(bang == 0) n = n * 10 + (s[i] - '0');
            else a[cnt] = a[cnt]*10 + (s[i] - '0');
        }
        else{
            cnt++;
            if(s[i] == '=') bang = 1;
        }
    }
    if(cnt == 1){
        cout << "No solution";
        return 0;
    }
    Tham();
}
/*
7=1+1+1+1+1+1+1
7=1+1+1+1+1+2
7=1+1+1+1+3
7=1+1+1+2+2
7=1+1+1+4
7=1+1+2+3
7=1+1+5
7=1+2+2+2
7=1+2+4
7=1+3+3
7=1+6
7=2+2+3
7=2+5
7=3+4
7=7
*/
