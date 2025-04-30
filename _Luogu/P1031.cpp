#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n,sum=0;
    int a[210]{};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum/=n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=sum)
        {
            ++ans;
            a[i+1]+=a[i]-sum;
            a[i]=sum;   
        }
    }
    cout<<ans<<'\n';
}