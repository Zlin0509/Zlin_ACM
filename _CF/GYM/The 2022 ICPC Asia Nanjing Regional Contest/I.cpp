//
// Created by Zlin on 2024/10/19.
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
    string x;
    cin >> x;
    int ans = 0;
    vi cnt(26);
    for (int i = 0; i < x.length(); i++) {
        ++cnt[x[i] - 'a'];
        ans = max(ans, cnt[x[i] - 'a']);
    }
    cout << x.length() - ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}