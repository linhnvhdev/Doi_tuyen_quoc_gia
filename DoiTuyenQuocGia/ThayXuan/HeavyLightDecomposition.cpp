Phân rã cây
Duyệt lần 1 dfs(u):
    {
        pd[u] : cha đỉnh u
        s[u] : size cây con u
        đưa đỉnh nặng nhất lên đầu
        sconmax[u]
    }
Cạnh nặng nối u với con u nặng nhất và các đường
Duyệt lần 2 : Hld(u):
    {
        pos[u]: thứ tự duyệt u;
        tt[i]: đỉnh có thứ tự duyệt thứ i
        head[u]: đầu đường nặng chứa u
        d_Hld[u]: thứ tự đường nặng chứa u
        e[u] : độ dài đường đi từ u lên cha u
    }
gethld(u,v)
{
    if (head[u] == head[v])
            get(1,1,n,pos[u],pos[v]);

}
