#include<bits/stdc++.h>
using namespace std;

int n,ans=INT_MAX;
int a[110]{};
int l[110]{},r[110]{};
int len_l=0,len_r=0;
int l1[110]{},r1[110]{};

void solve()
{
    l[1]=a[1];
    len_l=1;
    l1[1]=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>l[len_l])
        {
            l[++len_l]=a[i];
        }
        else
        {
            l[lower_bound(l+1,l+1+len_l,a[i])-l]=a[i];
        }
        l1[i]=len_l;
    }
    r[1]=a[n];
    len_r=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]>r[len_r])
        {
            r[++len_r]=a[i];
        }
        else
        {
            r[lower_bound(r+1,r+1+len_r,a[i])-r]=a[i];
        }
        r1[i]=len_r;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    solve();
    for(int i=1;i<=n;i++)
    {
        // cout<<l1[i]<<" "<<r1[i+1]<<'\n';
        ans=min(ans,n-l1[i]-r1[i+1]);
    }
    cout<<ans<<'\n';
}