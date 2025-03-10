#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,n1=0,n0=0;
    long long a[110]{},m=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m=max(m,a[i]);
    }
    int i=0;
    while((1ll<<i)<=m)
    {
        n1=0,n0=0;
        for(int j=1;j<=n;j++)
        {
            if((a[j]&(1ll<<i))!=0) ++n1;
            else ++n0;
        }
        ++i;
        if(n1!=0&&n0!=0)
        {
            break;
        }
    }
    cout<<(1ll<<i)<<endl;
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