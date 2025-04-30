//
// Created by Zlin on 2024/10/5.
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

const double PI = acos(-1.0);

struct Complex {
    double real, imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    Complex operator+(const Complex &other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    Complex operator-(const Complex &other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    Complex operator*(const Complex &other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }
};

// 进行 FFT 或 IFFT，on == 1 表示 FFT，on == -1 表示 IFFT
void fft(vector<Complex> &a, int n, int on) {
    for (int i = 1, j = 0; i < n - 1; i++) {
        for (int k = n >> 1; (j ^= k) < k; k >>= 1);
        if (i < j) swap(a[i], a[j]);
    }
    for (int m = 2; m <= n; m <<= 1) {
        Complex wm(cos(2 * PI / m), sin(on * 2 * PI / m));
        for (int i = 0; i < n; i += m) {
            Complex w(1, 0);
            for (int j = 0; j < m / 2; j++) {
                Complex u = a[i + j];
                Complex t = w * a[i + j + m / 2];
                a[i + j] = u + t;
                a[i + j + m / 2] = u - t;
                w = w * wm;
            }
        }
    }
    if (on == -1) {
        for (int i = 0; i < n; i++) {
            a[i].real /= n;
            a[i].imag /= n;
        }
    }
}

// 多项式乘法
vector<int> multiply_polynomials(const vector<int> &A, const vector<int> &B) {
    int n = 1;
    while (n < A.size() + B.size()) n <<= 1;  // 取大于等于 A.size() + B.size() 的最小2的幂
    vector<Complex> a(n), b(n);

    for (int i = 0; i < A.size(); i++) a[i] = Complex(A[i], 0);
    for (int i = 0; i < B.size(); i++) b[i] = Complex(B[i], 0);

    // 进行 FFT 变换
    fft(a, n, 1);
    fft(b, n, 1);

    // 点乘：每个位置上的系数相乘
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i];

    // 逆 FFT 变换
    fft(a, n, -1);

    // 提取结果并处理进位
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(a[i].real);

    return result;
}

inline void Zlin() {
    int n, m;
    cin >> n >> m;
    vi f(n + 1), g(m + 1);
    for (int i = 0; i <= n; i++) cin >> f[i];
    for (int i = 0; i <= m; i++) cin >> g[i];
    vi ans = multiply_polynomials(f, g);
    for (int i = 0; i < n + m + 1; i++) cout << ans[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int ttt = 1;
//    cin >> ttt;
    while (ttt--) Zlin();
}