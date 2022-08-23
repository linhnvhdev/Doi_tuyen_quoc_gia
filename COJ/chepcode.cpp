#include <bits/stdc++.h>
#define For(i,a,b) for(int i = a; i <= b; ++i)
#define maxN 100005
using namespace std;
char s[maxN];
int a[maxN], sz;
bool ok = true;
void Change(int id,int cnt)
{
    while(id <= sz)
    {
        a[id] = cnt;
        cnt = (cnt + 1) % 2;
        id++;
    }
}
void Check(int i)
{
    if(i == sz)return;
    if(a[i] == a[i + 1])
    {
        ok = false;
        if(a[i + 1] < 9)
        {
            a[i + 1]++;
            Change(i + 2, 0);
        }
        else
        {
            a[i] = a[i + 1] = 0;
            int id = i - 1;
            while(true)
            {
                if(id == 0)
                {
                    a[0] = 1;
                    Change(1, 0);
                    break;
                }
                a[id] = (a[id] + 1) % 10;
                if(a[id] == 0)id--;
                else
                    if(a[id] != a[id - 1] && a[id] != a[id + 1])
                    {
                        Change(id + 1, 0);
                        break;
                    }
            }
        }
    }
    else
        Check(i + 1);
}
int main()
{
    scanf("%s", &s);
    sz = strlen(s);
    for(int i = 0; i < sz; i++)
        a[i + 1] = s[i] - '0';
    a[0] = 0;
    a[sz + 1] = -1;
    if(sz == 1)
    {
        printf("%d", a[1] + 1);
        return 0;
    }
    Check(1);
    if(ok)
    {
        int id = sz;
        while(true)
        {
            if(id == 0)
            {
                a[0] = 1;
                Change(1, 0);
                break;
            }
            a[id] = (a[id] + 1) % 10;
            if(a[id] == 0)id--;
            else
                if(a[id] != a[id - 1] && a[id] != a[id + 1])
                {
                    Change(id + 1, 0);
                    break;
                }
        }
    }
    For(i,0,sz)
    {
        if(i == 0 && a[i] == 0)continue;
        printf("%d", a[i]);
    }
}
