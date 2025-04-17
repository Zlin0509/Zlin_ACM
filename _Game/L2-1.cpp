//
// Created by Zlin on 2025/1/16.
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
    int n, m, s;
    cin >> n >> m >> s;
    vector<string> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        reverse(a[i].begin(), a[i].end());
    }
    int x;
    stack<char> now;
    string ans;
    while (1) {
        cin >> x;
        if (x == -1) break;
        if (x == 0) {
            if (!now.empty()) {
                ans += now.top();
                now.pop();
            }
        } else {
            if (a[x].empty()) continue;
            if (now.size() == s) {
                ans += now.top();
                now.pop();
            }
            now.push(a[x].back());
            a[x].pop_back();
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
