#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int a[300010]{};
    char ch;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>ch;
        a[i]=a[i-1];
        if(ch=='0')
        {
            ++a[i];
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     cout<<a[i];
    // }
    int ans=-1;
    for(int i=0;i<=n;i++)
    {
        if(a[i]>=(i+1)/2&&(n-a[n]-i+a[i])>=(n-i+1)/2)
        {
            double x=double(n)/2-ans,y=double(n)/2-i;
            // cout<<x<<y<<'\n';
            if(abs(x)>abs(y))
            {
                ans=i;
            }
            else
            {
                break;
            }
        }
    }
    cout<<ans<<'\n';
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