#include<bits/stdc++.h>
using namespace std;

long long m,s,t;
int dp[300010][2]{};
int M[300010]{};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>m>>s>>t;
    M[0]=m;
    for(int i=1;i<=t;i++)
    {
        dp[i][1]=dp[i-1][1]+17;//直接跑的情况;

        dp[i][0]=dp[i-1][0];
        if(M[i-1]>=10)
        {
            M[i]=M[i-1]-10;
            dp[i][0]+=60;
        }
        else
        {
            M[i]=M[i-1]+4;
        }

        dp[i][1]=max(dp[i][1],dp[i][0]);

        if(max(dp[i][0],dp[i][1])>=s)
        {
            cout<<"Yes"<<'\n';
            cout<<i<<'\n';
            return 0;
        }
    }
    cout<<"No"<<'\n';
    cout<<max(dp[t][0],dp[t][1])<<'\n';
}