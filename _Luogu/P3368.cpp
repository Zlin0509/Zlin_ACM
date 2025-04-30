#include<bits/stdc++.h>
using namespace std;

struct node
{
    int l;
    int r;
    long long sum;
}tree[2000010]{};
long long a[500010]{};
int n,m;

void build(int i,int l,int r)
{
    tree[i]={l,r,0};
    if(l==r)
    {
        tree[i].sum=a[l];
        return;
    }
    int mid=l+r>>1;
    build(i*2,l,mid);
    build(i*2+1,mid+1,r);
}

void output(int i,int target,long long sum)
{
    sum+=tree[i].sum;
    // cout<<sum<<endl;
    if(tree[i].l==tree[i].r)
    {
        cout<<sum<<'\n';
        return;
    }

    int mid=tree[i].l+tree[i].r>>1;
    if(mid>=target)
    {
        output(i*2,target,sum);
    }
    else
    {
        output(i*2+1,target,sum);
    }
}

void change_tree(int i,int l,int r,int k)
{
    if(tree[i].l>=l&&tree[i].r<=r)
    {
        tree[i].sum+=k;
        // cout<<i<<" "<<tree[i].sum<<endl;
        return;
    }
    int mid=tree[i].l+tree[i].r>>1;
    // cout<<tree[i].l<<" "<<tree[i].r<<endl;
    // cout<<mid<<endl;
    if(mid>=l)
        change_tree(i*2,l,r,k);
    if(mid<r)
        change_tree(i*2+1,l,r,k);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    int q,x,y,z;
    for(int i=1;i<=m;i++)
    {
        cin>>q;
        if(q==1)
        {
            cin>>x>>y>>z;
            change_tree(1,x,y,z);
        }
        else
        {
            cin>>x;
            long long sum=0;
            output(1,x,sum);
        }
    }
}