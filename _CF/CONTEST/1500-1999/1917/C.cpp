#include<bits/stdc++.h>
using namespace std;



void solve()
{
    int n,k,d,ans=0,n1;
    int a[2010]{},v[100010]{};
    cin>>n>>k>>d;
    int x=d;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<k;i++) cin>>v[i];

    for(int i=1;i<=min(d,n*2+1);i++)
    {
        n1=0;--x;
        for(int j=1;j<=n;j++)
        {
            if(a[j]==j)
            {
                ++n1;
            }
        }
        ans=max(ans,n1+x/2);
        for(int j=1;j<=v[(i-1)%k];j++) ++a[j];
    }
    cout<<ans<<endl;
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