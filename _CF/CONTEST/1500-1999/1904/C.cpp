#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    long long a[200010]{};
    cin>>n>>k;
    for(int i=0,x;i<n;i++)
    {
        cin>>a[i];
    }
    if(k>2)
    {
        cout<<"0"<<endl;
        return;
    }
    sort(a,a+n);
    long long ans=a[0];
    if(k==1)
    {
        for(int i=0;i<n-1;i++)
        {
            ans=min(ans,a[i+1]-a[i]);
        }
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<n-1;i++)
    {
        ans=min(ans,a[i]);
        for(int j=i+1;j<n;j++)
        {
            ans=min(ans,a[j]-a[i]);
            int place=lower_bound(a,a+n,a[j]-a[i])-a;
            if(place>0) ans=min(ans,a[j]-a[i]-a[place-1]);
            if(place<n) ans=min(ans,a[place]-a[j]+a[i]);
        }
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