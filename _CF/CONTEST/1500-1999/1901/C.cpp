#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<long long>;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    ll M = INT_MIN, m = INT_MAX;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        M < x ? M = x : M;
        m > x ? m = x : m;
    }
    vl ans;
    int num = 0;
    while (m < M) {
        ++num;
        if (m % 2 == M % 2) {
            m = (m + 2) / 2;
            M = (M + 2) / 2;
            ans.push_back(2);
        } else if (m % 2 == 0) {
            m = (m + 2) / 2;
            M = (M + 2) / 2;
            ans.push_back(2);
        } else {
            m = (m + 1) / 2;
            M = (M + 1) / 2;
            ans.push_back(1);
        }
    }
    cout << num << '\n';
    if (num <= n && num) {
        for (auto it: ans)
            cout << it << " ";
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
