//
// Created by Zlin on 2024/12/15.
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
    string ans;
    for (auto it: x) {
        if (it == 'w') ans = 'w' + ans;
        else if (it == 'q') ans = 'p' + ans;
        else ans = 'q' + ans;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
