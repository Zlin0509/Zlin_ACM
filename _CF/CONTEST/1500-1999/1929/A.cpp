#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int a[200010]{};
    long long ans=0;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++) ans+=a[i]-a[i-1];
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