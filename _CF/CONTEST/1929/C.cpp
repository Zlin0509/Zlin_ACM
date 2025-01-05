#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long k,x,a,all=1;
    cin>>k>>x>>a;
    for(int i=1,p;i<=x;i++)
    {
        all+=all/(k-1)+1;
        if(all>a)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    all<=a?cout<<"YES"<<endl:cout<<"NO"<<endl;
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