#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    int a[55]{};
    int ans=0;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=10)
        {
            int x=a[i]/10,y=a[i]%10;
            if(x<=y&&x>=ans)
            {
                ans=y;
            }
            else
            {
                if(a[i]<ans)
                {
                    cout<<"NO"<<'\n';
                    return;
                }
                else ans = a[i];
            }
        }
        else
        {
            if(a[i]<ans)
            {
                cout<<"NO"<<'\n';
                return;
            }
            else ans = a[i];
        }
    }
    cout<<"YES"<<'\n';
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