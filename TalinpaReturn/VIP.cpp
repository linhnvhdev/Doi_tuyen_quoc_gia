#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define ll long long
#define fi first
#define se second
using namespace std;

int q;
int n,k;
string s,t;
int kt[27],kt2[27];

int d[100005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("VIP.inp","r",stdin);
    freopen("VIP.out","w",stdout);
    cin >> q;
    while(q--){
        cin >> n >> k >> s >> t;
        memset(kt,0,sizeof(kt));
        memset(kt2,0,sizeof(kt2));
        memset(d,0,sizeof(d));
        For(i,0,n-1){
            kt[s[i] - 'a']++;
            kt2[t[i] - 'a']++;
        }
        int K = n - k;
        int cnt = 0;
        string ans ="";
        For(i,0,n-1){
            int x = s[i] - 'a';
            if(K == 0) break;
            else{
                if(kt2[x] > 0){
                    K--;
                    kt2[x]--;
                    d[i] = x+1;
                }
            }
        }
        if(K > 0) cout << -1 << '\n';
        else{
            while(ans.size() < s.size()){
                int m = ans.size();
                if(d[m] != 0){
                    ans += char(d[m] - 1 + 'a');
                    continue;
                }
                bool ok = false;
                For(j,0,26){
                    if(j != s[m] - 'a' && kt2[j] > 0){
                        kt2[j]--;
                        ans += char(j + 'a');
                        ok = true;
                        break;
                    }
                }
                if(!ok){
                    cout << -1 << '\n';
                    break;
                }
            }
            cout << ans << '\n';
        }
    }
}
