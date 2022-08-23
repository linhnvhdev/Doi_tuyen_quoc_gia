/*
    2 xâu gọi là tương đương nếu mà khi ta rút gọn hết tất cả Aa aA...
    mà đc 2 xâu = nhau thì tương đương
    Tìm y sao cho chứa s và tương đương với x
    1) Tìm x' và s'
    2) Tìm đoạn con(liên tiếp) dài nhất của x' và s'
        (f[i][j]) = f[i-1][j-1] + 1 nếu x'[i] = s'[j]
                  = 0 nếu ko
            i = 1->x'.size
                j = 1-> s'.size
    3) Xây dựng xâu y:
        + cho S vào Y
        +
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 4005
#define ll long long
using namespace std;

string x,s,y="",x2="",s2="";

int f[maxn][maxn];

bool check(char a,char b)
{
    if(a == 'a' && b == 'A') return true;
    if(a == 'A' && b == 'a') return true;
    if(a == 'B' && b == 'b') return true;
    if(a == 'b' && b == 'B') return true;
    return false;
}

string Reduce(string S)
{
    string test = "";
    test += S[0];
    for(int i = 1;i < (int) S.size();i++){
        //cerr << S << ' ' << test << endl;
        if(test.size() > 0 && check(test[(int) test.size()-1],S[i])) {
            test.erase((int) test.size()-1,1);
            continue;
        }
        test += S[i];
    }
    return test;
    //cerr << test << endl;
}

char dao(char kt)
{
    if(kt == 'a') return 'A';
    if(kt == 'A') return 'a';
    if(kt == 'B') return 'b';
    if(kt == 'b') return 'B';
}

int main()
{
    freopen("SUBWORD.inp","r",stdin);
    freopen("SUBWORD.out","w",stdout);
    cin >> x >> s;
    x2 = Reduce(x);
    s2 = Reduce(s);
    //cerr << x2 << ' ' << s2 << endl;
    //x2.erase(x2.size()-1,1);
    //cerr << x2 << endl;
    int maxlength = 0,maxl = -1,maxr = -1,thuatrai = 0,thuaphai = 1;
    For(i,1,(int) x2.size())
        For(j,1,(int) s2.size()){
            if(x2[i-1] == s2[j-1]){
                f[i][j] = f[i-1][j-1] + 1;
                if(f[i][j] > maxlength){
                    maxlength = f[i][j];
                    maxl = i - maxlength;
                    maxr = i-1;
                    thuatrai = j - maxlength - 1;
                    thuaphai = j;
                }
            }
            else f[i][j] = 0;
        }
    //cerr << maxl << ' ' << maxr << ' ' << thuatrai << ' ' << thuaphai << endl;
    string y = s;
    For(i,0,thuatrai) y = dao(s2[i]) + y;
    //cerr << y << endl;
    Forr(i,(int) s2.size() - 1,thuaphai) y += dao(s2[i]);
    //cerr << y << endl;
    Forr(i,maxl-1,0) y = x2[i] + y;
    //cerr << y << endl;
    For(i,maxr+1,(int) x2.size()-1) y = y + x2[i];
    //cerr << y << endl;
    cout << y << endl;
}
