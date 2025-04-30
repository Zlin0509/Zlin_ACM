#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    char ch;
    string s;
    cin>>ch;
    while(ch!='E')
    {
        if(ch!='\n') s+=ch;
        cin>>ch;
    }

    if(s.length()==0)
    {
        cout<<"0:0"<<'\n';
        cout<<'\n';
        cout<<"0:0"<<'\n';
        return 0;
    }

    int check=11,n1=0,n2=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='W') ++n1;
        else ++n2;

        if(abs(n1-n2)>=2)
        {
            if(n1>=check||n2>=check)
            {
                cout<<n1<<":"<<n2<<'\n';
                n1=0;n2=0;
            }
        }
    }
    cout<<n1<<":"<<n2<<'\n';
    n1=0;n2=0;
    cout<<'\n';
    check=21;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='W') ++n1;
        else ++n2;

        if(abs(n1-n2)>=2)
        {
            if(n1>=check||n2>=check)
            {
                cout<<n1<<":"<<n2<<'\n';
                n1=0;n2=0;
            }
        }
    }
    cout<<n1<<":"<<n2<<'\n';
    n1=0;n2=0;
}