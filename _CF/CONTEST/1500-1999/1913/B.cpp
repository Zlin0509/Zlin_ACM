#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string x;
    int n0=0,n1=0;
    cin>>x;
    int len=x.length();
    for(int i=0;i<len;i++)
    {
        x[i]=='0'?++n0:++n1;
    }
    int ans=0;
    for(int i=0;i<len;i++)
    {
        if(x[i]=='0'&&n1!=0)
        {
            --n1;
        }
        else if(x[i]=='1'&&n0!=0)
        {
            --n0;
        }
        else
        {
            ++ans;
            --len;
            --i;
        }
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