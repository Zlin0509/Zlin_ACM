#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,p,flag;
    int a[200010]{};
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==p)
        {
            flag=i;
        }
    }
    int r=n+1,l=1,mid;
    while(r-l>1)
    {
        mid=r+l>>1;
        if(a[mid]<=p) l=mid;
        else r=mid;
        // cout<<l<<" "<<r<<'\n';
    }
    if(l!=flag)
    {
        cout<<"1"<<'\n';
        cout<<l<<" "<<flag<<'\n';
    }
    else
    {
        cout<<"0"<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}