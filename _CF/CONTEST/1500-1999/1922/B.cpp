#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[300010];
map<int,int> mp;
set<int> st;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        mp.clear();
        st.clear();
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i],mp[a[i]]++,st.insert(a[i]);
        int tp=0;
        for(auto i:st)
        {
            if(mp[i]<2)
            {
                tp+=mp[i];
                continue;
            }
            if(mp[i]==2) ans+=mp[i]*(mp[i]-1)/2*tp;
            else ans+=mp[i]*(mp[i]-1)/2*tp+mp[i]*(mp[i]-1)*(mp[i]-2)/6;
            tp+=mp[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}