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
    int n, m, k;
    cin >> n >> m >> k;
    vector<vi> ans;
    stack<int> have;
    vi now;
    for (int i = 1, x; i <= n; i++) {
        while (!have.empty() && (now.empty() || now.back() >= have.top())) {
            now.push_back(have.top());
            if (now.size() == k) {
                ans.push_back(now);
                now.clear();
            }
            have.pop();
        }
        cin >> x;
        if (now.empty() || now.back() >= x) {
            now.push_back(x);
            if (now.size() == k) {
                ans.push_back(now);
                now.clear();
            }
        } else {
            if (have.size() == m) {
                ans.push_back(now);
                now.clear();
                while (!have.empty() && (now.empty() || now.back() >= have.top())) {
                    now.push_back(have.top());
                    if (now.size() == k) {
                        ans.push_back(now);
                        now.clear();
                    }
                    have.pop();
                }
            }
            have.push(x);
        }
    }
    if (now.size()) {
        ans.push_back(now);
        now.clear();
    }
    while (!have.empty()) {
        while (!have.empty() && (now.empty() || now.back() >= have.top())) {
            now.push_back(have.top());
            if (now.size() == k) {
                ans.push_back(now);
                now.clear();
            }
            have.pop();
        }
        if (now.size()) {
            ans.push_back(now);
            now.clear();
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
            if (j != ans[i].size() - 1) cout << " ";
        }
        if (i != ans.size() - 1) cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}
