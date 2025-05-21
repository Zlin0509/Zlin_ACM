//
// Created by 27682 on 2025/5/21.
//
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

typedef vector<int> vi;
typedef pair<int, int> pii;

constexpr int N = 1e5;

int n, a[N + 5], b[N + 5];
int cnt[N * 300 + 100000];

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i], b[n - i + 1] = a[i];
    int ans = n;
    for (int d = 0; d <= 300; d++) {
        for (int i = 1; i <= n; i++) ans = min(ans, n - ++cnt[a[i] - i * d + d * n]);
        for (int i = 1; i <= n; i++) cnt[a[i] - i * d + d * n] = 0;
        for (int i = 1; i <= n; i++) ans = min(ans, n - ++cnt[b[i] - i * d + d * n]);
        for (int i = 1; i <= n; i++) cnt[b[i] - i * d + d * n] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j + i <= n && j * 300 <= 1e5; j++) {
            int dif = a[i + j] - a[i];
            if (dif % j) continue;
            ans = min(ans, n - ++cnt[dif / j + 100000] - 1);
        }
        for (int j = 1; j + i <= n && j * 300 <= 1e5; j++) {
            int dif = a[i + j] - a[i];
            if (dif % j) continue;
            cnt[dif / j + 100000] = 0;
        }
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Zlin();
    return 0;
}
