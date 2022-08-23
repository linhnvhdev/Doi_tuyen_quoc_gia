#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 250005
#define ll long long
#define fi first
#define se second
using namespace std;

int n,t,val[4*maxn],add[4*maxn],a[maxn],b[maxn];
ll k;

//void init(int node,int l,int r)
//{
//    if(l == r){
//        val[node] = l;
//        return;
//    }
//    int c = (l+r)/2;
//    init(2*node,l,c);
//    init(2*node+1,c+1,r);
//    if(a[val[2*node]] <= a[val[2*node+1]]) val[node] = val[2*node];
//    else val[node] = val[2*node+1];
//}
//
//void down(int node,int l,int r)
//{
//    int c = (l+r)/2;
//    val[2*node] += add[node];
//    val[2*node+1] += add[node];
//    add[2*node+1] += add[node];
//    add[2*node+1] += add[node];
//    add[node] = 0;
//}
//
//void update(int node,int l,int r,int i,int j,int v)
//{
//    if(l > j || r < i) return;
//    if(l >= i && r <= j){
//        val[node] += v;
//        add[node] += v;
//        return;
//    }
//    down(node,l,r);
//    int c = (l+r)/2;
//    update(2*node,l,c,i,j,v);
//    update(2*node,c+1,r,i,j,v);
//    if(a[val[2*node]] <= a[val[2*node+1]]) val[node] = val[2*node];
//    else val[node] = val[2*node+1];
//}
//
//int get(int node,int l,int r,int i,int j)
//{
//    if(r < i || l > j) return 0;
//    if(l >= i && r <= j) return val[node];
//    down(node,l,r);
//    int c = (l+r)/2;
//    int t1 = get(2*node,l,c,i,j);
//    int t2 = get(2*node,c+1,r,i,j);
//    if(a[t1] <= a[t2]) return t1;
//    else return t2;
//}

int main()
{
    freopen("LEXICOGRAFIC.inp","r",stdin);
    freopen("LEXICOGRAFIC.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%lld",&n,&k);
        bool ok1 = false;
        For(i,1,n)
            scanf("%d",&a[i]);
        if(k == 1ll*n*(n-1)/2){
            sort(a+1,a+1+n);
            For(i,1,n) printf("%d ",a[i]);
            continue;
        }
        for(int i = 1;k > 0 && i <= n; i++){
            int vtmin = i;
            For(j,i,min(i+k,1ll*n))
                if(a[j] < a[vtmin])
                    vtmin = j;
            //cerr <<t << ' ' << i << ' ' <<vtmin << ' ' << k << endl;
            k -= vtmin - i;
            Forr(j,vtmin,i+1) swap(a[j],a[j-1]);
            //For()
        }
        For(i,1,n) printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}
