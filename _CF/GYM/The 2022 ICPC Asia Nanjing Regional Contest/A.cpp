//
// Created by Zlin on 2024/10/19.
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

const int dif = 2010;
int n, m, k, lx, rx, ly, ry;
int sum[5020][5020];

inline void Zlin() {
    cin >> n >> m >> k;
    string s;
    cin >> s;
    int x, y, ans = 0, now = n * m;
    lx = ly = 1, rx = m, ry = n;
    for (auto it: s) {
        if (it == 'U') {
            ly++;
            ry++;
        } else if (it == 'D') {
            ry--;
            ly--;
        } else if (it == 'L') {
            rx--;
            lx--;
        } else {
            lx++;
            rx++;
        }
        if (ry < 1 || rx < 1 || ly > n || lx > m) {
            now = 0;
            break;
        }
        lx = max(lx, 1), lx = min(lx, m);
        rx = max(rx, 1), rx = min(rx, m);
        ly = max(ly, 1), ly = min(ly, n);
        ry = max(ry, 1), ry = min(ry, n);
    }
    if (now)
        now = (rx - lx + 1) * (ry - ly + 1) * 1ll;

    if (now - k < 0) {
        cout << 0 << '\n';
        return;
    } else if (!now && !k) {
        cout << n * m << '\n';
        return;
    } else {
        now -= k;
    }

//    cout << lx << ' ' << ly << ' ' << rx << ' ' << ry << '\n';
    x = 0, y = 0;
    sum[dif][dif] = 1;
    for (auto it: s) {
        if (it == 'U') {
            ly--;
            ry--;
            y--;
        } else if (it == 'D') {
            ly++;
            ry++;
            y++;
        } else if (it == 'L') {
            lx++;
            rx++;
            x++;
        } else {
            lx--;
            rx--;
            x--;
        }
        if (x < -m || x > m || y < -n || y > n) continue;
        sum[y + dif][x + dif] = 1;
    }

//    for (int i = dif - n; i <= dif + n; i++) {
//        for (int j = dif - m; j <= dif + m; j++) {
//            cout << sum[i][j] << ' ';
//        }
//        cout << '\n';
//    }

    for (int i = dif - m * 2; i <= dif + m * 2; i++)
        for (int j = dif - n * 2; j <= dif + n * 2; j++)
            sum[j][i] += sum[j - 1][i] + sum[j][i - 1] - sum[j - 1][i - 1];
    if (now < 0) {
        ans = 0;
    } else {
        int ax, ay, bx, by, check;
        for (y = 1; y <= n; y++) {
            for (x = 1; x <= m; x++) {
                ax = rx + dif - x, ay = ry + dif - y;
                bx = lx + dif - x, by = ly + dif - y;
                check = sum[ay][ax] - sum[by - 1][ax] - sum[ay][bx - 1] + sum[by - 1][bx - 1];
                if (check == now)++ans;
//                cout << check << ' ';
            }
//            cout << '\n';
        }
    }
//    for (int i = dif - n; i < dif + n; i++) {
//        for (int j = dif - m; j < dif + m; j++) {
//            cout << sum[i][j] << ' ';
//        }
//        cout << '\n';
//    }
    cout << ans << '\n';

    for (int i = dif - n * 2; i <= dif + n * 2; i++)
        for (int j = dif - m * 2; j <= dif + m * 2; j++)
            sum[i][j] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}