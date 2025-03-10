#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x,y;
    long long ans=0;
    int a[200010]{};
    map<pair<int,int>,int>p;
    cin>>n>>x>>y;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
    {
        ans+=p[{(x-a[i]%x)%x,a[i]%y}];
        ++p[{a[i]%x,a[i]%y}];
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}