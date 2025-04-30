#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    cin>>a>>b;
    if(a<b) swap(a,b);
    if(a==1&&b==1)
    {
        cout<<"No"<<endl;
        return;
    }
    if(a==2&&b==1)
    {
        cout<<"No"<<endl;
        return;
    }
    if(b%2!=0&&a%2!=0)
    {
        cout<<"No"<<endl;
        return;
    }
    if(b%2!=0&&a==b*2)
    {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
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