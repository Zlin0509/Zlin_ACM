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

const int N = 2e5 + 5;
int n, x;
int a[N];
vi have;
map<int, int> used;

inline void Zlin() {
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    used[x] = 1;
    have.push_back(x);
    int ans = 0, l = 0;
    for (int i = 1; i <= n; i++) {
        if (used[a[i]]) {
            ++ans;
            have.clear();
            used.clear();
            have.push_back(x);
            used[x] = 1;
        }
        for (auto it: have) {
            if (it % a[i] || used[it / a[i]]) continue;
            have.push_back(it / a[i]);
            used[it / a[i]] = 1;
        }
    }
    ++ans;
    have.clear();
    used.clear();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt;
    cin >> ttt;
    while (ttt--) Zlin();
}