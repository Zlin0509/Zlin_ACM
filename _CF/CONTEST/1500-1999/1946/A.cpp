#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int a[200010]{};
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    int check=a[(n+1)/2];
    for(int i=(n+1)/2;i<=n;i++)
    {
        if(a[i]==check)
        {
            ++ans;
        }
        else
        {
            break;
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