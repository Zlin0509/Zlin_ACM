#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<int> vi;

constexpr int N = 3e5 + 10;

int n, m, k, lx[N], rx[N], val[N * 3], used[N];
vi have, in[N * 3], out[N * 3];

inline void Zlin() {
    cin >> n >> k;
    have.clear();
    for (int i = 1; i <= n; i++) {
        used[i] = 0;
        cin >> lx[i] >> rx[i];
        have.push_back(lx[i]);
        have.push_back(rx[i]);
    }
    sort(have.begin(), have.end());
    have.erase(unique(have.begin(), have.end()), have.end());
    m = have.size();
    for (int i = 0; i < m; i++) {
        val[i] = 0;
        in[i].clear();
        out[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        lx[i] = lower_bound(have.begin(), have.end(), lx[i]) - have.begin();
        rx[i] = lower_bound(have.begin(), have.end(), rx[i]) - have.begin();
        in[rx[i]].push_back(i);
        if (lx[i]) out[lx[i] - 1].push_back(i);
    }
    int ans = 0;
    for (int i = m - 1, cnt = 0; ~i; i--) {
        cnt += in[i].size() + out[i].size();
        val[i] = cnt;
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
