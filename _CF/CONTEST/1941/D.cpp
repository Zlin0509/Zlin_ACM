#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,k;
    int r1,r2;
    cin>>n>>m>>k;
    int r;char c;
    set<int>ans,f;
    ans.insert(k);
    while(m--)
    {
        cin>>r>>c;
        if(c=='0')
        {
            for(auto i=ans.begin();i!=ans.end();i++)
            {
                r1=(*i+r-1)%n+1;
                f.insert(r1);
            }
            ans.clear();
            ans=f;
            f.clear();
        }
        if(c=='1')
        {
            for(auto i=ans.begin();i!=ans.end();i++)
            {
                r1=(*i-r-1+n)%n+1;
                f.insert(r1);
            }
            ans.clear();
            ans=f;
            f.clear();
        }
        if(c=='?')
        {
            for(auto i=ans.begin();i!=ans.end();i++)
            {
                r1=(*i+r-1)%n+1;
                f.insert(r1);
                r2=(*i-r-1+n)%n+1;
                f.insert(r2);
            }
            ans.clear();
            ans=f;
            f.clear();
        }
        // for(auto it:ans)
        // {
        //     cout<<it<<" ";
        // }
        // cout<<'\n';
    }
    cout<<ans.size()<<'\n';
    for(auto i=ans.begin();i!=ans.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<'\n';
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