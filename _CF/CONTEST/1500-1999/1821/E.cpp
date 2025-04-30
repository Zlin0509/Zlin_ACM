//
// Created by 27682 on 2025/3/26.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

inline void Zlin() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    vi cnt(s.length()), all;
    stack<int> have;
    ll ans = 0;
    for (int r = 1, val, l; r < s.length(); r++) {
        cnt[r] += cnt[r - 1];
        if (s[r] == '(') {
            have.push(r);
        } else {
            l = have.top();
            have.pop();
            val = cnt[r] - cnt[l];
            ans += val;
            all.push_back(val);
            ++cnt[r];
        }
    }
    sort(all.begin(), all.end());
    while (k && !all.empty()) {
        ans -= all.back();
        all.pop_back();
        --k;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
