//
// Created by 27682 on 2025/5/9.
//

#include "bits/stdc++.h"
#define endl '\n'
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
    int a, b, ab, ba, cnt = 0;
    string s, c;
    vector<string> v;
    cin >> s >> a >> b >> ab >> ba;
    c = s[0];
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i - 1]) {
            if (c.length() & 1) {
                char z = c.back();
                c.pop_back();
                cnt += c.length() / 2;
                z == 'A' ? --a : --b;
            } else {
                v.push_back(c);
            }
            c.clear();
        }
        c += s[i];
    }
    if (c.length() & 1) {
        char z = c.back();
        c.pop_back();
        cnt += c.length() / 2;
        z == 'A' ? --a : --b;
    } else {
        v.push_back(c);
    }
    c.clear();

    if (a < 0 || b < 0) {
        cout << "NO" << endl;
        return;
    }
    int sab = 0, sba = 0, val;
    priority_queue<int> abx, bax;
    for (const string &it: v) {
        val = it.length() / 2;
        if (it[0] == 'A') {
            sab += val;
            abx.push(val);
        } else {
            sba += val;
            bax.push(val);
        }
    }
    while (sab > ab && a && b) {
        --a, --b;
        val = abx.top();
        abx.pop();
        sab -= val;
        cnt += val - 1;
    }
    while (sba > ba && a && b) {
        --a, --b;
        val = bax.top();
        bax.pop();
        sba -= val;
        cnt += val - 1;
    }
    ab -= sab, ba -= sba;
    if (a < 0 || b < 0 || ab < 0 || ba < 0 || cnt > ab + ba + min(a, b)) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
