#include<bits/stdc++.h>
using namespace std;

int n;
int a[200010]{};

int check(int k)
{
    int x=0;
    for(int i=1+k;i<=n;i++)
    {
        int y=abs(a[i]-a[i-k]),t=0;
        while(y!=0)
        {
            t=x%y;
            x=y;
            y=t;
        }
        if(x==1) return 0;
    }
    //    cout<<k<<endl;
    return 1;
}

void solve()
{
    memset(a,sizeof(a),0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    int ans=0;
    for(int k=1;k<=sqrt(n);k++)
    {
        if(n%k==0)
        {
            ans+=check(k);
            if(k*k!=n) ans+=check(n/k);
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