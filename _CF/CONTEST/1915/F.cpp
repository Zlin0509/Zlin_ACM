#include <bits/stdc++.h>
using namespace std;
int t, n, nv, tp[1000005 << 1];
long long ans, c[1000005];
pair<int, int> p[1000005];
map<int, bool> flag;
void add(int x, int k) {
    while (x <= nv) {
        c[x] += k;
        x += (x & -x);
    }
}
int query(int x) {
    int ret = 0;

    while (x) {
        ret += c[x];
        x -= (x & -x);
    }

    return ret;
}
int main() {
    cin >> t;

    while (t--) {
        for (int i = 0; i <= n * 2; i++)
            c[i] = 0;

        cin >> n;
        ans = nv = 0, flag.clear();

        for (int i = 1; i <= n; i++) {
            cin >> p[i].first >> p[i].second;

            if (!flag[p[i].first]) {
                tp[++nv] = p[i].first;
                flag[p[i].first] = 1;
            }

            if (!flag[p[i].second]) {
                tp[++nv] = p[i].second;
                flag[p[i].second] = 1;
            }
        }

        sort(tp + 1, tp + nv + 1);
        nv = unique(tp + 1, tp + nv + 1) - tp - 1;

        for (int i = 1; i <= n; i++) {
            p[i].first = lower_bound(tp + 1, tp + nv + 1, p[i].first) - tp;
            p[i].second = lower_bound(tp + 1, tp + nv + 1, p[i].second) - tp;
        }

        sort(p + 1, p + n + 1);

        for (int i = 1; i <= n; i++) {
            ans += i - query(p[i].second - 1) - 1;
            add(p[i].second, 1);
        }

        cout << ans << '\n';
    }

    return 0;
}