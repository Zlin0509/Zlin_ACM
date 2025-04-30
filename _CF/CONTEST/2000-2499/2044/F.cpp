//
// Created by Zlin on 2024/12/15.
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

const int N = 2e5 + 10;

int n, m, q;
int a[N], b[N];
ll suma = 0, sumb = 0, sum;
unordered_map<ll, int> havea, haveb;

inline void Zlin() {
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) cin >> a[i], suma += a[i];
    for (int i = 1; i <= m; i++) cin >> b[i], sumb += b[i];

    sum = suma + sumb;
    for (int i = 1; i <= n; i++) havea[suma - a[i]] = 1;
    for (int i = 1; i <= m; i++) haveb[sumb - b[i]] = 1;
    while (q--) {
        int x;
        cin >> x;
        bool check = false;
        for (int i = 1, l, r; i <= sqrt(abs(x)); i++) {
            if (abs(x) % i) continue;
            l = i, r = x / i;
            if ((havea[l] && haveb[r]) || (havea[r] && haveb[l])) {
                check = true;
                break;
            }
            if ((havea[-l] && haveb[-r]) || (havea[-r] && haveb[-l])) {
                check = true;
                break;
            }
        }
        cout << (check ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    // cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
