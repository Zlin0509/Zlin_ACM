#include<bits/stdc++.h>
using namespace std;

int n=1;
char a1[200010]{},a2[200010]{};
int used[2][200010]{};

void solve()
{
    for(int i=1;i<=n+3;i++)
    {
        used[0][i]=0;used[1][i]=0;
    }
    used[0][1]=1;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a1[i];
    for(int i=1;i<=n;i++) cin>>a2[i];
    for(int i=1;i<=n;i++)
    {
        if(used[0][i]==1)
        {
            if(a2[i]=='>')
            {
                if(used[1][i]==0) used[1][i]=-1;
                used[1][i+1]=1;
            }
            if(a1[i+1]=='>')
            {
                if(used[0][i+1]==0) used[0][i+1]=-1;
                used[0][i+2]=1;
            }
        }
        if(used[1][i]==1)
        {
            if(a1[i]=='>')
            {
                if(used[0][i]==0) used[0][i]=-1;
                used[0][i+1]=1;
            }
            if(a2[i+1]=='>')
            {
                if(used[1][i+1]==0) used[1][i+1]=-1;
                used[1][i+2]=1;
            }
        }
    }
    if(used[1][n]==0)
    {
        cout<<"NO"<<'\n';
    }
    else
    {
        cout<<"YES"<<'\n';
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