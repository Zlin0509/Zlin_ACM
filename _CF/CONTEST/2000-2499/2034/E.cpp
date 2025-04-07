//
// Created by 27682 on 2025/3/31.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll fac[20];

inline void Zlin() {
    int n, k;
    cin >> n >> k;
    if (k == 1) {
        if (n == 1) {
            cout << "YES" << endl << 1 << endl;
        } else {
            cout << "NO" << endl;
        }
        return;
    }
    if (n <= 10 && fac[n] < k) {
        cout << "NO" << endl;
        return;
    }
    vector<vi> ans, used;
    vi now;
    if (k & 1) {
        if (n % 2 == 0) {
            cout << "NO" << endl;
            return;
        }
        if (n <= 10 && fac[n] - 3 < k) {
            cout << "NO" << endl;
            return;
        }
        int x = n / 2;

        for (int i = 1; i <= n; i++)
            now.push_back(i);
        ans.push_back(now);
        used.push_back(now);
        reverse(now.begin(), now.end());
        used.push_back(now);
        now.clear();

        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                now.push_back(x + 1 - i / 2);
            } else {
                now.push_back(2 * x + 2 - i / 2);
            }
        }
        ans.push_back(now);
        used.push_back(now);
        reverse(now.begin(), now.end());
        used.push_back(now);
        now.clear();

        for (int i = 1; i <= n; i++) {
            if (i & 1) {
                now.push_back(2 * x + 1 - i / 2);
            } else {
                now.push_back(x + 1 - i / 2);
            }
        }
        ans.push_back(now);
        used.push_back(now);
        reverse(now.begin(), now.end());
        used.push_back(now);
        now.clear();

        k -= 3;
    }
    for (int i = 1; i <= n; i++)
        now.push_back(i);
    while (k) {
        bool check = true;
        for (vi &it: used) {
            if (it == now) {
                check = false;
                break;
            }
        }
        if (!check) {
            next_permutation(now.begin(), now.end());
            continue;
        }
        ans.push_back(now);
        ans.push_back(vi());
        for (int it: now)
            ans.back().push_back(n + 1 - it);
        next_permutation(now.begin(), now.end());
        k -= 2;
    }

    cout << "YES" << endl;
    for (vi &it: ans) {
        for (int i: it)
            cout << i << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    fac[0] = 1;
    for (int i = 1; i <= 10; i++)
        fac[i] = fac[i - 1] * i;
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
