#include<bits/stdc++.h>
using namespace std;

long long mod=1e9+7;
int n=1,k=1;
int a[200010]{};
long long dp[200010]{};

void solve()
{
    for(int i=0;i<=n;i++)
    {
        a[i]=dp[i]=0;
    }
    long long ans=0,M=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dp[i]=max(0ll,dp[i-1]+a[i]);
        M=max(M,dp[i]);
        ans=(ans+a[i]+mod)%mod;
    }
    // cout<<ans<<M<<'\n';
    ans=(ans+M+mod)%mod;
    for(int i=1;i<k;i++)
    {
        M=(M*2)%mod;
        ans=(ans+M+mod)%mod;
        // cout<<ans<<'\n';
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