#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(a<b&&b<c)
    {
        cout<<"STAIR"<<'\n';
        return;
    }
    if(a<b&&b>c)
    {
        cout<<"PEAK"<<'\n';
        return;
    }
    cout<<"NONE"<<'\n';
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