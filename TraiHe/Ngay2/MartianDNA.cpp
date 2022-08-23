#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 200005
#define fi first
#define se second
using namespace std;

int n,k,R;
int a[maxn],dna[maxn],b[maxn],q[maxn],DNA[maxn][12];
int cur[maxn],need[maxn];

bool Check(int m)
{
    //cout << endl;
    For(i,1,n-m+1){
        bool ok = true;
        //cout << i << ' ' << i + m - 1 << endl;
        For(j,1,R){
            //cout << " * " << j << ' ' << b[j] << ' ' << q[j] << ' ' << DNA[i+m-1][j] << ' ' << DNA[i-1][j] << endl;
            int nu = DNA[i+m-1][j] - DNA[i-1][j];
            if(nu < q[j]){
                ok = false;
                break;
            }
        }
        if(ok) return true;
    }
    return false;
}

void Sub1()
{
    For(i,1,R)
        For(j,1,n){
            DNA[j][i] = DNA[j-1][i];
            if(a[j] == b[i]) DNA[j][i]++;
        }
    int l = 1, r = n;
    while(r - l > 1){
        int mid = (r+l)/2;
        //cout << "### " << mid << ' ' << Check(mid) << endl;
        if(Check(mid)) r = mid;
        else l = mid;
    }
    if(Check(l)) cout << l << endl;
    else{
        if(Check(r)) cout << r << endl;
        else cout << "impossible";
    }
    exit(0);
}

int main()
{
    scanf("%d%d%d",&n,&k,&R);
    For(i,1,n){
        scanf("%d",&a[i]);
        dna[a[i]]++;
    }
    int require = 0;
    For(i,1,R){
        scanf("%d%d",&b[i],&q[i]);
        if(dna[b[i]] < q[i]){
            cout << "impossible\n";
            return 0;
        }
        need[b[i]] = q[i];
        require++;
    }
    if(R <= 10) Sub1();
    int i = 1,j = 1,ans = n;
    cur[a[1]]++;
    if(cur[a[1]] == need[a[1]]) require--;
    while(true){
        if(require > 0){
            if(j == n) break;
            j++;
            if(++cur[a[j]] == need[a[j]]) require--;
        }
        else{
            ans = min(ans,j-i+1);
            if(cur[a[i]]-- == need[a[i]]) require++;
            i++;
            if(i > j) break;
        }
    }
    cout << ans << endl;
}
