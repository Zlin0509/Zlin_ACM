//
// Created by Zlin on 2024/10/22.
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

const int N = 2e5 + 5;
int n;

struct ss {
    int val, id;

    bool operator<(const ss &x) const {
        return val < x.val;
    }
} a[N];

bool check(int x) {
    int l = x, r = x, cnt = 1, tag;
    for (int i = 1; i <= n; i++) {
        tag = a[i].id;
        if (tag >= l && tag <= r) continue;
        if (tag < l) {
            cnt += l - tag;
            l = tag;
        } else if (tag > r) {
            cnt += tag - r;
            r = tag;
        }
        if (cnt > a[i].val) return false;
    }
    return true;
}

inline void Zlin() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].val, a[i].id = i;
    sort(a + 1, a + 1 + n);
    int l = 1, r = a[1].id, mm, mx, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    mm = l;
    l = a[1].id, r = n;
    while (l < r) {
        mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    mx = l;
    cout << (check(a[1].id) ? mx - mm + 1 : 0) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}