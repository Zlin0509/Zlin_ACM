#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    int ans=32-__builtin_clz(n)-1;
    cout<<(1<<ans)<<endl;
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