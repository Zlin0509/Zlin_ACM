#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k,m;
    cin>>n>>k>>m;
    string s,ans;
    cin>>s;
    set<char>a;
    int num=0;
    for(int i=0;i<m;i++)
    {
        a.insert(s[i]);
        if(a.size()==k)
        {
            ++num;
            a.clear();
            ans+=s[i];
        }
        if(num==n)
        {
            cout<<"YES"<<endl;
            return;
        }
    }

    cout<<"NO"<<endl;
    cout<<ans;
    for(char i='a';i<'a'+k;i++)
    {
        if(a.find(i)==a.end())
        {
            for(int j=num;j<n;j++) cout<<i;
            cout<<endl;
            return;
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