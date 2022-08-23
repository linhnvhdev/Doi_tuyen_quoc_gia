/*
    int d[10^5] : gía min để có đc xâu con s[0...i]
    set<pair<int,int> >// pair: chi phí và chỉ số xâu
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define pii pair<ll,int>
#define fi first
#define se second
using namespace std;

int n,z[maxn];
ll a,b,c,ans = 0;
string s;
set<pii> q;
ll d[maxn];

void FindZ()
{
    z[0] = n;
    for(int i = 1,l = 0,r = 0;i < n;i++){
        if(i > r){
            l = r = i;
            while(r < n && s[r - l] == s[r]) r++;
            r--;
            z[i] = r - l + 1;
        }
        else{
            if(z[i-l] < r - i + 1) z[i] = z[i-l];
            else{
                l = i;
                while(r < n && s[r - l] == s[r]) r++;
                r--;
                z[i] = r - l + 1;
            }
        }
    }
    //For(i,1,n) cout << " # " << i << " : " << z[i] << endl;
}

int main()
{
    cin >> n >> s >> a >> b >> c;
    FindZ();
    d[0] = a;
    q.insert({a,0});
    For(i,1,n) d[i] = 1e18;
    while(!q.empty()){
        int i = (*q.begin()).second;
        q.erase(q.begin());
        //cout << i << endl;
        if(i + 1 < n){
            int j = i + 1;
            if(d[j] > d[i] + a){
                q.erase({d[j],j}); // xóa cái cũ ít tối ưu hơn
                d[j] = d[i] + a;
                q.insert({d[j],j});
            }
        }
        //xóa kt cuối
        if(i - 1 >= 0){
            int j = i - 1;
            if(d[j] > d[i] + c){
                q.erase({d[j],j});
                d[j] = d[i] + c;
                q.insert({d[j],j});
            }
        }
        // gấp đôi
        int k = min(z[i + 1],i+1);
        if(d[i + k] > d[i] + b + c*(i + 1 - k)){
            q.erase({d[i+k],i+k});
            d[i + k] = d[i] + b + c*(i + 1 - k);
            q.insert({d[i+k],i+k});
        }
    }
    cout << d[n-1] << endl;
    return 0;
}
