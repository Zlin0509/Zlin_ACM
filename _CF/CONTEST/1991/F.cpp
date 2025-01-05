//
// Created by Zlin on 2024/9/13.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, q, l, r;
    cin >> n >> q;
    vi a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        cin >> l >> r;
        if (r - l + 1 >= 48) {
            cout << "YES" << '\n';
        } else {
            vi b(r - l + 1);
            int ll = -1, rr = -1;
            for (int i = 0; i <= r - l; i++)
                b[i] = a[l + i];
            sort(b.begin(), b.end());
            for (int i = 0; i <= r - l - 2; i++)
                if (b[i] + b[i + 1] > b[i + 2]) {
                    if (ll == -1) ll = i;
                    else rr = i;
                }
            if (ll + 2 < rr) {
                cout << "YES" << '\n';
            } else {
                bool check = false;
                for (int i = 0; i < (b.size() > 5 ? b.size() - 5 : 0); i++) {
                    vector<int> c(b.begin() + i, b.begin() + i + 6);
                    for (int j = 1; j < 5; j++) {
                        for (int k = j + 1; k < 6; k++) {
                            if (c[0] + c[j] > c[k]) {
                                vector<int> v;
                                for (int l = 1; l < 6; l++)
                                    if (l != j && l != k)
                                        v.emplace_back(c[l]);
                                if (v[0] + v[1] > v[2]) check = true;
                            }
                        }
                    }
                }
                cout << (check ? "YES" : "NO") << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Zlin();
}