#include<bits/stdc++.h>
using namespace std;

int n;
long long ans=0,x;
priority_queue<int,vector<int>,greater<int>>a;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        a.push(x);
    }
    while(a.size()!=1)
    {
        x=0;
        x+=a.top();
        a.pop();
        x+=a.top();
        a.pop();
        ans+=x;
        a.push(x);
    }
    cout<<ans<<'\n';
}