#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull =unsigned long long;
const int N=1e6+5;
const int M=1e6+5;
const ll inf=1e18;
const ll mod=1e9+7;
ll n,a[20],b[20],c[20];
void solve(){
    ll res=0;
    for(int i=1;i<=13;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+13);
    ll sum=0,sumc=0;
    for(int i=1;i<=13;i++){
        c[i]=a[i]%3;
        b[i]=a[i]-c[i];
        sum+=b[i];
        sumc+=c[i];
    }
    for(int i=13;i>=1;i--){
        if(b[i]>=(sumc-c[i])*3){
            ll ans = sumc - c[i];
            sum-=b[i];
            b[i]-=ans*3;
            ll zz=0;
            for(int j=0;j<=c[i];j++){
                ll res=j;
                ll yy=0;
                if(b[i]>=sum*3){
                    yy=sum;
                }else{
                    yy=(sum+b[i])/4;
                }
                zz=max(zz,yy+res);
                if(sum>=3)sum-=3;
                else break;
            }
            cout << ans+zz << "\n";
            return;
        }
    }
    ll xx=min(sum/3,sumc);
    ll yy=(sum-xx*3)/4;
    cout << xx+yy << "\n";
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _=1;  cin >> _;
    while(_--) solve();
    return 0;
}