#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    if(n%2!=0)
    {
        cout<<"NO"<<'\n';
        return;
    }
    cout<<"YES"<<'\n';
    for(int i=0;i<n/2;i++)
    {
        cout<<"BAA";
    }
    cout<<"B";
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