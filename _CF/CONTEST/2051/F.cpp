//
// Created by Zlin on 2025/2/22.
//

#include "bits/stdc++.h"

#define endl "\n"
using namespace std;

typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

inline void Zlin() {
    int n, m, q;
    cin >> n >> m >> q;
    vi qry(q);
    for (int i = 0; i < q; i++)
        cin >> qry[i];
    int l = m, r = m, beg = -1, end = -1;
    for (int i = 0; i < q; i++) {
        int x = qry[i];
        if (qry[0] == m) {
            if (i == 0)
                beg = 1, end = n;
            else {
                if (beg < x)
                    ++beg;
                if (end > x)
                    --end;
            }
            cout << min(n, n - end + 1 + beg) << ' ';
        } else {
            if (end != -1 && end > x)
                --end;
            if (beg != -1 && beg < x)
                ++beg;
            if (l > x) {
                --l;
            } else if (r < x) {
                ++r;
            } else {
                if (beg == -1)
                    beg = 1;
                if (end == -1)
                    end = n;
            }
            if (beg != -1 && beg >= l)
                l = 1, beg = -1;
            if (end != -1 && end <= r)
                r = n, end = -1;
            int ans = r - l + 1;
            if (beg != -1)
                ans += beg;
            if (end != -1)
                ans += n - end + 1;
            cout << ans << ' ';
        }
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
