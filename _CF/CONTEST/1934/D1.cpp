#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n,m;
    cin>>n>>m;
    int l1=64-__builtin_clzll(n)-1;
    int l2=64-__builtin_clzll(m)-1;
    if(l1==l2)
    {
        cout<<"1"<<endl;
        cout<<n<<" "<<m<<endl;
        return;
    }
    long long N=n-(1ll<<l1);
    if(N==0)
    {
        cout<<"-1"<<endl;
        return;
    }
    l1=64-__builtin_clzll(N);
    --l1;
    if(l1<l2)
    {
        cout<<"-1"<<endl;
        return;
    }
    if(l1==l2)
    {
        cout<<"1"<<endl;
        cout<<n<<" "<<m<<endl;
        return;
    }
    long long ans=(1ll<<l1)+m;
    cout<<"2"<<endl;
    cout<<n<<" "<<ans<<" "<<m<<endl;
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