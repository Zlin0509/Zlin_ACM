//
// Created by Zlin on 2024/9/26.
//

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1e5 + 5;
int n, q, x;
int a[N], res[N], cnt[N << 1];

inline bool check(int mid) {
    int sum = 0;
    for (int i = 0; i <= n; i += x) {
        if (!i) sum += cnt[mid];
        else sum += cnt[i + mid] - cnt[i - 1];
    }
    return sum >= n / 2 + 1;
}

inline void Zlin() {
    memset(cnt, 0, sizeof cnt);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i], cnt[a[i]]++;
    for (int i = 1; i < n * 2; i++) cnt[i] += cnt[i - 1];
    for (x = 1; x <= n; x++) {
        int l = 0, r = x - 1, mid;
        while (l < r) {
            mid = l + r >> 1;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        res[x] = l;
    }
    while (q--) {
        cin >> x;
        cout << res[x] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}