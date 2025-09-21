//
// Created by 27682 on 2025/9/21.
//

#include "bits/stdc++.h"
using namespace std;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef double db;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Fraction {
    long long num; // 分子
    long long den; // 分母

    // 构造函数
    Fraction(long long _num = 0, long long _den = 1) {
        if (_den == 0) throw runtime_error("Denominator cannot be zero");
        if (_den < 0) _num = -_num, _den = -_den; // 保持分母为正
        long long g = gcd(abs(_num), abs(_den));
        num = _num / g;
        den = _den / g;
    }

    // 约分
    void reduce() {
        if (den < 0) num = -num, den = -den;
        long long g = gcd(abs(num), abs(den));
        num /= g;
        den /= g;
    }

    // 加法
    Fraction operator+(const Fraction &other) const {
        return Fraction(num * other.den + other.num * den, den * other.den);
    }

    // 减法
    Fraction operator-(const Fraction &other) const {
        return Fraction(num * other.den - other.num * den, den * other.den);
    }

    // 乘法
    Fraction operator*(const Fraction &other) const {
        return Fraction(num * other.num, den * other.den);
    }

    // 除法
    Fraction operator/(const Fraction &other) const {
        if (other.num == 0) throw runtime_error("Division by zero fraction");
        return Fraction(num * other.den, den * other.num);
    }

    // 复合赋值运算符
    Fraction &operator+=(const Fraction &other) { return *this = *this + other; }
    Fraction &operator-=(const Fraction &other) { return *this = *this - other; }
    Fraction &operator*=(const Fraction &other) { return *this = *this * other; }
    Fraction &operator/=(const Fraction &other) { return *this = *this / other; }

    // 比较运算
    bool operator==(const Fraction &other) const {
        return num == other.num && den == other.den;
    }

    bool operator!=(const Fraction &other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction &other) const {
        return num * other.den < other.num * den;
    }

    bool operator>(const Fraction &other) const {
        return num * other.den > other.num * den;
    }

    bool operator<=(const Fraction &other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction &other) const {
        return !(*this < other);
    }

    // 输出
    friend ostream &operator<<(ostream &os, const Fraction &f) {
        if (f.den == 1) return os << f.num;
        return os << f.num << "/" << f.den;
    }

    // 输入
    friend istream &operator>>(istream &is, Fraction &f) {
        string s;
        is >> s;
        auto pos = s.find('/');
        if (pos == string::npos) {
            f = Fraction(stoll(s), 1);
        } else {
            long long n = stoll(s.substr(0, pos));
            long long d = stoll(s.substr(pos + 1));
            f = Fraction(n, d);
        }
        return is;
    }
} k(1, 4);

constexpr int N = 1005;

int n, cc[N];
pair<Fraction, Fraction> res[N];
vi a;

inline void Zlin() {
    cin >> n;
    a.clear();
    memset(cc, 0, sizeof(cc));
    for (int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        ++cc[x];
        a.emplace_back(x);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    for (int i = 0; i < a.size(); i++) {
        if (cc[a[i]] == 1) {
            if (i > 0 && i < a.size() - 1) {
                cout << "? " << a[i] << " 1" << endl;
                cin >> res[i].first.num >> res[i].first.den;
                res[i].second = res[i].first;
            } else res[i].first = res[i].second = Fraction(0, 1);
        } else {
            Fraction xx = {a[i], 1};
            xx -= k;
            cout << "? " << xx.num << " " << xx.den << endl;
            cin >> res[i].first.num >> res[i].first.den;
            xx += k, xx += k;
            cout << "? " << xx.num << " " << xx.den << endl;
            cin >> res[i].second.num >> res[i].second.den;
        }
    }
    Fraction ans{0, 1};
    for (int i = 1; i < a.size(); i++) {
        Fraction dif = k;
        dif *= {(cc[a[i - 1]] > 1) + (cc[a[i]] > 1), 1};
        dif.reduce();
        dif = Fraction(a[i] - a[i - 1], 1) - dif;
        dif.reduce();
        dif = (res[i].first - res[i - 1].second) / dif;
        dif.reduce();

        Fraction tmp = {0, 1};
        if (cc[a[i]] > 1) tmp += res[i].first + dif * k;
        else tmp += res[i].first;
        tmp.reduce();
        if (cc[a[i - 1]] > 1) tmp += res[i - 1].second - dif * k;
        else tmp += res[i - 1].second;
        tmp.reduce();

        tmp *= Fraction(a[i] - a[i - 1], 2);
        tmp.reduce();

        ans += tmp;
        ans.reduce();
    }
    cout << "! " << ans.num << " " << ans.den << endl;
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int ttt = 1;
    cin >> ttt;
    while (ttt--) Zlin();
    return 0;
}
