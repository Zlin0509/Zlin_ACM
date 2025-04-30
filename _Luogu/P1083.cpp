#include<bits/stdc++.h>
using namespace std;

const int mod=1e6+7;

int n,m;
int a[1000010]{};
int num[1000010]{},l[1000010]{},r[1000010]{};
long long diff[1000010]{},c[1000010]{};

bool check(int x)
{
    for(int i=1;i<=n;i++)
    {
        diff[i]=0;c[i]=0;
    }
    for(int i=1;i<=x;i++)
    {
        diff[l[i]]+=num[i];
        diff[r[i]+1]-=num[i];
    };
    for(int i=1;i<=n;i++)
    {
        c[i]=c[i-1]+diff[i];
        if(c[i]>a[i]) return false;
    }
    return true;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>num[i]>>l[i]>>r[i];
    int begin=1,end=m,mid;
    if(check(m))
    {
        cout<<'0'<<'\n';
        return 0;
    }
    while(begin<end)
    {
        mid=begin+end>>1;
        if(check(mid)) begin=mid+1;
        else end=mid;
    }
    cout<<"-1"<<'\n'<<begin<<'\n';
}