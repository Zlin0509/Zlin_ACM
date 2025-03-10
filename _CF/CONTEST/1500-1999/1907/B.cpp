#include<bits/stdc++.h>
using namespace std;

void solve()
{
    char x[1000010]{},s[1000010]{};
    cin>>x;
    stack<int>B,b;
    int len=0;
    while(x[len]!='\0')
    {
        if(x[len]=='b')
        {
            s[len]='0';
            if(!b.empty())
            {
                s[b.top()]='0';
                b.pop();
            }
        }
        else if(x[len]=='B')
        {
            s[len]='0';
            if(!B.empty())
            {
                s[B.top()]='0';
                B.pop();
            }
        }
        else
        {
            s[len]=x[len];
            if(s[len]>='A'&&s[len]<='Z') B.push(len);
            else b.push(len);
        }
        ++len;
    }
    for(int i=0;i<len;i++)
    {
        if(s[i]!='0')
            cout<<s[i];
    }
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