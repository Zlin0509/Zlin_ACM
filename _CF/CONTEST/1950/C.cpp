#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a,b;
    char x;
    cin>>a>>x>>b;
    if(a>12)
    {
        a%=12;
        printf("%02d:%02d PM\n",a,b);
    }
    else if(a==12)
    {
        printf("%02d:%02d PM\n",a,b);
    }
    else
    {
        if(a==0) a+=12;
        printf("%02d:%02d AM\n",a,b);
    }
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