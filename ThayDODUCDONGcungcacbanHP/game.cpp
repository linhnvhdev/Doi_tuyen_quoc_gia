/*
    Cặp ghép cực đại Wryyyyyyyyyyyyyy
    Tìm ghép cho đỉnh i(bên trái)
    chính là tìm 1 đường đi tại i sang trái kết thúc tại 1 đỉnh tự do bên phải j
    vd
    có n số
    ghép thành nhóm nhiều nhất sao cho ghép thành snt
    => lẻ trái, chẵn phải
    nếu 2 số + vào = snt -> có cạnh nối
    Nhưng nếu xét như thế thì sẽ bị dính th 1 ghép với 1
    => Ghép các số > 1, ghép đc thì ghép
*/
#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define maxn 505
#define Bit(x,i) ((x >> i)&1)
#define fi first
#define se second
using namespace std;

int main()
{
    freopen("game.inp","r",stdin);
    freopen("game.out","w",stdout);
}
