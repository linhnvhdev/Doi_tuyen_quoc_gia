#include<bits/stdc++.h>
#define For(i,a,b) for(int i = a;i <= b;i++)
#define Forr(i,a,b) for(int i = a;i >= b;i--)
#define ll long long
#define maxn 18
#define Bit(x,i) ((x >> i) & 1)
using namespace std;

int r,c,tflip = 0;
char s[20];
int a[maxn][maxn],b[maxn][maxn];
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};

void flip(int i,int j)
{
    //cout << "# " << i << ' ' << j << endl;
    b[i][j] = 1 - b[i][j];
    b[i-1][j] = 1 - b[i-1][j];
    b[i+1][j] = 1 - b[i+1][j];
    b[i][j-1] = 1 - b[i][j-1];
    b[i][j+1] = 1 - b[i][j+1];
    tflip++;
}

bool check()
{
    For(j,1,c) if(b[r][j]) return false;
    return true;
}

int main()
{
    scanf("%d%d",&r,&c);
    For(i,1,r){
        scanf("%s",&s);
        For(j,1,c) a[i][j] = (s[j-1] == 'X') ? 1 : 0;
    }
    int nflip = 1e9;
    for(int i = 0;i < (1 << c);i++){
        For(j,1,r)
            For(k,1,c) b[j][k] = a[j][k];
        tflip = 0;
        For(j,0,c-1){
            if(Bit(i,j))
                flip(1,j+1);
            if(tflip >= nflip) break;
        }
        For(j,2,r){
            For(k,1,c)
                if(b[j-1][k])
                    flip(j,k);
            if(tflip >= nflip) break;
        }
        if(check()) if(nflip > tflip) nflip = tflip;
    }
    if(nflip == 1e9) cout << "Damaged billboard.\n";
    else cout << "You have to tap " << nflip <<" tiles.\n";
}
