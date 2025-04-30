//
// Created by Zlin on 2024/9/24.
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
    int n, ans = INT_MAX;
    string x;
    cin >> n;
    cin >> x;
    x = ' ' + x;
    int pre[26][2]{};
    for (int i = 1; i <= n; i++) pre[x[i] - 'a'][i & 1]++;
    if (n & 1) {
        for (int i = n, m0, m1; i; i--) {
            m0 = m1 = 0;
            pre[x[i] - 'a'][i & 1]--;
            for (int j = 0; j < 26; j++) {
                m0 = max(m0, pre[j][0]);
                m1 = max(m1, pre[j][1]);
            }
            pre[x[i] - 'a'][!(i & 1)]++;
            ans = min(ans, n - 1 - m0 - m1);
        }
        ++ans;
    } else {
        int m0 = 0, m1 = 0;
        for (int i = 0; i < 26; i++) {
            m0 = max(m0, pre[i][0]);
            m1 = max(m1, pre[i][1]);
        }
        ans = min(ans, n - m0 - m1);
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