//
// Created by Zlin on 2025/5/1.
//

#include "bits/stdc++.h"
#define endl "\n"
using namespace std;

typedef __int128 i128;
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

constexpr ll inf = 2e18;

int n;
ll a1, b1, a2, b2;

// 将 i128 转换为字符串输出
void print_i128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    if (x < 0) {
        cout << '-';
        x = -x;
    }
    string s;
    while (x) {
        s += char(x % 10 + '0');
        x /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s;
}

i128 cost(ll a, ll b, ll k) {
    return i128(a) * k * (k + 1) / 2 + i128(b) * k;
}

i128 total_cost(ll x) {
    ll y = n - x;
    return cost(a1, b1, x) + cost(a2, b2, y);
}

inline void Zlin() {
    cin >> n >> a1 >> b1 >> a2 >> b2;
    int l = 1, r = n - 1;
    while (r - l > 3) {
        int midl = l + (r - l) / 3;
        int midr = r - (r - l) / 3;
        if (total_cost(midl) < total_cost(midr))
            r = midr - 1;
        else
            l = midl + 1;
    }
    i128 ans = 1e38;
    for (int i = l; i <= r; i++) {
        ans = min(ans, total_cost(i));
    }
    print_i128(ans);
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
