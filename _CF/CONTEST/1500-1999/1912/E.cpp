//
// Created by 27682 on 2025/3/4.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;

typedef long long ll;
typedef vector<ll> vll;

vll sxsx;

void opbase(ll base) {
    if (base == 0) {
        cout << "1-1";
        return;
    }
    char tag = '+';
    if (base < 0) base *= -1, tag = '-';
    vll all;
    for (int i = sxsx.size() - 1, cnt; ~i; i--) {
        cnt = base / sxsx[i];
        base %= sxsx[i];
        while (cnt--) all.push_back(sxsx[i]);
    }
    if (tag == '-') cout << 1 << tag;
    cout << all.back();
    all.pop_back();
    while (!all.empty()) {
        cout << tag << all.back();
        all.pop_back();
    }
    if (tag == '-') cout << tag << 1;
}

inline void Zlin() {
    ll p, q;
    cin >> p >> q;
    ll dif = p - q, base = p;
    vector<string> ans;
    string lx, rx;
    if (dif & 1) {
        ans.push_back("12");
        base -= 12;
        dif += 9;
    }
    lx = "1+", rx = "-1";
    if (dif < 0) {
        lx = "1-", rx = "+1";
        dif *= -1;
    }
    for (int i = sxsx.size() - 1; i; i--) {
        ll val = sxsx[i] * 2ll - 2;
        while (val <= dif) {
            ans.push_back(lx + to_string(sxsx[i]) + rx);
            dif -= val;
            if (lx == "1+") base -= sxsx[i];
            else base -= 2 - sxsx[i];
        }
        if (!dif) break;
    }
    opbase(base);
    while (!ans.empty()) {
        cout << '+';
        cout << ans.back();
        ans.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int ttt = 1;
    ll tag = 1;
    for (int i = 1; i <= 18; i++) {
        for (int j = 1; j <= 9; j++) sxsx.push_back(tag * j);
        tag = tag * 10 + 1;
    }
    while (ttt--) Zlin();
    return 0;
}
