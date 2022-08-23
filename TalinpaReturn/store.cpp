ll valmin[4*maxn],valmax[4*maxn],a[maxn],ans = 0;

void Init(int node,int l,int r)
{
    if(l == r) return valmin[node] = valmax[node] = a[l];
    int c = (l+r)/2;
    Init(2*node,l,c);
    Init(2*node+1,c+1,r);
    valmin[node] = min(valmin[2*node],valmin[2*node+1]);
    valmax[node] = max(valmax[2*node],valmax[2*node+1]);
}

int getmin(int node,int l,int r,int i,int j)
{
    if(r < i || l > j) return 1e9;
    if(l >= i && r <= j) return valmin[node];
    int c = (l+r)/2;
    return min(getmin(2*node,l,c,i,j),getmin(2*node+1,c+1,r,i,j));
}

int getmax(int node,int l,int r,int i,int j)
{
    if(r < i || l > j) return -1e9;
    if(l >= i && r <= j) return valmax[node];
    int c = (l+r)/2;
    return max(getmax(2*node,l,c,i,j),getmax(2*node+1,c+1,r,i,j));
}
