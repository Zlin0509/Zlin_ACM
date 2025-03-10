#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b,c;
    cin>>a>>b>>c;
    if(b%3+c<3&&b!=0&&b%3!=0)
    {
        cout<<"-1"<<'\n';
    }
    else
    {
        long long ans=(b+c)/3+a;
        (b+c)%3==0?ans:++ans;

        cout<<ans<<'\n';
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