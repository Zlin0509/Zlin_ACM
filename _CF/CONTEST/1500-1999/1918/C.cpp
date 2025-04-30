#include<bits/stdc++.h>
using namespace std;

inline long long lg(long long x) {return 63ll^ __builtin_clzll(x);}

void solve()
{
    long long a,b,r,ans=0;
    cin>>a>>b>>r;
    if(a==b){
        cout<<"0"<<endl;
        return;
    }
    //    if(b> a) a^=b^=a^=b;
    if(a<b) swap(a,b);
    //    cout<<i<<endl;
    for(int i=min(lg(a^b)-1,lg(r));i>=0;i--)
    {
        if((a&(1ll<<i))==(b&(1ll<<i))) continue;
        if((a&(1ll<<i))&&(ans+(1ll<<i)<=r))
        {
            a^=(1ll<<i);
            b^=(1ll<<i);
            ans+=(1ll<<i);
        }
    }
    //    cout<<a<<" "<<b<<endl;
    cout<<a-b<<endl;
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