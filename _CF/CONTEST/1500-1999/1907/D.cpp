#include<bits/stdc++.h>
using namespace std;

int n;
int l[200010]{},r[200010]{};
int l1,r1,mid;

bool check(int k)
{
    int p_max=0,p_min=0;
    for(int i=1;i<=n;i++)
    {
        p_max+=k;
        p_min-=k;
        if(p_min>r[i]||p_max<l[i])
        {
            return false;
        }
        p_min=max(p_min,l[i]);
        p_max=min(p_max,r[i]);
    }
    return true;
}

void solve()
{
    l1=INT_MAX;r1=INT_MIN;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i]>>r[i];
        l1=min(l1,l[i]);
        r1=max(r1,r[i]);
    }
    while(l1<r1)
    {
        mid=l1+r1>>1;
        if(check(mid)) r1=mid;
        else l1=mid+1;
    }
    cout<<l1<<endl;
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