/**
    Gọi S[i][j] là các tiền tố của các hậu tố thứ i có độ dài là 2^j
    Xét j = 0 -> log2n ở bước thứ i ta sẽ sắp xếp các s[i][j] theo thứ tự từ điển và lưu thứ tự của s[i][j] trong mảng p[i][j]
    Lưu ý 2 xâu = thì 2 P = nhau
    Gsử  đã có thứ tự  ở bước j  khi đó ở bước j + 1 có đc = vc ghép s[i][j] và s[i + 2^j][j] -> s[i][j+1]
    việc sắp xếp các s[i][j+1] là dựa trên (p[i][j],p[i+2^j][j])
    => sa[p[i][m]] = i với i = 0 -> n-1
**/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define ll long long
#define fi first
#define se second
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int n,k,a[maxn],sum[maxn];
int child[31*maxn][2],sz = 0;
int cnt[31*maxn];
ll ans = 0;

void update(int x)
{
    int node = 0;
    //cout << "#### " << x << endl;
    Forr(i,30,0){
        int bit = Bit(x,i);
        //cout << node << endl;
        if(child[node][bit] == 0) child[node][bit] = ++sz;
        node = child[node][bit];
        cnt[node]++;
    }
}
ll get(int x)
{
    ll tmp = 0;
    int node = 0;
    Forr(i,30,0){
        int bit = Bit(x,i),bitk = Bit(k,i);
        if(bitk == 1){
            if(child[node][bit] != 0) tmp += cnt[child[node][bit]];
            node = child[node][1-bit];
        }
        else node = child[node][bit];
        if(node == 0) break;
    }
    return tmp;
}

int main()
{
    cin >> n >> k;
    For(i,1,n){
        scanf("%d",&a[i]);
        sum[i] = sum[i-1] ^ a[i];
    }
    update(0);
    For(i,1,n){
        ans += get(sum[i]);
        //cout << ans << endl;
        update(sum[i]);
    }
    cout << ans << endl;
}
