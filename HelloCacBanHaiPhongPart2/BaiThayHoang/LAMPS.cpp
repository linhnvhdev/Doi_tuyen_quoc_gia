/**
    ta chia các pt của mảng vào các khối,mỗi khối gồm (sqrt(n)) phần tử
    len = sqrt(n);
    sz = (n + len - 1)/len;
    //các khối chứa chỉ số từ 0 -> sz - 1
    For(i,1,n){
        b[i/len] .push_back(a[i]);
    }
    // các pt trong 1 khối sắp xếp tăng
    For(i,1,sz-1){
        sort(b.begin(),b.end());
    }
**/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 100005
#define INF 1e9
#define Bit(x,i) ((x >> i) & 1)
#define point pair<int,int>
using namespace std;

int n,a[maxn],len,sz;
vector<int> b[400];

// Truy vấn 1 :
int query1(int u,int v,int x)
{
    int l = (u-1)/len + 1;
    int r = (v-1)/len + 1;
    int ans = 0;
    if(l == r){
        For(i,u,v) if(a[i] >= x) ans++;
        return ans;
    }
    For(i,u,l*len) if(a[i] >= x) ans++;
    For(i,l+1,r-1) ans += b[i].end() - lower_bound(b[i].begin(),b[i].end(),x);
    For(i,(r-1)*len + 1,v) if(a[i] >= x) ans++;
    return ans;
}

void query2(int u,int x)
{
    int i = (u-1)/len + 1;
    int j = lower_bound(b[i].begin(),b[i].end(),a[u]) - b[i].begin();
    a[u] = b[i][j] = x;
    for(int k = j;k > 0 && b[i][k] < b[i][k-1];k--)
        swap(b[i][k],b[i][k-1]);
    for(int k = j;k < b[i].size() - 1 && b[i][k] > b[i][k+1];k++)
        swap(b[i][k],b[i][k+1]);
}

int main()
{
    scanf("%d",&n);
    len = sqrt(n);
    sz = (n + len - 1)/len;
    //các khối chứa chỉ số từ 0 -> sz - 1
    For(i,1,n){
        scanf("%d",&a[i]);
        b[(i-1)/len + 1] .push_back(a[i]);
    }
    // các pt trong 1 khối sắp xếp tăng
    For(i,1,sz)
        sort(b[i].begin(),b[i].end());
    int q;
    scanf("%d",&q);
    For(i,1,q){
        int c,u,v,x;
        scanf("%d",&c);
        if(c == 0){
            scanf("%d%d%d",&u,&v,&x);
            printf("%d\n",query1(u,v,x));
        }
        else{
            scanf("%d%d",&u,&x);
            query2(u,x);
        }
    }
}
