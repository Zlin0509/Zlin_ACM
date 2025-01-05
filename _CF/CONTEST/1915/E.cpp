#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200010]{};
set<long long>b;
vector<long long>sum1,sum2;

void solve()
{
    cin>>n;
    b.clear();b.insert(0);
    //sum1放奇数，sum2放偶数;
    cin>>a[1];
    sum1.clear();sum2.clear();
    sum1.push_back(a[1]);
    sum2.push_back(a[0]);
    for(int i=2;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-2];
        if(i%2==0)
        {
            sum1.push_back(a[i-1]);
            sum2.push_back(a[i]);
        }
        else
        {
            sum1.push_back(a[i]);
            sum2.push_back(a[i-1]);
        }
    }
    for(int i=0;i<n;i++)
    {
        if(b.find(sum1[i]-sum2[i])!=b.end())
        {
            cout<<"YES"<<endl;
            return;
        }
        b.insert(sum1[i]-sum2[i]);
    }
    cout<<"NO"<<endl;
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