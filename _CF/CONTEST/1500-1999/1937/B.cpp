#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,l,r;
    string a,b;
    cin>>n;
    cin>>a;
    cin>>b;
    l=0,r=n-1;
    for(int i=n-1;i>0;i--)
    {
        if(a[i]=='1'&&b[i-1]=='0') r=i-1;
    }
    for(int i=0;i<r;i++)
    {
        if(a[i+1]=='0'&&b[i]=='1') l=i+1;
    }
    for(int i=0;i<=r;i++) cout<<a[i];
    for(int i=r;i<n;i++) cout<<b[i];
    cout<<endl;
    cout<<r-l+1<<endl;
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