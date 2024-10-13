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


inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vi cnt(m + 1);
    vector<vi> a(n + 1);
    for (int i = 1, x; i <= n; i++) {
        cin >> x;
        for (int j = 1, y; j <= x; j++) {
            cin >> y;
            ++cnt[y];
            a[i].push_back(y);
        }
    }
    set<int> b[n + 1];
    for (int i = 1; i <= n; i++)
        for (auto j: a[i])
            if (cnt[j] >= 2)
                b[i].insert(j);
    int tag = 0;
    for (int i = 1; i < n; i++) {
        bool check = true;
        for (auto j: b[i]) {
            --cnt[j];
            if (cnt[j] == 1 && b[i + 1].find(j) != b[i + 1].end())
                check = false;
        }
        if (check) {
            tag = i;
            break;
        }
    }
    if (!tag) {
        cout << "No" << '\n';
        return;
    } else {
        cout << "Yes" << '\n';
        for (int i = 1; i <= n; i++) {
            if (i == tag) {
                cout << i + 1 << ' ' << i << ' ';
                i++;
            } else {
                cout << i << ' ';
            }
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}