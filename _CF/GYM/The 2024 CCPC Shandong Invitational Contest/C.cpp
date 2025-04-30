//
// Created by Zlin on 2024/10/7.
//

#include "bits/stdc++.h"

using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

struct ffa{
    ll a;
    ll b;
}s[500005];
bool cmp(ffa n1,ffa n2){
    if(n1.b==n2.b) return n1.a<n2.a;
    return n1.b<n2.b;
}
ll mod=998244353;
ll cnt[500005];
inline void Zlin() {
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].b;
        cnt[i]=0;
    }
    sort(s+1,s+n+1,cmp);
    for(int i=2;i<=n;i++){
        ll l=1,r=i-1;
        while(l<=r){
            ll mid=(l+r)/2;
            if(s[mid].b>=s[i].a){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        cnt[l]++;
        cnt[i]--;
    }
    for(int i=2;i<=n;i++){
        cnt[i]+=cnt[i-1];
    }
    ll tot=max((ll)1,k-cnt[1]);
    for(int i=2;i<=n;i++){
        if(k-cnt[i]<=0){
            tot=0;
            break;
        }
        tot=tot*max((ll)1,k-cnt[i])%mod;
    }
    cout<<tot<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}