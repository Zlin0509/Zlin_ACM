//
// Created by Zlin on 2024/10/13.
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
    if(n1.a==n2.a) return n1.b<n2.b;
    return n1.a<n2.a;
}
inline void Zlin() {
    ll n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>s[i].a>>s[i].b;
    }
    sort(s+1,s+m+1,cmp);
    ll tot=0;
    s[0].a=0;
    s[0].b=0;
    for(int i=1;i<=m;i++){
        if(s[i].b>s[i].a)
        {
            cout<<"No"<<"\n";
            return;
        }
        else
        {
            if(s[i].a-s[i-1].a!=s[i].b-s[i-1].b)
            {
                if(s[i].a-s[i-1].a>=s[i].b+1)
                    continue;
                else
                {
                    cout<<"No"<<"\n";
                    return;
                }
            }
        }
    }
    cout<<"Yes"<<"\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}