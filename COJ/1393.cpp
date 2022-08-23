#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 105
#define Bit(x,i) ((x >> i) & 1)
#define fi first
#define se second
using namespace std;

int n,a[maxn][maxn];
bool ok = true;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool used[maxn][maxn];

void dfs(int i,int j,int cur_min,int cur_max)
{
    used[i][j] = true;
    For(k,0,3){
        int ii = i + dx[k],jj = j + dy[k];
        if(ii <= 0 || ii > n || jj <= 0 || jj > n || used[ii][jj]) continue;
        if(a[ii][jj] >= cur_min && a[ii][jj] <= cur_max)
            dfs(ii,jj,cur_min,cur_max);
    }
}

bool check(int mina,int maxa)
{
    memset(used,false,sizeof(used));
    if(a[1][1] < mina || a[1][1] > maxa) return false;
    dfs(1,1,mina,maxa);
    return used[n][n];
}

int main()
{
    scanf("%d",&n);
    For(i,1,n)
        For(j,1,n) scanf("%d",&a[i][j]);
    int ans = 1e9;
    For(i,0,a[1][1]){
        int l = 0, r = 200;
        while(r - l > 1){
            int mid = (l + r)/2;
            //cout << mid << ' ' << check(i,i + mid) << endl;
            if(check(i,i + mid))
                r = mid;
            else l = mid;
        }
        if(check(i,i + l)) ans = min(ans,l);
        else if(check(i,i+r)) ans = min(ans,r);
    }
    cout << ans << endl;
}
