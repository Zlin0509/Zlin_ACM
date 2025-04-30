#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

struct node
{
    int l,r;
    long long sum;
    long long lz;
}tree[MAXN*4]{};
long long a[MAXN]{},ans=0,n,m;

inline void push_down(int i)
{
    if(tree[i].lz!=0)
    {
        tree[i*2].lz+=tree[i].lz;
        tree[i*2+1].lz+=tree[i].lz;
        int mid=tree[i].l+tree[i].r>>1;
        tree[i*2].sum+=tree[i].lz*(mid-tree[i].l+1);
        tree[i*2+1].sum+=tree[i].lz*(tree[i].r-mid);
        tree[i].lz=0;
    }
    return;
}

inline void build(int i,int l,int r)
{
    tree[i]={l,r,0,0};
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=a[l];
        return;
    }
    int mid=l+r>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}

inline void add(int i,int l,int r ,int k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].lz+=k;
        tree[i].sum+=k*(tree[i].r-tree[i].l+1);
        return;
    }
    int mid=tree[i].l+tree[i].r>>1;
    push_down(i);
    if(mid>=l) add(i*2,l,r,k);
    if(mid<r) add(i*2+1,l,r,k);
    tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
    return;
}

inline void search(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        ans+=tree[i].sum;
        return;
    }
    int mid=tree[i].l+tree[i].r>>1;
    // cout<<tree[i].l<<" "<<tree[i].r<<endl;
    push_down(i);
    if(mid>=l) search(i*2,l,r);
    if(mid<r) search(i*2+1,l,r);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    int j,x,y,z;
    while(m--)
    {
        cin>>j;
        if(j==1)
        {
            cin>>x>>y>>z;
            add(1,x,y,z);
        }
        else
        {
            cin>>x>>y;
            search(1,x,y);
            cout<<ans<<'\n';
            ans=0;
        }
    }
}