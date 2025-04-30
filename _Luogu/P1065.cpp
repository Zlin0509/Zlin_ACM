#include<bits/stdc++.h>
using namespace std;

int m,n,ans=0;
struct temp
{
    int num;
    int time;
}a[22][22]{};
int manage[550]{};
int step[22]{},last_time[22]{};
int mac[22][50010]{};

void read()
{
    cin>>m>>n;
    for(int i=1;i<=n*m;i++) cin>>manage[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j].num;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>a[i][j].time;
        }
    }
}

void solve()
{
    for(int d=1;d<=m*n;d++)
    {
        int id=a[manage[d]][step[manage[d]]+1].num,cost=a[manage[d]][step[manage[d]]+1].time;
        int sum=0;
        for(int i=last_time[manage[d]]+1;;i++)
        {
            if(mac[id][i]==0) ++sum;
            else sum=0;
            if(sum==cost)
            {
                for(int j=i-cost+1;j<=i;j++) mac[id][j]=1;
                ++step[manage[d]];
                last_time[manage[d]]=i;
                ans=max(ans,i);
                break;
            }
        }
    }
}

int main()
{
    read();
    solve();
    cout<<ans<<'\n';
}