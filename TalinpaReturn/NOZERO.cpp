#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

ll n,k;
ll ans = 0;
ll p[20],b[maxn];
int cs = 0,bg;

int t[20];

bool used[20];

bool Check(int cs)
{
    bool chk = false;
    while(cs > 0){
        int t = cs%10;
        if(t == 0) chk = true;
        cs /= 10;
    }
    return chk;
}

void Part2()
{
    For(i,1,cs){
        ll cur = ceil(1.0*k / p[cs-i]) - 1;
        if(i == cs-1){
            int t1 = 1e9,t2=-1;
            For(j,1,cs) if(!used[j]) t1 = min(t1,j),t2 = max(t2,j);
            if(k == 2) swap(t1,t2);
            b[i] = t1;
            b[i+1] = t2;
            break;
        }
        int pick;
        For(j,1,cs){
            if(used[j]) continue;
            if(t[j] == cur){
                pick = j;
                used[j] = true;
                break;
            }
        }
        b[i] = pick;
        For(j,pick+1,cs) t[j]--;
        k -= cur*(p[cs-i]);
    }
    if(n <= 500000){
        For(i,1,bg)
            if(Check(i)) ans++;
        For(i,1,cs)
            if(Check(bg+i) || Check(bg+b[i])) ans++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("NOZERO.inp","r",stdin);
    freopen("NOZERO.out","w",stdout);
    cin >> n >> k;
    if(k == 1){
        cout << n/10 << endl;
        return 0;
    }
    p[0] = 1;
    For(i,1,14){
        t[i] = i-1;
        p[i] = p[i-1]*i;
        if(p[i] > k){
            cs = i;
            break;
        }
    }
    bg = n - cs;
    Part2();
    cout <<n - ans << endl;
}
