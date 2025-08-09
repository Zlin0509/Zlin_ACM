//
// Created by Zlin on 2025/8/8.
//

#include "bits/stdc++.h"
#include "iostream"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int base = 2;

int cnt[366];

inline void Zlin() {
    int k, L, R;
    cin >> k >> L >> R;
    set<int> st;
    int tag = base, time = 2025;
    while (time < L) {
        if (time % 4 == 0 && time % 100 != 0) {
            tag = (tag + 2) % 7;
        } else {
            tag = (tag + 1) % 7;
        }
        ++time;
    }
    while (time <= R) {
        if (time % 4 == 0 && time % 100 != 0) {
            for (int i = 0; i < 366; i++) {
                if (tag == 5 || tag == 6) ++cnt[i];
                tag = (tag + 1) % 7;
            }
        } else {
            for (int i = 0; i < 366; i++) {
                if (i == 59) {
                    ++cnt[i];
                    continue;
                }
                if (tag == 5 || tag == 6) ++cnt[i];
                tag = (tag + 1) % 7;
            }
        }
        ++time;
    }
    priority_queue<int> pq;
    for (int i = 0; i < 366; i++) pq.emplace(cnt[i]), cnt[i] = 0;
    int ans = (R - L + 1) * k;
    while (k--) {
        ans -= pq.top();
        pq.pop();
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
