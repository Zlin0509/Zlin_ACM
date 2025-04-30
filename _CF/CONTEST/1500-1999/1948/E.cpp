#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;
    cin>>n>>k;

    int ans[55]{};
    for(int i=1;i<=n;i+=k)
    {
        int l=i,r=min(i+k-1,n),num=min(i+k-1,n);
        int mid=l+r >> 1;
        for(int q=mid+1;q<=r;q++)
        {
            ans[q]=num--;
        }
        for(int q=l;q<=mid;q++)
        {
            ans[q]=num--;
        }
    }

    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<'\n';

    //第二行输出
    cout<<(n-1)/k+1<<'\n';

    //第三行输出
    for(int i=0;i<n;i++)
    {
        cout<<i/k+1<<" ";
    }
    cout<<'\n';
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