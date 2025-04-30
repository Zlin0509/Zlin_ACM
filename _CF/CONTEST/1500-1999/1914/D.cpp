#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[200010]{},b[200010]{},c[200010]{};

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
    for(int i=1;i<=n;i++) cin>>b[i].first,b[i].second=i;
    for(int i=1;i<=n;i++) cin>>c[i].first,c[i].second=i;
    sort(a+1,a+1+n),sort(b+1,b+1+n),sort(c+1,c+1+n);

    int ans=INT_MIN;

    for(int i=n;i>=n-2;i--)
    {
        for(int j=n;j>=n-2;j--)
        {
            for(int q=n;q>=n-2;q--)
            {
                if(a[i].second!=b[j].second&&a[i].second!=c[q].second&&b[j].second!=c[q].second)
                {
                    ans=max(ans,a[i].first+b[j].first+c[q].first);
                }
            }
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