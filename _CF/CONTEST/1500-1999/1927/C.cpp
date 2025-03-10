#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,k;
    int a[200010]{},b[200010]{};
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);sort(b,b+m);
    int l1=0,l2=0,n1=0,n2=0,j=1,all=0;
    while(j<=k)
    {
        if(a[l1]==b[l2]&&a[l1]==j)
        {
            while(a[l1]==j) ++l1;
            while(b[l2]==j) ++l2;
            ++j;
            ++all;
        }
        else if(a[l1]==j)
        {
            while(a[l1]==j) ++l1;
            ++n1;
            ++j;
        }
        else if(b[l2]==j)
        {
            while(b[l2]==j) ++l2;
            ++n2;
            ++j;
        }
        else
        {
            cout<<"NO"<<endl;
            return;
        }
        if(n1>k/2||n2>k/2)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    if(n1+all<k/2||n2+all<k/2)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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