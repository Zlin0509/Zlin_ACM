#include<bits/stdc++.h>
using namespace std;

const int mod=20123;

int n,m;
int ladder_sum[10010]{};//每层总共有多少梯子;
int ladder[10010][110]{};
int a[10010][110]{};
int start,ans=0;

void read()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ladder[i][j]>>a[i][j];
            ladder_sum[i]+=ladder[i][j];
        }
    }
    cin>>start;
}

void solve()
{
    int i=1,j=start;
    while(i<=n)
    {
        ans=(ans+a[i][j])%mod;
        int x=a[i][j]%ladder_sum[i]+ladder_sum[i];
        if(ladder[i][j]==1) --x;
        // cout<<x<<'\n';
        while(x>0)
        {
            j=(j+1)%m;
            if(ladder[i][j]==1) --x;
        }
        ++i;
    }
}

int main()
{
    read();
    solve();
    cout<<ans;
}