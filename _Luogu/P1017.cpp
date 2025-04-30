#include<bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n,base;
    cin>>n>>base;
    int len=0;
    int a[110]{};
    a[0]=n;
    int j=0;
    while(j<=len)
    {
        if(a[j]>1)
        {
            len+=2;
            
        }
        ++j;
    }
}