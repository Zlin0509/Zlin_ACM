//
// Created by 27682 on 2025/9/5.
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

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    for (int &it: a) cin >> it;
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    queue<int> q;
    for (int it: a) q.emplace(it);
    int cnt = 0, kk = k * 2 + 1;
    vi have;
    while (kk) {
        if (!q.empty() && q.front() == cnt) q.pop();
        else {
            have.emplace_back(cnt);
            kk--;
        }
        ++cnt;
    }
    int c1 = 0, c2 = 0, check = -1;
    for (int it: have) {
        if (it & 1) {
            if (c1 < k) ++c1;
            else {
                check = 0;
                break;
            }
        } else {
            if (c2 < k) ++c2;
            else {
                check = 1;
                break;
            }
        }
    }
    cout << (check ? "Alice" : "Bob") << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
