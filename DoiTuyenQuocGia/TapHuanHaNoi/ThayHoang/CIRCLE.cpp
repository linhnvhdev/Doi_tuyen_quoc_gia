#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define fi first
#define se second
#define maxn 1000005
using namespace std;

int n;
int nhan[maxn],in[maxn],out[maxn],low[maxn],cnt[maxn],scc = 0;
int a[maxn],dem = 0,head[maxn],tail[maxn];
int cc = 0,d = 0,cur_h = 0;
pair<int,int> ans[maxn];

bool used[maxn];

void dfs1(int u)
{
    used[u] = true;
    int v = a[u];
    if(!used[v])
        dfs1(v);
    else tail[dem] = u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CIRCLE.inp","r",stdin);
    freopen("CIRCLE.out","w",stdout);
    cin >> n;
    For(i,1,n)
    {
        cin >> a[i];
        out[i]++;
        in[a[i]]++;
    }
    For(i,1,n)
        if(in[i] == 0)
        {
            dem++;
            head[dem] = i;
            dfs1(i);
        }
    For(i,1,n)
        if(!used[i])
        {
            dem++;
            head[dem] = i;
            dfs1(i);
        }
    cur_h = 1;
    head[dem+1] = head[1];
    tail[dem+1] = tail[1];
    cout << dem << endl;
    For(i,1,dem)
        cout << tail[i] << ' ' << head[i+1] << '\n';
}
