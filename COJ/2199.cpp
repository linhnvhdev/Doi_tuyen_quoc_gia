/**
    Gọi 2 xâu ban đầu là s1 và s2
    Tạo ra xâu s = s1+'$'+s2
    Tính mảng hậu tố SA của xâu s
    Nhận xét:
        + Xâu con chung của s1,s2 chính là tiền tố chung của 2 hậu tố của xâu S Trong đó có 1 hậu tố của s1, 1 hậu tố của s2
    Chú ý: Sa[i] là hậu tố của xâu s1 <=> Sa[i] < s1.size()
        + Xâu con chung dài nhất là tiền tố chung dài nhất của 2 loại hậu tố nói trên
        + Mặt khác hai hậu tố này phải là 2 hậu tố liên tiếp trên mảng hậu tố
    => ans = tiền tố chung dài nhất của 2 hậu tố liên tiếp nhau, trong đó có 1 hậu tố là của s1 và hậu tố kia là của s2
    Vấn đề còn lại là tìm tiền tố chung dài nhất của 2 hậu tố bất kì
    Căn cứ vào mảng p[i][j]
**/


#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,m,n1,n2,logn = 0,p[2*maxn][19],id[2*maxn];
string s,s1,s2;
pair<pair<int,int>,int> L[2*maxn];

vector<string> ans;

int lcp(int x,int y)
{
    if(x == y) return (n - x);
    int ans = 0;
    for(int i = logn; x < n && y < n && i >= 0;i--){
        if(p[x][i] == p[y][i]){
            x += (1<<i);
            y += (1<<i);
            ans += (1<<i);
        }
    }
    return ans;
}

int main()
{
    while(cin >> s1 >> s2){
        ans.clear();
        s = s1 + '$' + s2;
        n = s.size(); n1 = s1.size(),n2 = s2.size();
        logn = 0;
        while((1<<logn) < n) logn++;
        For(i,0,n-1) p[i][0] = s[i];
        For(j,1,logn){
            For(i,0,n-1)
                L[i] = {{p[i][j-1],(i+(1<<(j-1)) < n) ? p[i+(1<<(j-1))][j-1] : -1},i};
            sort(L,L+n);
            For(i,0,n-1) p[L[i].se][j] = (i > 0 && L[i].fi == L[i-1].fi) ? p[L[i-1].se][j] : i;
        }
        For(i,0,n-1) id[p[i][logn]] = i;
        int cur_ans = 0,bg = -1;
        //For(i,0,n-1) cout << id[i] << endl;
        For(x,0,n-2){
            if(id[x] < n1 && id[x+1] >= n1){
                int kq = lcp(id[x],id[x+1]);
                if(kq > cur_ans){
                    cur_ans = kq;
                    ans.clear();
                    ans.push_back(s.substr(id[x],cur_ans));
                }
                else if(kq == cur_ans)
                    ans.push_back(s.substr(id[x],cur_ans));
            }

            if(id[x] >= n1 && id[x+1] < n1){
                int kq = lcp(id[x],id[x+1]);
                if(kq > cur_ans){
                    cur_ans = kq;
                    ans.clear();
                    ans.push_back(s.substr(id[x],cur_ans));
                }
                else if(kq == cur_ans)
                    ans.push_back(s.substr(id[x],cur_ans));
            }
        }
        if(cur_ans == 0){
            printf("No common sequence.\n\n");
            continue;
        }
        ans.resize(distance(ans.begin(),unique(ans.begin(),ans.end())));
        for(int i = 0;i < ans.size();i++)
            cout << ans[i] << '\n';
        printf("\n");
    }
    return 0;
}
