#include<bits/stdc++.h>
using namespace std;

int dp[200010]{},id[200010]{};
vector<pair<int,int>>edg[200010]{};
int n=1;

void dfs(int i)
{
    for(auto it:edg[i])
    {
        if(dp[it.first]==0)
        {
            dp[it.first]=dp[i]+(it.second<=id[i]);
            id[it.first]=it.second;
            dfs(it.first);
        }
    }
}

void solve()
{
    for(int i=0;i<=n;i++)
    {
        dp[i]=id[i]=0;
        edg[i].clear();
    }
    cin>>n;
    for(int i=1,u,v;i<n;i++)
    {
        cin>>u>>v;
        edg[v].push_back({u,i});
        edg[u].push_back({v,i});
    }
    dp[1]=1;id[1]=0;
    dfs(1);
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
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