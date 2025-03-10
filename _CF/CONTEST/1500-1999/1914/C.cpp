#include<bits/stdc++.h>
using namespace std;

int n=1,k,ans;
int a[200010]{},b[200010]{};
int f[200010]{},M[200010]{};

void solve()
{
    ans=0;
    for(int i=1;i<=n;i++)
    {
        a[i]=b[i]=0;
        f[i]=M[i]=0;
    }
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    M[1]=b[1];f[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        f[i]=f[i-1]+a[i];
        M[i]=max(b[i],M[i-1]);
    }
    for(int i=1;i<=n;i++)
    {
        if(i<=k)
        {
            int x=f[i]+M[i]*(k-i);
            ans=max(ans,x);
        }
    }
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