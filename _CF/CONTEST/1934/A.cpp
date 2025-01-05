#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    int a[200]{};
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    int as=a[n-1]*2-a[0]*2+a[n-2]*2-a[1]*2;
    cout<<as<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;
    while(T--){
        solve();
    }
}