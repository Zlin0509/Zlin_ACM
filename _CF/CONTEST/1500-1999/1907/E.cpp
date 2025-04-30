#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin>>n;
    long long ans=1;
    vector<int>a,b;
    while(n>0)
    {
        a.push_back(n%10);
        n/=10;
    }
    for(int i=0;i<a.size();i++)
    {
        // cout<<a[i]<<endl;
        int num=0;
        //暴力求组合;
        for(int i1=0;i1<=9;i1++)
        {
            for(int i2=i1;i2<=9;i2++)
            {
                for(int i3=i2;i3<=9;i3++)
                {
                    if(i1+i2+i3==a[i])
                    {
                        if(i1==i2&&i2==i3)
                        {
                            ++num;
                        }
                        else if(i1==i2||i1==i3||i2==i3)
                        {
                            num+=3;
                        }
                        else num+=6;
                    }
                }
            }
        }
        b.push_back(num);
    }
    for(int i=0;i<b.size();i++)
    {
        // cout<<b[i]<<endl;
        ans*=b[i];
    }
    cout<<ans<<endl;
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