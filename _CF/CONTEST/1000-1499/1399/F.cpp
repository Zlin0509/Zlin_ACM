//
// Created by 27682 on 2025/6/25.
//
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 3e3 + 10;

int n;
pii line[N];

inline void Zlin() {
    cin >> n;
    vi idx;
    for (int i = 1; i <= n; i++) {
        cin >> line[i].first >> line[i].second;
        idx.push_back(line[i].first);
        idx.push_back(line[i].second);
    }
    idx.push_back(0), idx.push_back(2e5 + 1);
    sort(idx.begin(), idx.end());
    idx.erase(unique(idx.begin(), idx.end()), idx.end());
    for (int i = 1; i <= n; i++) {
        line[i].first = lower_bound(idx.begin(), idx.end(), line[i].first) - idx.begin();
        line[i].second = lower_bound(idx.begin(), idx.end(), line[i].second) - idx.begin();
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
