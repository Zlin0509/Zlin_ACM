//
// Created by Zlin on 2025/5/1.
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
    int n;
    cin >> n;
    vi a(n * 2 + 1);
    for (int i = 1; i <= n << 1; i++) {
        char c;
        cin >> c;
        a[i] = c - '0';
    }
    vi r;
    int cnt = 1;
    for (int i = 2; i <= n << 1; i++) {
        if (a[i] != a[i - 1]) {
            r.push_back(cnt);
            cnt = 0;
        }
        ++cnt;
    }
    r.push_back(cnt);
    cnt = 0;
    int tag = -1, tot = 0;
    vi op;
    for (int i = 0; i + 1 < r.size(); i++) {
        if (r[i] & 1) {
            if (tot & 1) {
                if (a[cnt + r[i]] == tag) {
                    op.push_back(cnt + r[i]);
                    --r[i];
                    ++r[i + 1];
                } else {
                    op.push_back(cnt + r[i] + 1);
                    ++r[i];
                    --r[i + 1];
                }
            } else {
                if (tag == -1) {
                    tag = a[cnt + r[i]];
                    op.push_back(cnt + r[i] + 1);
                    ++r[i];
                    --r[i + 1];
                } else if (a[cnt + r[i]] == tag) {
                    op.push_back(cnt + r[i] + 1);
                    ++r[i];
                    --r[i + 1];
                } else {
                    op.push_back(cnt + r[i]);
                    --r[i];
                    ++r[i + 1];
                }
            }
            ++tot;
        }
        cnt += r[i];
    }
    if (r.back() & 1 || tot & 1) {
        cout << -1 << endl;
        return;
    }
    cout << op.size() << ' ';
    for (int it: op) cout << it << ' ';
    cout << endl;
    for (int i = 1; i <= n << 1; i += 2) cout << i << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
