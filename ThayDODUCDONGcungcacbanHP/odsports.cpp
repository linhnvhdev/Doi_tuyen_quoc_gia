/*
    Sub3: Dùng cặp ghép
    Thuật toán tham:
        lần lượt xét từng cột. nếu chỉ có 1 đoạn thỏa mãn => chon
                               nếu có nhiều đoạn thỏa mãn => chọn đoạn kết thúc sớm nhất
    (1) sắp xếp các đoạn tăng dần theo điểm bắt đầu
    (2) Xét lần lượt từng cột:{
        Đẩy các đoạn có điểm bắt đầu là i vào
        Lấy ra phần tử có điểm cuối nhỏ nhất
    }
    => O(n * log2(n)) (Đây là 1 Truy Vấn)
    => Tìm ra m lớn nhất mà nó có nghiệm = vc chặt nhị phân
    => O(n * log2(n)^2)
*/

#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
#define fi first
#define se second
using namespace std;

int n,v[maxn],m,s[maxn],q,x[15],limit = 0;
bool used[15];
pair<int,int> t[maxn];
bool ok = false;

bool check(int mid)
{

    priority_queue<int> pq;
    For(i,1,n) t[i] = {max(1,v[i] - s[i]/mid),min(n,v[i] + s[i]/mid)};
    sort(t+1,t+1+n);
    int vt = 1;
    For(i,1,n){
        while(vt <= n && t[vt].fi == i){
            pq.push(-t[vt].se);
            vt++;
        }
        if(!pq.empty() && -pq.top() >= i) pq.pop();
        else return false;
    }
    return true;
}

void Init()
{
    int l = 1,r = 1e9;
    while(r - l > 1){
        int mid = (l + r)/2;
        //cerr << mid << ' ' << check(mid) << endl;
        if(check(mid)) l = mid;
        else r = mid;
    }
    if(check(r)) limit = r;
    else if(check(l))limit = l;
    else limit = 0;
}

int main()
{
    //freopen("odsports.inp","r",stdin);
    //freopen("odsports.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&v[i]);
    For(i,1,n) scanf("%d",&s[i]);
    Init();
    //cerr << limit << endl;
    scanf("%d",&q);
    For(i,1,q){
        scanf("%d",&m);
        printf("%d ",(m <= limit));
    }
}

/*
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 100005
using namespace std;

int n,v[maxn],m,s[maxn],q,x[15];
bool used[15];
bool ok = false;

void dfs(int i)
{
    if(ok) return;
    if(i > n){
        ok = true;
        return;
    }
    for(int j = max(v[i] - (s[i]/m),1);j <= min(v[i] + (s[i]/m),n);j++){
        if(used[j]) continue;
        used[j] = true;
        dfs(i+1);
        used[j] = false;
    }
}

void Solve(int m)
{
    memset(used,0,sizeof(used));
    ok = false;
    dfs(1);
    printf("%d ",ok);
}

int main()
{
    freopen("odsports.inp","r",stdin);
    freopen("odsports.out","w",stdout);
    scanf("%d",&n);
    For(i,1,n) scanf("%d",&v[i]);
    For(i,1,n) scanf("%d",&s[i]);
    scanf("%d",&q);
    For(i,1,q){
        scanf("%d",&m);
        Solve(m);
    }
}
*/
