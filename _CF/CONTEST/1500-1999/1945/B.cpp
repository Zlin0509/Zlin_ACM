#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long a,b,m;
    cin>>a>>b>>m;
    long long ans=m/a+2+m/b;
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