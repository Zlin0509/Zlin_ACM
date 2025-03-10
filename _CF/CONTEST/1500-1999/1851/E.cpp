#include<bits/stdc++.h>
using namespace std;

int n=1,k;
long long c[200010]{};
int used[200010]{};
vector<int>m[200010]{};

long long dfs(int i)
{
    if(used[i]!=0)
    {
        return c[i];
    }
    ++used[i];
    if(m[i].empty())
    {
        return c[i];
    }
    long long sum=0;
    for(int j=0;j<m[i].size();j++)
    {
        sum+=dfs(m[i][j]);
    }
    c[i]=min(c[i],sum);
    return c[i];
}

void solve()
{
    for(int i=1;i<=n;i++)
    {
        c[i]=0;used[i]=0;
        m[i].clear();
    }
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=0,x;i<k;i++)
    {
        cin>>x;
        c[x]=0;
    }
    for(int i=1,x;i<=n;i++)
    {
        cin>>x;
        for(int j=0,y;j<x;j++)
        {
            cin>>y;
            m[i].push_back(y);
        }
    }
    for(int i=1;i<=n;i++)
    {
        dfs(i);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<c[i]<<" ";
    }
    cout<<endl;
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