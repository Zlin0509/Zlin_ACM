#include<bits/stdc++.h>
using namespace std;

set<int>ans;
int a[31]={10,11,111,110,101,100,1111,1110,1101,1011,1100,1010,1001,1000,11111,11110,11101,11011,10111,11100,11010,10110,11001,10101,10011,11000,10100,10010,10001,10000,100000};

void dfs(int x)
{
    if(x>1e5) return;
    ans.insert(x);
    for(int i=0;i<31;i++)
    {
        dfs(x*a[i]);
    }
}

void solve()
{
    int n;
    cin>>n;
    if(ans.find(n)!=ans.end()) cout<<"YES"<<'\n';
    else cout<<"NO"<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    dfs(1);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    // for(auto it:ans)
    // {
    //     cout<<it<<" ";
    // }
}