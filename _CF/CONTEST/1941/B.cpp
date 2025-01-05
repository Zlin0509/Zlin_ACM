#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int a[200010]{};
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=2;i<=n-1;i++)
    {
        a[i]-=a[i-1]*2;
        a[i+1]-=a[i-1];
        a[i-1]=0;
        if(a[i]<0)
        {
            cout<<"NO"<<'\n';
            return;
        }
    }
    if(a[n]!=0||a[n-1]!=0)
    {
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
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