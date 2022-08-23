/*
Subtask3:///::: nghĩa là chia hết
    TH1 : đếm các xâu đx độ dài lẻ và tạo thành 1 số ::: 3
   d1[i]: số các xâu con đối xứng độ dài lẻ tâm i
   Đếm số xâu con đối xứng độ dài lẻ tâm i ::: 3
    các xâu có thể s[i-k]...s[i-k]
    s[i-k]...s[i+k] <=> s[i-k] + s[i - k + 1] + ... + s[i + k] ::: 3
                    <=> s[i] + 2(s[i+1]+...+s[i+k]) ::: 3
    <=> s[i] đồng dư (s[i + 1] + ... + s[i + k]) (mod 3)
    Tóm lại: có bao nhiêu số k t/m: 0 <= k <= d1[i] - 1
    t/m s[i] đồng dư (d[i+1] + ... + s[i+k]) (mod 3)
    <=> sum[i] + s[i] đồng dư với sum[i] + s[i + 1] + ... + s[i+k] = sum[i + k]
    c[i][j] : số các tổng tiền tố sum[p](p <= i) (mod 3) mà = j
    => số gt t/m: c[i+k][sum[i] + s[i]] - c[i][sum[i] + s[i]];
    Chẵn tương tự
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 1000005
#define ll long long
using namespace std;

string s;
int d1[maxn],n,d2[maxn];
ll sum[maxn];
ll c[maxn][3];
ll ans = 0;

void manacher()
{
    for(int i = 0,l = 0,r = -1;i < n;i ++){
        int k = (i > r) ? 1 : min(d1[l + r - i],r - i + 1);
        while(i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
        d1[i] = k--;
        if(i + k > r){
            l = i - k;
            r = i + k;
        }
    }
    for(int i = 0,l = 0,r = -1;i < n;i ++){
        int k = (i > r) ? 0 : min(d2[l + r - i + 1],r - i + 1);
        while(i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k]) k++;
        d2[i] = k--;
        if(i + k > r){
            l = i - k - 1;
            r = i + k;
        }
    }
}

int main()
{
    cin >> s;
    n = s.size();
    For(i,1,n){
        sum[i] = (sum[i-1] + (s[i-1] - '0')%3)%3;
        For(j,0,2) c[i][j] = c[i-1][j];
        if(s[i-1] != '0') c[i][sum[i]]++;
    }
    manacher();
    ll ans = 0;
    For(i,0,n-1){
        if((s[i] - '0') % 3 == 0) ans++;
        int k = (sum[i+1] + (s[i] - '0')%3) % 3;
        ans += c[i + d1[i]][k] - c[i + 1][k];
        if(d2[i] > 0) ans += c[i + d2[i]][sum[i]] - c[i][sum[i]];
    }
    cout << ans << endl;
}
