//
// Created by 27682 on 2025/4/16.
//

#include "bits/stdc++.h"
// #define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int x;
    cin >> x;
    int m = 1000;
    unordered_map<int, int> tag;
    int sum = 1, ans = 0;
    tag[x] = sum;
    for (int i = 1; i < m; i++) {
        cout << "+ " << 1 << endl;
        cin >> x;
        ++sum;
        if (!tag[x])
            tag[x] = sum;
        else {
            ans = sum - tag[x];
            cout << "! " << ans << endl;
        }
    }
    while (1) {
        cout << "+ " << m << endl;
        cin >> x;
        sum += m;
        if (tag[x]) {
            ans = sum - tag[x];
            cout << "! " << ans << endl;
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
