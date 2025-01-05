#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200010]{};
long long dp[200010][2]{};

void solve()
{
    memset(a,sizeof(a),0);
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=0;dp[i][1]=0;
    }
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    dp[1][0]=INT_MIN;dp[1][1]=INT_MIN;
    abs(a[1])%2==0?dp[1][0]=a[1]:dp[1][1]=a[1];
    for(int i=2;i<=n;i++)
    {
        if(abs(a[i])%2==0)
        {
            dp[i][0]=max(dp[i-1][1]+a[i],a[i]);
            dp[i][1]=INT_MIN;
        }
        else
        {
            dp[i][1]=max(dp[i-1][0]+a[i],a[i]);
            dp[i][0]=INT_MIN;
        }
    }
    // for(int i=1;i<=n;i++)
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
    long long ans=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,dp[i][0]);
        ans=max(ans,dp[i][1]);
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