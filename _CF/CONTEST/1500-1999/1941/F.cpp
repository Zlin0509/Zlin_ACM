#include<bits/extc++.h>
using namespace std;
namespace pbds=__gnu_pbds;
using ui=unsigned int;
using uli=unsigned long long int;
using li=long long int;
int main(void){
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    size_t T;
    cin>>T;
    while (T--){
        size_t n,m,k;cin>>n>>m>>k;
        vector<ui> a(n),d(m),f(k);
        for (ui& i:a) cin>>i;
        for (ui& i:d) cin>>i;
        for (ui& i:f) cin>>i;
        sort(a.begin(),a.end()),sort(d.begin(),d.end()),sort(f.begin(),f.end());
        ui l=0,r=2e9+1;
        auto check=[&](ui mid){
            bool flag=false;
            for (size_t i=1;i<n;++i) if (a[i]-a[i-1]>mid){
                if (flag) return false;
                flag=true;
                for (ui j:d){
                    vector<ui>::const_iterator it=a[i]-mid>=j?lower_bound(f.cbegin(),f.cend(),a[i]-mid-j):f.cbegin(),
                                               jt=a[i-1]+mid>=j?upper_bound(f.cbegin(),f.cend(),a[i-1]+mid-j):f.cbegin();
                    if (it<jt) goto getit;
                }
                return false;
                getit:;
            }
            return true;
        };
        while (l<r){
            ui mid=(l+r)/2;
            check(mid)?r=mid:l=mid+1;
        }
        cout<<l<<'\n';
    }
    return 0;
}