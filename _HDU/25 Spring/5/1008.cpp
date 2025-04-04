//
// Created by Zlin on 2025/4/4.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int &it: a) cin >> it;
    if (n > 200) {
        cout << "YES" << endl;
        return;
    }
    sort(a.begin(), a.end());
    vi cnt(m + 1);
    for (int it: a) {
        ++cnt[it];
        if (cnt[it] > 1) {
            cout << "YES" << endl;
            return;
        }
    }
    unordered_map<int, vector<pii> > mp;
    bool check = false;
    for (int i = 0; i < n && !check; i++) {
        for (int j = i + 1; j < n && !check; j++) {
            int sum = a[i] + a[j];
            if (!mp[sum].empty()) {
                for (auto [x, y]: mp[sum]) {
                    if (x != i && x != j && y != i && y != j) {
                        check = true;
                        break;
                    }
                }
            }
            mp[sum].emplace_back(i, j);
        }
    }
    cout << (check ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
