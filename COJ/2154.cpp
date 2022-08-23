#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
using namespace std;

char s[maxn];
int a[maxn],n,ok = -1;

void change(int i)
{
    int nho = 0;
    a[i]++;
    nho = a[i] / 10;
    a[i] %= 10;

    //cout << a[i] << endl;
    int t = (a[i] == 0) ? 1 : 0;
    For(j,i+1,n){
        if(j == i + 1 && a[i] == 0 && a[i-1] == 9) j--;
        a[j] = t;
        t = (t+1)%2;
    }
    Forr(j,i-1,0){
        if(nho == 0) return;
        a[j] += nho;
        nho = a[j] / 10;
        a[j] %= 10;
    }
    return;
}

void Print()
{
    if(a[0] != 0) printf("%d",a[0]);
    For(i,1,n) printf("%d",a[i]);
    return;
}

int check()
{
    For(i,2,n)
        if(a[i] == a[i-1]) return i;
    return -1;
}

bool checktest20()
{
    int gg[2] = {9,8},j = 0;
    For(i,1,n){
        if(a[i] != gg[j]) return false;
        j = 1 - j;
    }
    return true;
}

int main()
{
    scanf("%s",&s);
    n = strlen(s);
    for(int i = 0;i < n;i++) a[i+1] = s[i]-'0';
    a[0] = 0;
    if(checktest20()){
        change(1);
        Print();
        return 0;
    }
    int t = check();
    if(t == -1){
        change(n);
        t = check();
    }
    while(t != -1){
        change(t);
        t = check();
    }
    Print();
    return 0;
}
