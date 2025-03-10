#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a[30]{},b[30]{};
    int n,k;
    string s,t;
    cin>>n>>k;
    cin>>s>>t;
    for(int i=0;i<n;i++)
    {
        a[s[i]-'a']+=1;
        b[t[i]-'a']+=1;
    }
    for(int i=0;i<=26;i++)
    {
        if(a[i]!=b[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    // for(int i=n-k;i<k;i++)
    // {
    //     if(s[i]!=t[i])
    //     {
    //         cout<<"NO"<<endl;
    //         return;
    //     }
    // }
    for(int i=0;i<n;i++)
    {
        if(i+k>=n&&i-k<0)
        {
            if(s[i]!=t[i])
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }
    cout<<"YES"<<endl;
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