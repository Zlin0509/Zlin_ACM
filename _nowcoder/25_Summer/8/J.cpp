//
// Created by Zlin on 2025/8/7.
//

#include "bits/stdc++.h"
#define endl '\n'
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const double PI = acos(-1.0);

struct Cp {
    double r, i;

    Cp(double _r = 0.0, double _i = 0.0) : r(_r), i(_i) {
    }

    Cp operator+(const Cp &o) const {
        return Cp(r + o.r, i + o.i);
    }

    Cp operator-(const Cp &o) const {
        return Cp(r - o.r, i - o.i);
    }

    Cp operator*(const Cp &o) const {
        return Cp(r * o.r - i * o.i, r * o.i + i * o.r);
    }
};

// 进行 FFT 或 IFFT，d == 1 表示 FFT，d == -1 表示 IFFT
void fft(vector<Cp> &a, int n, int d) {
    for (int p = 1, q = 0; p < n - 1; p++) {
        for (int k = n >> 1; (q ^= k) < k; k >>= 1);
        if (p < q) swap(a[p], a[q]);
    }
    for (int m = 2; m <= n; m <<= 1) {
        Cp wm(cos(2 * PI / m), sin(d * 2 * PI / m));
        for (int p = 0; p < n; p += m) {
            Cp w(1, 0);
            for (int j = 0; j < m / 2; j++) {
                Cp u = a[p + j];
                Cp t = w * a[p + j + m / 2];
                a[p + j] = u + t;
                a[p + j + m / 2] = u - t;
                w = w * wm;
            }
        }
    }
    if (d == -1) {
        for (int p = 0; p < n; p++) {
            a[p].r /= n;
            a[p].i /= n;
        }
    }
}

// 大数乘法主函数
vector<int> multiply(const vector<int> &A, const vector<int> &B) {
    int n = 1;
    while (n < A.size() + B.size()) n <<= 1; // 找到大于等于 A.size() + B.size() 的最小 2 的幂
    vector<Cp> a(n), b(n);

    for (int p = 0; p < A.size(); p++) a[p] = Cp(A[p], 0);
    for (int p = 0; p < B.size(); p++) b[p] = Cp(B[p], 0);

    fft(a, n, 1);
    fft(b, n, 1);

    for (int p = 0; p < n; p++) a[p] = a[p] * b[p]; // 点乘
    fft(a, n, -1);

    vector<int> res(n + 200);
    for (int p = 0; p < n; p++) res[p] = int(a[p].r + 0.5); // 四舍五入取整
    for (int p = 0; p < n + 200 - 1; p++) {
        if (res[p] >= 2) {
            int k = res[p] >> 1;
            res[p] -= k << 1;
            res[p + 2] -= k;
        }
        if (res[p] < 0) {
            int k = 1 - res[p] >> 1;
            res[p] += k << 1;
            res[p + 2] += k;
        }
    }
    while (res.size() > 1 && res.back() == 0) res.pop_back(); // 去掉前导0
    return res;
}

string sa, sb;

inline void Zlin() {
    cin >> sa >> sb;
    vi a, b;
    for (char i: sa) a.emplace_back(i - '0');
    for (char i: sb) b.emplace_back(i - '0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vi res = multiply(a, b);
    while (!res.empty()) {
        cout << res.back();
        res.pop_back();
    }
    cout << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
