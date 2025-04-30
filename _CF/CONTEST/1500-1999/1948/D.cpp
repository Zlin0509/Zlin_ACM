#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string x;
    cin>>x;
    int ans=0;
    for(int d=1;d<=x.length()/2;d++)
    {
        int cnt=0;
        for(int i=0;i<x.length()-d;i++)
        {
            if(x[i]==x[i+d]||x[i]=='?'||x[i+d]=='?')
            {
                ++cnt;
            }
            if(i-d>=0&&(x[i]==x[i-d]||x[i]=='?'||x[i-d]=='?'))
            {
                --cnt;
            }
            if(i-d>=-1&&cnt==d)
            {
                ans=d;
            }
        }
    }
    cout<<ans*2<<'\n';
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