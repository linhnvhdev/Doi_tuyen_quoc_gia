#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define Forr(i,a,b) for(int i = a;i >= b; i--)
#define Forv(i,a) for(int i = 0;i < a.size();i++)
#define maxn 100005
#define ll long long
#define plli pair<long long, int>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

void SolveX(vector<int> id);
void SolveY(vector<int> id,int xl,int xr);
void SolveZ(vector<int> id,int xl,int xr,int yl,int yr);

struct cube
{
    int xa,ya,za,xb,yb,zb;
} ans[maxn];

int a,b,c,m;
int x[maxn],y[maxn],z[maxn];

void SolveX(vector<int> id)// mảng chứa chỉ số của khối lập phương socola
{
    map<int,vector<int> > X;
    Forv(i,id)
        X[x[id[i]]].push_back(id[i]);
    for(auto it = X.begin(); it != X.end();it++)
    {
        int xl,xr;
        if(it == X.begin())
            xl = 1;
        else
        {
            auto it_prev = it;
            it_prev--;
            xl = (it_prev -> fi) + 1;
        }
        if(it == --X.end())
            xr = a;
        else
        {
            xr = it->fi;
        }
        SolveY(it->se,xl,xr);
    }
}

void SolveY(vector<int> id,int xl,int xr)// mảng chứa chỉ số của khối lập phương socola
{
    map<int,vector<int> > Y;
    Forv(i,id)
        Y[y[id[i]]].push_back(id[i]);
    for(auto it = Y.begin(); it != Y.end();it++)
    {
        int yl,yr;
        if(it == Y.begin())
            yl = 1;
        else
        {
            auto it_prev = it;
            it_prev--;
            yl = (it_prev -> fi) + 1;
        }
        if(it == --Y.end())
            yr = b;
        else
        {
            yr = it->fi;
        }
        SolveZ(it->se,xl,xr,yl,yr);
    }
}

void SolveZ(vector<int> id,int xl,int xr,int yl,int yr)// mảng chứa chỉ số của khối lập phương socola
{
    map<int,int> Z;
    Forv(i,id)
        Z[z[id[i]]] = id[i];
    for(auto it = Z.begin(); it != Z.end();it++)
    {
        int zl,zr;
        if(it == Z.begin())
            zl = 1;
        else
        {
            auto it_prev = it;
            it_prev--;
            zl = (it_prev -> fi) + 1;
        }
        if(it == --Z.end())
            zr = c;
        else
        {
            zr = it->fi;
        }
        ans[it->se] = {xl,yl,zl,xr,yr,zr};
    }
}

int main()
{
    while(cin >> a)
    {
        if(a == -1) return 0;
        scanf("%d%d%d",&b,&c,&m);
        //cout << a << ' ' << b << ' ' << c << ' ' << m << " ::\n";
        For(i,1,m) scanf("%d%d%d",&x[i],&y[i],&z[i]);
        vector<int> id;
        For(i,1,m) id.push_back(i);
        SolveX(id);
        printf("YES\n");
        For(i,1,m) printf("%d %d %d %d %d %d\n",ans[i].xa,ans[i].ya,ans[i].za,ans[i].xb,ans[i].yb,ans[i].zb);
    }
}
