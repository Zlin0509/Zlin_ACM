#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[200010]{},pre[200010]{};
long long go[200010]{},back[200010]{};

void solve()
{
    memset(go,sizeof(go),0);memset(back,sizeof(back),0);
    memset(a,sizeof(a),0);memset(pre,sizeof(pre),0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    pre[1]=2;pre[n]=n-1;
    for(int i=2;i<n;i++)
    {
        int x=a[i+1]-a[i],y=a[i]-a[i-1];
        x>y?pre[i]=i-1:pre[i]=i+1;
    }

    //打表;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]==i+1) go[i+1]=go[i]+1;
        else go[i+1]=go[i]+a[i+1]-a[i];
    }

    for(int i=n;i>=1;i--)
    {
        if(pre[i]==i-1) back[i-1]=back[i]+1;
        else back[i-1]=back[i]+a[i]-a[i-1];
    }

    cin>>m;
    while(m--)
    {
        int x,y,ans=0;
        cin>>x>>y;
        if(x<y)
        {
            ans=go[y]-go[x];
        }
        if(x>y)
        {
            ans=back[y]-back[x];
        }
        cout<<ans<<endl;
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