#include<bits/stdc++.h>
using namespace std;

int n;
char a[2000]{};

void build(int l,int r)
{
    if(l!=r)
    {
        int mid=l+r>>1;
        build(l,mid);
        build(mid+1,r);
    }
    int a0=0,a1=0;
    for(int i=l;i<=r;i++)
    {
        a[i]=='0'?++a0:++a1;
    }
    if(a1&&a0)
    {
        cout<<"F";
    }
    else if(a1)
    {
        cout<<"I";
    }
    else
    {
        cout<<"B";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    n=pow(2,n);
    for(int i=1;i<=n;i++) cin>>a[i];
    build(1,n);
}