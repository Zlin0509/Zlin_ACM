//
// Created by 27682 on 2025/5/6.
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

constexpr int N = 1e6 + 50;
constexpr ll p = 1145141, mo = 1e9 + 7;

ll Hash[N], fac[N];
ll lx, rx, va;
string s, t;
int q, ans[12];

unordered_map<ll, int> val;

inline void Zlin() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = fac[i - 1] * p % mo;
    cin >> s;
    Hash[0] = s[0];
    for (int i = 1; i < s.length(); i++) Hash[i] = (Hash[i - 1] * p + s[i]) % mo;
    for (int len = 1; len <= 10; len++) {
        for (int k = len + 1; k <= s.length(); k++) {
            lx = Hash[k - 1 - len];
            rx = (Hash[s.length() - 1] - Hash[s.length() - 1 - (k - len)] * fac[k - len] % mo + mo) % mo;
            if (lx == rx) {
                va = (Hash[k - 1] - Hash[k - 1 - len] * fac[len] % mo + mo) % mo;
                val[va] = max(val[va], k);
            }
        }
    }
    cin >> q;
    while (q--) {
        cin >> t;
        for (int i = 0; i < t.length(); i++) Hash[i + s.length()] = (Hash[i + s.length() - 1] * p + t[i]) % mo;
        for (int i = 0; i < t.length(); i++) {
            va = (Hash[s.length() + i] - Hash[s.length() - 1] * fac[i + 1] % mo + mo) % mo;
            val.contains(va) ? ans[i + 1] = val[va] : ans[i + 1] = 0;
            for (int j = 0; j <= min(20, (int) s.length() + i - 1); j++) {
                lx = Hash[j];
                rx = (Hash[s.length() + i] - Hash[s.length() + i - (j + 1)] * fac[j + 1] % mo + mo) % mo;
                if (lx == rx) ans[i + 1] = max(ans[i + 1], j + 1);
            }
            for (int j = s.length(); j <= s.length() + i - 1; j++) {
                lx = Hash[j];
                rx = (Hash[s.length() + i] - Hash[s.length() + i - (j + 1)] * fac[j + 1] % mo + mo) % mo;
                if (lx == rx) ans[i + 1] = max(ans[i + 1], j + 1);
            }
        }
        for (int i = 1; i <= t.length(); i++) cout << ans[i] << ' ';
        cout << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
    while (ttt--) Zlin();
    return 0;
}