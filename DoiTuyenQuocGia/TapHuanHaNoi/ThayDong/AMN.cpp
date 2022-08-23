#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 505
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

int m,n,u,v;

vector<pair<int,pii> > a[maxn],b[maxn];
vector<int> c[maxn];

bool cmp(vector<pair<int,pii> > x,vector<pair<int,pii> > y)
{
    int i = x[0].se.fi;
    int i2 = y[0].se.fi;
    return b[i][0] > b[i2][0];
}

bool lonhon(pair<int,pii> x,pair<int,pii> y)
{
    return x.fi > y.fi;
}

bool CMP(vector<int> x,vector<int> y)
{
    return x[0] > y[0];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("AMN.inp","r",stdin);
    freopen("AMN.out","w",stdout);
    cin >> m >> n >> u >> v;
    For(i,1,m)
        For(j,1,n)
        {
            int x;
            cin >> x;
            a[i].push_back({x,{i,j}});
            b[i].push_back({x,{i,j}});
        }
    For(i,1,m)
        sort(b[i].begin(),b[i].end(),lonhon);
    sort(a+1,a+1+m,cmp);
    sort(a[1].begin(),a[1].end(),lonhon);
    For(i,1,n) c[1].push_back(a[1][i-1].fi);
    For(i,2,m)
    {
        For(j,0,n-1)
        {
            int curj = a[1][j].se.se;
            c[i].push_back(a[i][curj-1].fi);
        }
    }
    sort(c+2,c+1+m,CMP);
    cout << c[u][v-1] << endl;
}
