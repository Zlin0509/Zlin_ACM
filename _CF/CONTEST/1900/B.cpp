#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    (n2+n3)%2==0?cout<<"1":cout<<"0";
    cout<<" ";
    (n1+n3)%2==0?cout<<"1":cout<<"0";
    cout<<" ";
    (n2+n1)%2==0?cout<<"1":cout<<"0";
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