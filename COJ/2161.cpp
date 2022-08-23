/*
    Thuật Manacher
    Gọi d1[i] , d2[i] là số xâu con đối xứng có độ dài lẻ, chẵn với tâm ở i
    Lưu ý tâm của xâu s[l...r] là (l+r+1)/2;
    Tất cả các xâu con đx độ dài lẻ có tâm ở i là
    s[i-k...i+k]
    với k = 0,1,.... d1[i]-1
    Tất cả các xâu con đx độ dài lẻ có tâm ở i là
    s[i-k...i+k-1]
    với k = 0,1,.... d2[i]-1
    Đáp số của bài toán là Xíchma(0->n-1)[d1[i] + d2[i]] ở đó n - s.size()
    **** Tính d1[i]
    Gọi (l,r) là đoạn đối xứng bên phải nhất hiện tại
    Ban đầu l = 0, r = -1;
    Tính d1[i]
    TH1: i > r : Tính d1[i] như bth
*/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
using namespace std;

int n;
string s;
int d1[maxn],d2[maxn];

int main()
{
    cin >> s;
    n = s.size();
    //tinh d1
    for(int i = 0,l = 0,r = -1;i < n;i++){
        int k = (i > r) ? 1 : min(d1[l+r-i],r-i+1);
        while(0 <= i - k && i + k < n && s[i-k] == s[i+k]) k++;
        d1[i] = k--;
        if(i + k > r){
            r = i + k;
            l = i - k;
        }
    }
    // tinh d2
    for(int i = 0,l = 0,r = -1;i < n;i++){
        int k = (i > r) ? 0 : min(d2[l+r-i+1],r-i+1);
        //if(i == 3) cout << l << ' ' << r << ' ' << k << endl;
        while(0 <= i-k-1 && i+k < n && s[i-k-1] == s[i+k]){
            //cout << " $#@ " << ' ' << i << ' ' << i - k - 1 << ' ' << i + k << endl;
            k++;
        }
        d2[i] = k--;
        if(i + k > r){
            r = i + k;
            l = i - k -1;
        }
    }
    ll ans = 0;
    //For(i,0,n-1) cout << d1[i] << ' ' << d2[i] <<endl;
    For(i,0,n-1) ans += d1[i] + d2[i];
    printf("%lld\n",ans);
}


/*
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
using namespace std;

const int base = 128;
const int mod = 1e9+7;
int n;
char s[maxn];
ll h1[maxn],h2[maxn],p[maxn];

ll get_hash(ll h[maxn],int i,int j)
{
    return ((h[j] - h[i-1]*p[j-i+1])%mod +mod)%mod;
}

int main()
{
    scanf("%s",&s);
    int n = strlen(s);
    p[0] = 1;
    For(i,1,n){
        h1[i] = (h1[i-1]*base + s[i-1])%mod;
        p[i] = (p[i-1]*base)%mod;
    }
    For(i,1,n) h2[i] = (h2[i-1]*base + s[n-i])%mod;
    int ans = n;
    For(i,1,n)
        For(j,i+1,n)
            if(get_hash(h1,i,j) == get_hash(h2,n-j+1,n-i+1)){
                ans++;
            }
    cout << ans << endl;
}
*/
