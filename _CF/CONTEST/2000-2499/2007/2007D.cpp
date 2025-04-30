//
// Created by Zlin on 2024/9/19.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

int n;
int d[100010]{}, c[100010]{};

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) d[i] = 0, c[i] = -1;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        d[x]++;
        d[y]++;
    }
    int cnt = 0, c1 = 0, c2 = 0, tot = 0;
    c[1] = -1;
    string x;
    cin >> x;
    x = ' ' + x;
    for (int i = 1; i <= n; i++) {
        if (x[i] == '?') {
            ++tot;
            if (i != 1 && d[i] == 1) ++cnt;
        } else {
            c[i] = x[i] - '0';
            if (i != 1 && d[i] == 1)
                c[i] ? ++c1 : ++c2;
        }
    }
    int ans, check;
    if (c[1] == -1) {
        ans = max(c1, c2);
        if (cnt) ans += (cnt - 1) / 2 + (cnt - 1) % 2;
        if ((tot - cnt - 1) & 1) {
            check = min(c1, c2);
            if (cnt) check += cnt / 2 + cnt % 2;
            ans = max(ans, check);
        }
    } else {
        c[1] ? ans = c2 : ans = c1;
        if (cnt) ans += cnt / 2 + cnt % 2;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}