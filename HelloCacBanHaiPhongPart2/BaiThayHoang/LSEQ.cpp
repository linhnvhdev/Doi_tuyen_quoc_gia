#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
#define fi first
#define se second
#define INF 1e9
using namespace std;

int n,m,k = 0,a[maxn],b[maxn];
queue<pair<int,int> > q;
ll cur = 1,last,ans = 1;

void add(int i)
{
    k -= (b[i+1] - b[i] - 1);
    cur = b[i+1] - last + 1;
    q.push({b[i+1] - b[i] - 1,b[i+1]});
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LSEQ.inp","r",stdin);
    freopen("LSEQ.out","w",stdout);
    cin >> n;
    For(i,1,n){
        cin >> a[i];
        if(a[i] == 0) k++;
        else b[++m] = a[i];
    }
    if(m == 0){
        cout << k << endl;
        return 0;
    }
    sort(b+1,b+1+m);;
    last = b[1];
    ans = k+1;
    For(i,1,m-1){
        if(b[i+1] == b[i]) continue;
        if(b[i+1] == b[i] + 1)
            cur++;
        else if(k >= b[i+1] - b[i] - 1) add(i);
        else{
            bool ok = false;
            //cerr << b[i+1] << ' ' << b[i] << ' ' << k << ' ' << last << ' ' << cur << endl;
            while(!q.empty()){
                int d = q.front().fi;
                int newlast = q.front().se;
                q.pop();
                k += d;
                last = newlast;
                if(k >= b[i+1] - b[i] - 1){
                    add(i);
                    ok = true;
                    break;
                }
            }
            if(!ok){
                last = b[i+1];
                cur = 1;
            }
        }
        ans = max(ans,cur + k);
    }
    cout << ans << endl;
}
