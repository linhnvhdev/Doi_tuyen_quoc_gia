/**
    Fk[i] : chỉ số của kí tự trong xâu S sinh ra kí tự ở vị trí i của xâu Fk
    F1[i] = m2 + i; (i = 0,...,m1-1)    }
    F2[i] = i; (i = 0,...,m2-1)         } -> Vector
    Fk[i] = F(k-1) ++ F(k-2) (Nối mảng) }
    Tính cnt[i][j] số lượng kí tự 'A' + j trong xâu S ở vị trí i sinh ra
**/


#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long
#define INF 1e18
#define Bit(x,i) ((x >> i)&1)
using namespace std;

int m,m1,m2,r;

string S;

void change(string &s1,string &s2,string &t)
{
    while(true)
    {
        t = s2 + s1;
        if(t.size() >= m) return;
        swap(t,s2);
        swap(t,s1);
    }
}

void Sub1()
{
    string s2 = S.substr(0,m2);
    string s1 = S.substr(m2,m1);
    //cout << s1 << ' ' << s2 << endl;
    string t;
    change(s1,s2,t);
    int loi = 0;
    For(j,0,m-1)
        loi += (t[j] != S[j]);
    //cout << S << endl << t << endl;
    cout << loi << '\n';
}

void Sub12()
{
    string s1,s2,t,P;
    int ans = m;
    r = min(r,10);
    for(int i = 0;i < (1<<r);i++)
    {
        P = S;
        For(j,0,min(r-1,m1+m2-1))
            P[j] = char('A' + Bit(i,j));
        s2 = P.substr(0,m2);
        s1 = P.substr(m2,m1);
        change(s1,s2,t);
        int loi = 0;
        For(j,0,m-1)
            loi += (t[j] != P[j]);
        //cout << t << ' ' << P << endl;
        if(ans > loi) ans = loi;
    }
    cout << ans << '\n';
}

int cnt[maxn][27];

int best[maxn];

vector<int> f[maxn];

int sl[maxn];

bool cmp(int x,int y)
{
    return x > y;
}

void Sub3()
{
    For(i,0,m1-1) f[1].push_back(m2+i);
    For(i,0,m2-1) f[2].push_back(i);
    int k = 2;
    while(f[k].size() <= S.size())
    {
        k++;
        for(int v : f[k-1]) f[k].push_back(v);
        for(int v : f[k-2]) f[k].push_back(v);
    }
    //For(i,0,S.size()-1) cout << i << ' ' << f[k][i] << endl;
    For(i,m1+m2,(int) S.size()-1)
    {
        cnt[f[k][i]][S[i] - 'A']++;
        sl[f[k][i]]++;
    }
    For(i,0,m1+m2-1) best[i] = 0;
    int ans = 0;
    For(i,0,m1+m2-1)
    {
        int cur = sl[i] - cnt[i][S[i] - 'A'];
        ans += cur;
        For(j,0,25)
        {
            int change = sl[i] - cnt[i][j];
            best[i] = max(best[i],cur - change);
        }
    }
    sort(best,best+m1+m2,cmp);
    For(i,0,r-1) ans -= best[i];
    cout << ans << endl;
}

int main()
{
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
    cin >> m >> m1 >> m2 >> r >> S;
//    if(m <= 1000 && r == 0) Sub1();
//    else if(r <= 10 && r == m1 + m2) Sub12();
//    else
        Sub3();
}
