#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull =unsigned long long;
const int N=2e5+5;
const int M=1e6+5;
const ll inf=2e9;
const ll mod=998244353;
ll n,x,y;
ll lowbit(ll x){
    return x&-x;
}
void solve(){
    cin >> n >> x >> y;
    if(x==y){
        cout << "0\n";
    }else if(__builtin_popcountll(x)==__builtin_popcount(y)||lowbit(x)==lowbit(y)){
        cout << "1\n";
    }else{
        cout << "2\n";
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int _=1;  cin >> _;
    while(_--) solve();
    return 0;
}