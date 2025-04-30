#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    long long m1,m2,as=1;
    long long a;
    for(int i=0;i<n;i++){
        as=1;
        cin>>m1>>m2;
        for(int j=0;j<m1;j++){
            cin>>a;
            as*=a;
        };
        if(2023%as!=0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            cout<<2023/as;
            for(int j=0;j<m2-1;j++){
                cout<<" 1";
            }
            cout<<endl;
        }
    }
}