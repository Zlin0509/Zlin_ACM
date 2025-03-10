#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,m,k,ans=0;
    cin>>n>>m>>k;
    int a[110]{},b[110]{};
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<m;i++) cin>>b[i];
    sort(a,a+n);sort(b,b+m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(a[i]+b[j]<=k) ++ans;
            else break;
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