#include<bits/stdc++.h>
using namespace std;

long long n,p,l,t;

bool check(int k)
{
    long long ans=0;
    ans+=k*l;
    int x=(n-1)/7+1;
    if(k*2<=x) ans+=k*2*t;
    else ans+=x*t;
    return ans>=p;
}

void solve()
{
    cin>>n>>p>>l>>t;
    int l=1,r=n,mid;
    while(l<r)
    {
        mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
        //        cout<<l<<" "<<r<<endl;
    }
    cout<<n-l<<endl;
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