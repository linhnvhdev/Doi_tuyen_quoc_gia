#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 7005
using namespace std;

int n;

pair<ll,int> a[maxn];
bool ok[maxn];

int main()
{
    cin >> n;
    For(i,1,n) cin >> a[i].first;
    For(i,1,n) cin >> a[i].second;
    sort(a+1,a+1+n);
    ll ans = 0;
    a[0] = {-1,0};
    a[n+1] = a[n];
    Forr(i,n,1){
        //cout << i << ' ' << a[i].first << ' ' << ans << endl;
        int j = i-1;
        while(a[j].first == a[i].first){
            ans += a[j].second;
            ok[j] = ok[i] = true;
            j--;
        }
        if(i != j+1){
            ans += a[i].second;
            i = j + 1;
        }
        else
            For(k,i+1,n){
                if(ok[k] && ((a[k].first ^ a[i].first) == (a[k].first - a[i].first))){
                    ok[i] = true;
                    ans += a[i].second;
                    break;
                }
            }
    }
    cout << ans <<endl;
}
