#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,as=0,num=0;
    set<int>a;
    cin>>n;
    for (size_t i = 0,x; i < n; i++)
    {
        cin>>x;
        a.insert(x);
    }
    auto l=a.begin();
    for (auto i = a.begin(); i != a.end(); i++)
    {
        while(*i-*l>=n)
        {
            --num;
            ++l;
        }
        if(*i-*l<n) ++num;
        as=max(as,num);
    }
    cout<<as<<endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
}