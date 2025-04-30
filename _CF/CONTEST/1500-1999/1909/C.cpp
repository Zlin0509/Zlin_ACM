#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
long long l[100010]{},r[100010]{},c[100010]{},a[200010]{};

void solve()
{
    ans=0;
    memset(l,sizeof(l),0);memset(r,sizeof(r),0);memset(c,sizeof(c),0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i];
    for(int i=1;i<=n;i++) cin>>r[i];
    for(int i=1;i<=n;i++) cin>>c[i];

    sort(l+1,l+n+1);sort(r+1,r+n+1);sort(c+1,c+n+1);

    stack<int>s;
    int p=1;

    for(int i=1;i<=n;i++)
    {
        while(l[p]<r[i]&&p<=n)
        {
            s.push(l[p]);
            ++p;
        }
        a[i]=r[i]-s.top();
        s.pop();
    }

    sort(a+1,a+1+n,greater<int>());
    for(int i=1;i<=n;i++) ans+=a[i]*c[i];

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