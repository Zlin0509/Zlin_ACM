#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int T;
    cin>>T;
    while(T--)
    {
        long long n;cin>>n;
        long long curr=n;
        int parity=0;
        if(__builtin_popcountll(n)%2){
            cout<<"second"<<endl;
        }else{
            cout<<"first"<<endl;
            parity=1;
        }
        int turn=0;
        while(1){
            if(turn%2==parity){
                long long p1,p2;cin>>p1>>p2;
                if (p1 == 0 && p2 == 0)
                    break;
                if(__builtin_popcountll(p1)%2==0){
                    curr=p1;
                }else{
                    curr=p2;
                }
            }else{
                int pos=0;
                for(int i=0;(1ll<<i)<curr;i++){
                    if(curr&(1ll<<i)){
                        pos=i;
                    }
                }
                long long p1=(1ll<<pos);
                long long p2=curr^p1;
                cout<<p1<<" "<<p2<<endl;
                curr = p1;
            }
            turn++;
        }
    }
}