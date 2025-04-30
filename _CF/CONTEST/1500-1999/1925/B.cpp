#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int x,t;
    cin>>x>>t;
    int as=1;
    for(int i=1;i<=sqrt(x);i++)
    {
        if(x%i==0&&x/i>=t) as=max(as,i);
        if(x%i==0&&i>=t) as=max(as,x/i);
    }
    cout<<as<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}