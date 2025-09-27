//
// Created by 27682 on 2025/9/27.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

constexpr int N = 1e5 + 10;

const char cx[3]{'C', 'P', 'J'};

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (k) {
        cout << (n & 1) << endl;
        return;
    }
    s = ' ' + s;
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    auto it = st.begin();
    while (it != st.end() && next(it) != st.end()) {
        auto nxt = next(it);
        if (s[*it] == s[*nxt]) {
            if (it != st.begin()) {
                auto pre = prev(it);
                st.erase(it), st.erase(nxt);
                it = pre;
            } else st.erase(it), it = st.erase(nxt);
        } else it = nxt;
    }
    cout << st.size() << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
