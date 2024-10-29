//
// Created by Zlin on 2024/10/24.
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

inline void Zlin() {
    double p,q;
    cin>>p>>q;
    if(sqrt(p+2*q)==(int)sqrt(p+2*q))
    {
        int k=(int) sqrt(p+2*q);
        cout<<1<<" "<<k-1<<endl;
    }
    else
    {
        cout<<0<<" "<<0<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    //int ttt = 1;
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}