#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int a;
    map<char,int>b{};
    cin>>n;
    for(int i=0;i<n;i++)
    {
        char x='a';
        cin>>a;
        while(b[x]!=a)
        {
            ++x;
        }
        if(b[x]==a)
        {
            cout<<x;
            ++b[x];
        }
    }
    cout<<endl;
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