//
// Created by Zlin on 2024/10/17.
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

vll a(7);


ll cal(ll tag, ll now) {
    return tag * now + (now - 1) * 3 / 2;
}

inline void Zlin() {
    ll l, r, ans = 0, ans1 = 0;
    ll dep = 0, now = 1;
    ll tag = 1, cnt = 2;
    cin >> l >> r;
    ans = dep = 0, now = 1;
    while (now * 3 <= r) {
        now *= 3;
        ++dep;
    }
    tag = 1, cnt = 2;
    while (dep) {
        if (cal(tag * 3 + 2, now / 3) >= l && cal(tag * 3 + 2, now / 3) <= r) {
            ans = max(ans, cnt + dep * 3);
            break;
        } else if (cal(tag * 3 + 1, now / 3) >= l && cal(tag * 3 + 1, now / 3) <= r) {
            ans = max(ans, cnt + dep * 3 - 1);
            break;
        } else if (cal(tag * 3, now / 3) >= l && cal(tag * 3, now / 3) <= r) {
            ans = max(ans, cnt + dep * 3 - 2);
            break;
        }
        if (tag * now > r || cal(tag * 3 + 2, now / 3) < l) break;
        if (cal(tag * 3, now / 3) >= l) {
            tag = tag * 3;
            ++cnt;
        } else if (cal(tag * 3 + 1, now / 3) >= l) {
            tag = tag * 3 + 1;
            cnt += 2;
        } else {
            tag = tag * 3 + 2;
            cnt += 3;
        }
        now /= 3;
        --dep;
    }
    while ((tag + 1) % 3 && tag + 1 <= r) {
        ++ans;
        ++tag;
    }
    ans1 = dep = 0, now = 1;
    while (now * 3 <= r / 2) {
        now *= 3;
        ++dep;
    }
    tag = 2, cnt = 3;
    while (dep) {
        if (cal(tag * 3 + 2, now / 3) >= l && cal(tag * 3 + 2, now / 3) <= r) {
            ans1 = max(ans1, cnt + dep * 3);
            break;
        } else if (cal(tag * 3 + 1, now / 3) >= l && cal(tag * 3 + 1, now / 3) <= r) {
            ans1 = max(ans1, cnt + dep * 3 - 1);
            break;
        } else if (cal(tag * 3, now / 3) >= l && cal(tag * 3, now / 3) <= r) {
            ans1 = max(ans1, cnt + dep * 3 - 2);
            break;
        }
        if (tag * now > r || cal(tag * 3 + 2, now / 3) < l) break;
        if (cal(tag * 3, now / 3) >= l) {
            tag = tag * 3;
            ++cnt;
        } else if (cal(tag * 3 + 1, now / 3) >= l) {
            tag = tag * 3 + 1;
            cnt += 2;
        } else {
            tag = tag * 3 + 2;
            cnt += 3;
        }
        now /= 3;
        --dep;
    }
    while ((tag + 1) % 3 && tag + 1 <= r) {
        ++ans1;
        ++tag;
    }
    ans = max(ans, ans1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    a[0] = 1, a[1] = 2, a[2] = a[3] = 3, a[6] = 3;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}