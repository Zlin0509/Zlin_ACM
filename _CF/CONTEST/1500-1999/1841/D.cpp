//
// Created by 27682 on 2025/2/28.
//

#include "bits/stdc++.h"

#define endl '\n'
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int n;
    cin >> n;
    vector<pii> a(n);
    for (pii &it: a)
        cin >> it.first >> it.second;
    vector<pii> now;
    auto check = [](int l1, int r1, int l2, int r2) {
        if (l1 > l2)
            swap(l1, l2), swap(r1, r2);
        return r1 >= l2;
    };
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (check(a[i].first, a[i].second, a[j].first, a[j].second))
                now.push_back({min(a[i].first, a[j].first), max(a[i].second, a[j].second)});
    sort(now.begin(), now.end(), [](const pii &a, const pii &b) {
        return a.second < b.second;
    });
    int cnt = 0, tag = -1;
    for (auto it: now) {
        if (it.first <= tag)
            continue;
        ++cnt;
        tag = it.second;
    }
    cout << n - cnt * 2 << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--)
        Zlin();
    return 0;
}