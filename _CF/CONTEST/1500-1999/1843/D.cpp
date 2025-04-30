#include<bits/stdc++.h>
using namespace std;

int n=1,q,x,y;
vector<int>tree[200010]{};
int depth[200010]{};
long long num[200010]{};

int dfs(int i,int f)
{
    if(depth[i]==1&&i!=1)
    {
        num[i]=1;
        return num[i];
    }
    for(auto j:tree[i])
    {
        if(j==f) continue;
        num[i]+=dfs(j,i);
    }
    return num[i];
}

void solve()
{
    for(int i=0;i<=n;i++) tree[i].clear(),depth[i]=0,num[i]=0;
    cin>>n;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
        depth[x]++;depth[y]++;
    }
    dfs(1,1);
    cin>>q;
    while(q--)
    {
        cin>>x>>y;
        long long ans=num[x]*num[y];
        cout<<ans<<endl;
    }
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