#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        if(i%2==0)
        {
            for(int j=0;j<n;j++)
            {
                j%2==0?cout<<"##":cout<<"..";

            }
            cout<<'\n';
            for(int j=0;j<n;j++)
            {
                j%2==0?cout<<"##":cout<<"..";

            }
            cout<<'\n';
        }
        else
        {
            for(int j=0;j<n;j++)
            {
                j%2==0?cout<<"..":cout<<"##";

            }
            cout<<'\n';
            for(int j=0;j<n;j++)
            {
                j%2==0?cout<<"..":cout<<"##";

            }
            cout<<'\n';
        }
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