#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=26;i++)
    {
        for(int j=1;j<=26;j++)
        {
            for(int q=1;q<=26;q++)
            {
                if(i+j+q==n)
                {
                    cout<<char('a'-1+i)<<char('a'-1+j)<<char('a'-1+q)<<endl;
                    return;
                }
            }
        }
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