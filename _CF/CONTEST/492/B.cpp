#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    double m,a[1010]{};
    cin>>n>>m;
    int c1=0,c2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==0) c1=1;
        if(a[i]==m) c2=1;
    }
    sort(a,a+n);
    double M=0;
    if(c1==0) M=a[0];
    if(c2==0) M=max(M,m-a[n-1]);
    for(int i=0;i<n-1;i++){
        if((a[i+1]-a[i])/2>M) M=(a[i+1]-a[i])/2;
    }
    printf("%.10lf", M);
}