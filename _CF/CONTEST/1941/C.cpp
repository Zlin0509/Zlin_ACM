#include<bits/stdc++.h>
using namespace std;



void solve()
{
    int n;
    string a;
    cin>>n;
    int ans=0;
    cin>>a;
    for(int i=0;i<=n-3;i++)
    {
        if(a[i]=='m'&&a[i+1]=='a'&&a[i+2]=='p')
        {
            if(i+4<n)
            {
                if(a[i+3]=='i'&&a[i+4]=='e')
                {
                    a[i+2]='0';
                    ++ans;
                }
                else
                {
                    a[i+1]='0';
                    ++ans;
                }
            }
            else
            {
                a[i+1]='0';
                ++ans;
            }
        }
        if(a[i]=='p'&&a[i+1]=='i'&&a[i+2]=='e')
        {
            a[i+1]='0';
            ++ans;
        }
    }
    cout<<ans<<'\n';
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