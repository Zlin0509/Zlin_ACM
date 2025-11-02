//
// Created by Zlin on 2024/10/12.
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

constexpr int N = 1e6 + 5;
constexpr ll mo = 1e9 + 7;


inline ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mo;
        a = a * a % mo;
        b >>= 1;
    }
    return res;
}

const ll inv3 = qpow(3, mo - 2);

inline ll dif(int i) {
    return (qpow(4, i) - 1 + mo) % mo * inv3 % mo * 4 % mo;
}

inline ll cal(string &t) {
    if (t.length() & 1) t += '0';
    ll ans = 0;
    for (int i = t.length() - 1, tmp, k; ~i; i -= 2) {
        tmp = (t[i] - '0') * 2 + (t[i - 1] - '0');
        k = i / 2;
        if (tmp == 1) ans = (ans + dif(k) + 1) % mo;
        if (tmp == 3) ans = (ans + (dif(k) + 1) * 2) % mo;
        if (tmp == 2) ans = (ans + (dif(k) + 1) * 3) % mo;
    }
    return ans;
}

inline void Zlin() {
    string s, t;
    int k;
    cin >> s >> t >> k;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    while (s.length() > t.length()) t += '0';
    while (t.length() > s.length()) s += '0';
    for (int i = 0; i < s.length(); i++) if (s[i] == '1') t[i] = t[i] == '1' ? '0' : '1';
    for (int i = 0; i < min((int) t.length(), (k - 1) * 2); i++) {
        if (t[i] == '1') {
            cout << -1 << endl;
            return;
        }
    }
    cout << (cal(t) + dif(k - 1)) % mo << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
}
