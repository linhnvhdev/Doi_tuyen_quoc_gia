/**
    if(u là gốc)
        tạo đỉnh 1 nối với size tk mới
    else
        tạo sz[u] - 1 đỉnh mới nối lên 1 nút ở cha
**/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,t,m,d,cd = 0;
int cntd[maxn];
vector<int> a[maxn];

bool used[maxn];

vector<pair<int,int> > edge;

int nhan[maxn];

void dfs(int u)
{
    //cerr << u << ' ' << d << endl;
    vector<int> nxt;
    int cur = nhan[u];
    for(int v : a[u]){
        if(used[v]) continue;
        edge.push_back({nhan[u],cur+1});
        cur++;
        nhan[v] = cur;
        d = max(d,cur);
        nxt.push_back(v);
        used[v] = true;
    }
    for(int v : nxt) dfs(v);
}

void reset()
{
    d = 0;
    memset(cntd,0,sizeof(cntd));
    memset(used,false,sizeof(used));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LINEGRAPH.inp","r",stdin);
    freopen("LINEGRAPH.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n >> m;
        reset();
        For(i,1,m){
            int u,v;
            //cerr << i << ' ' << u << ' ' << v << endl;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
            cntd[u]++;
            cntd[v]++;
        }
        if(m < n - 1){
            cout <<"NO\n";
            continue;
        }
        //For(i,1,n) cerr << i << ' ' << cntd[i] << endl;
        cout << "YES\n";
        if(m == n*(n-1)/2){
            cout << n + 1 << '\n';
            For(i,1,n) cout << 1 << ' ' << i+1 << '\n';
            continue;
        }
        else if(m == n-1){
            cout << n + 1 <<  '\n';
            For(i,1,n) cout << i << ' ' << i+1 << '\n';
            continue;
        }
        For(i,1,n){
            if(cntd[i] == 1){
                d = 3;
                edge.push_back({1,2});
                edge.push_back({1,3});
                used[i] = true;
                nhan[a[i][0]] = 3;
                used[a[i][0]] = true;
                dfs(a[i][0]);
                break;
            }
        }
        cout << d << endl;
        for(pair<int,int> kq : edge) cout << kq.fi << ' ' << kq.se << endl;
    }
}
