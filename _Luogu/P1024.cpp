#include<bits/stdc++.h>
using namespace std;

int check=0;
int a,b,c,d;

void search(double l,double r)
{
    if(check==3||r-l<1)
    {
        return;
    }
    double mid=(l+r)/2.00;
    double n1,n2,n3;
    n1=a*pow(l,3)+b*(l,2)+c*l+d;
    n2=a*pow(mid,3)+b*pow(mid,2)+c*mid+d;
    n3=a*pow(r,3)+b*pow(r,2)+c*r+d;
    if(abs(n1)<=0.05)
    {
        printf("%.02lf ",l);
        ++check;
    }
    if(n1*n2<0)
    {
        search(l,mid);
    }
    if(abs(n2)<=0.05)
    {
        printf("%.02lf ",mid);
        ++check;
    }
    if(n2*n3<0)
    {
        search(mid,r);
    }
    if(abs(n3)<=0.05)
    {
        printf("%.02lf ",r);
        ++check;
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin>>a>>b>>c>>d;
    search(-100.0,100.0);
}