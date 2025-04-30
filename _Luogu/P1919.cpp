//
// Created by Zlin on 2024/10/5.
//

#include "bits/stdc++.h"

using namespace std;

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

// 大数乘法主函数
vector<int> multiply(const vector<int> &A, const vector<int> &B) {
    int n = 1;
    while (n < A.size() + B.size()) n <<= 1;  // 找到大于等于 A.size() + B.size() 的最小 2 的幂
    vector<Complex> a(n), b(n);
    for (int i = 0; i < A.size(); i++) a[i] = Complex(A[i], 0);
    for (int i = 0; i < B.size(); i++) b[i] = Complex(B[i], 0);

    fft(a, n, 1);
    fft(b, n, 1);
    for (int i = 0; i < n; i++) a[i] = a[i] * b[i];  // 点乘
    fft(a, n, -1);

    vector<int> result(n);
    for (int i = 0; i < n; i++) result[i] = int(a[i].real + 0.5);  // 四舍五入取整
    for (int i = 0; i < n - 1; i++) {
        result[i + 1] += result[i] / 10;  // 处理进位
        result[i] %= 10;
    }
    while (result.size() > 1 && result.back() == 0) result.pop_back();  // 去掉前导0
    return result;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    vector<int> A(s1.size()), B(s2.size());

    // 将字符串转化为数字数组，低位在前
    for (int i = 0; i < s1.size(); i++) A[i] = s1[s1.size() - 1 - i] - '0';
    for (int i = 0; i < s2.size(); i++) B[i] = s2[s2.size() - 1 - i] - '0';

    vector<int> result = multiply(A, B);

    // 输出结果，注意高位在前
    for (int i = result.size() - 1; i >= 0; i--) cout << result[i];
    cout << endl;

    return 0;
}