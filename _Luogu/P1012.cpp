#include<bits/stdc++.h>
using namespace std;

bool cmp(const string &x,const string &y)
{
    for(int i=0;i<min(x.length(),y.length());i++)
    {
        if(x[i]!=y[i])
        {
            return x[i]>y[i];
        }
    }
    if(x.length()>y.length())
    {
        for(int i=y.length();i<x.length();i++)
        {
            if(x[i]!=y[0])
            {
                return x[i]>y[0];
            }
        }
    }
    if(x.length()<y.length())
    {
        for(int i=x.length();i<y.length();i++)
        {
            if(x[0]!=y[i])
            {
                return x[0]>y[i];
            }
        }
    }
    return x.length()>y.length();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    string a[22]{};
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) cout<<a[i];
}