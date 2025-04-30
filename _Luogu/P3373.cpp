#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+10;

struct node
{
    int l,r;
    long long sum;
    long long plz,mlz;
}tree[MAXN*4]{};
long long a[MAXN]{},ans=0,n,m,M;

inline void push_down(long long i)
{
    long long k1=tree[i].mlz,k2=tree[i].plz;
    tree[i<<1].sum=(tree[i<<1].sum*k1+k2*(tree[i<<1].r-tree[i<<1].l+1))%M;
    tree[i<<1|1].sum=(tree[i<<1|1].sum*k1+k2*(tree[i<<1|1].r-tree[i<<1|1].l+1))%M;
    tree[i<<1].mlz=tree[i<<1].mlz*k1%M;
    tree[i<<1|1].mlz=tree[i<<1|1].mlz*k1%M;
    tree[i<<1].plz=(tree[i<<1].plz*k1+k2)%M;
    tree[i<<1|1].plz=(tree[i<<1|1].plz*k1+k2)%M;
    tree[i].mlz=1;tree[i].plz=0;
    return;
}

inline void build(int i,int l,int r)
{
    tree[i]={l,r,0,0,1};
    if(tree[i].l==tree[i].r)
    {
        tree[i].sum=a[l]%M;
        return;
    }
    int mid=l+r>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
    tree[i].sum=(tree[i*2].sum+tree[i*2+1].sum)%M;
    return;
}

inline void search(int i,int l,int r)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        ans=(ans+tree[i].sum)%M;
        return;
    }
    push_down(i);
    int mid=tree[i].l+tree[i].r>>1;
    if(mid>=l) search(i<<1,l,r);
    if(mid<r) search(i<<1|1,l,r);
    // tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
    return;
}

inline void add_p(int i,int l,int r,int k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].plz+=k;
        tree[i].sum+=k*(tree[i].r-tree[i].l+1);
        return;
    }
    push_down(i);
    int mid=tree[i].l+tree[i].r>>1;
    if(mid>=l) add_p(i<<1,l,r,k);
    if(mid<r) add_p(i<<1|1,l,r,k);
    tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
    return;
}

inline void add_m(int i,int l,int r,int k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].plz*=k;
        tree[i].mlz*=k;
        tree[i].sum*=k;
        return;
    }
    push_down(i);
    int mid=tree[i].l+tree[i].r>>1;
    if(mid>=l) add_m(i<<1,l,r,k);
    if(mid<r) add_m(i<<1|1,l,r,k);
    tree[i].sum=tree[i<<1].sum+tree[i<<1|1].sum;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m>>M;
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,1,n);
    int j,x,y,z;
    while(m--)
    {
        cin>>j;
        if(j==1)
        {
            cin>>x>>y>>z;
            add_m(1,x,y,z);
        }
        else if(j==2)
        {
            cin>>x>>y>>z;
            add_p(1,x,y,z);
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