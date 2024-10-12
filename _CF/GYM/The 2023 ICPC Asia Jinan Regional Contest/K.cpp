//
// Created by Zlin on 2024/10/9.
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

const int N = 5e5 + 10;

int n;
ll k;
vi a(N);
ll sum_l, sum_r, all, mid;
int l, r, sl, sr;
int ans;
multiset<int, greater<int>> lx;
multiset<int> rx;

void cal() {
    int tag = 0;
    while (lx.size() > rx.size() + 1) {
        tag = *lx.begin();
        lx.erase(lx.begin());
        rx.insert(tag);
        sum_l -= tag;
        sum_r += tag;
    }
    while (lx.size() < rx.size()) {
        tag = *rx.begin();
        rx.erase(rx.begin());
        lx.insert(tag);
        sum_l += tag;
        sum_r -= tag;
    }
};

inline void Zlin() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], a[i] -= i;
    lx.clear(), rx.clear();
    l = r = ans = 1;
    sum_l = a[l], sum_r = 0;
    lx.insert(a[l]);
    while (l < n) {
        cal();//平衡左右堆大小
        sl = lx.size();
        sr = rx.size();
        if (lx.size() == rx.size()) {
            mid = *lx.begin();
            all = sum_r - mid * sr + mid * sl - sum_l;
            mid = *rx.begin();
            all = min(all, sum_r - mid * sr + mid * sl - sum_l);
        } else {
            mid = *lx.begin();
            all = sum_r - mid * sr + mid * sl - sum_l;
        }
        if (all <= k) {
            ans = max(ans, r - l + 1);
            if (r == n) break;
            ++r;
            if (a[r] <= *lx.begin()) {
                lx.insert(a[r]);
                sum_l += a[r];
            } else {
                rx.insert(a[r]);
                sum_r += a[r];
            }
        } else {
            if (a[l] <= *lx.begin()) {
                lx.erase(lx.find(a[l]));
                sum_l -= a[l];
            } else {
                rx.erase(rx.find(a[l]));
                sum_r -= a[l];
            }
            l++;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}