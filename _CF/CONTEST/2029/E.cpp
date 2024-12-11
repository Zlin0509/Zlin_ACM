//
// Created by Zlin on 2024/12/10.
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

const int N = 1e5 + 5;
int n;
unordered_map<int, bool> have;
vi a, s{2, 3, 5, 6, 7};

bool check(int x) {
    if (x == 2) {
        if (have[3] || have[5] || have[7]) return false;
    } else if (x == 3) {
        if (have[4] || have[5] || have[7]) return false;
    } else if (x == 5) {
        if (have[6] || have[7] || have[8] || have[9] || have[11] || have[13]) return false;
    } else if (x == 6) {
        if (have[7]) return false;
    } else if (x == 7) {
        for (int i = 8; i <= 13; i++) if (have[i]) return false;
        if (have[15] || have[17] || have[19]) return false;
    }
    return true;
}

inline void Zlin() {
    cin >> n;
    a.clear();
    have.clear();
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        if (x <= 7) a.push_back(x);
        if (x <= 20) have[x] = true;
    }
    sort(a.begin(), a.end());
    int ans = -1;
    if (!a.empty()) {
        for (auto i: s) {
            if (i > *a.begin()) break;
            if (check(i)) {
                ans = i;
                break;
            }
        }
    } else ans = 2;
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