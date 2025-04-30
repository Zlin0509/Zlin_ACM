#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,n1,n2,ans=0;
    int a[200010]{};
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=n;
    if(a[1]==a[n])
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[1])
            {
                l=i+1;
            }
            else break;
        }
        for(int i=n;i>=l;i--)
        {
            if(a[i]==a[1])
            {
                r=i-1;
            }
            else break;
        }
        ans=r-l+1;
    }
    else
    {
        n1=n,n2=n;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[1])
            {
                --n1;
            }
            else break;
        }
        for(int i=n;i>=1;i--)
        {
            if(a[i]==a[n])
            {
                --n2;
            }
            else break;
        }
        ans=min(n1,n2);
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