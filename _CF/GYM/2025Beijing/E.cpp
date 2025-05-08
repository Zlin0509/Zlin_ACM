//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
typedef double ldb;
mt19937 rnd(time(0));
const int inf = 1e15;
int n;
const int N = 1e5 + 7;

struct Point {
    double x, y;

    Point() {
    }

    Point(double _x, double _y) : x(_x), y(_y) {
    }

    Point operator-(const Point &b) const { return Point(x - b.x, y - b.y); }
    Point operator+(const Point &b) const { return Point(x + b.x, y + b.y); }
} p[N];

double cross(Point a, Point b) {
    return a.x * b.y - b.x * a.y;
}

double dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}

double get_length(Point a) {
    return sqrt(dot(a, a));
}

double distance_to_line(Point p, Point a, Point b) {
    Point v1 = b - a, v2 = p - a;
    return fabs(cross(v1, v2) / get_length(v1));
}

Point get_line_projection(Point p, Point a, Point b) {
    Point v = b - a;
    return {a.x + v.x * (dot(v, p - a) / dot(v, v)), a.y + v.y * (dot(v, p - a) / dot(v, v))};
}

double eps = 1e-7;
//二分最远长度
vector<double> v;
int getindex(double x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int a, b, c;
Point p1, p2;
int mx = 0;
int arr[N];

bool check(double mid) {
    vector<pair<double,double> > vl;
    v.clear();
    for (int i = 1; i <= n; i++) {
        double h = distance_to_line(p[i], p1, p2);
        cout << h << endl;
        if (h > mid)return false;
        Point t = get_line_projection(p[i], p1, p2);
        double w = sqrtl(mid * mid - h * h);
        double d = w * (b * b) / ((a * a) + (b * b));
        vl.push_back({t.x - d, t.x + d});
        v.push_back(t.x - d);
        v.push_back(t.x + d);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (auto i: vl) {
        int tem = getindex(i.first);
        int tem2 = getindex(i.second);
        arr[tem] += 1;
        arr[tem2 + 1]--;
        mx = max({mx, tem, tem2 + 1});
    }
    for (int i = 1; i <= mx; i++) {
        arr[i] += arr[i - 1];
        if (arr[i] == n)return true;
    }
    return false;
}

void solved() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    cin >> a >> b >> c;
    p1 = {0, -(ldb) c / b};
    p2 = {-(ldb) c / a, 0};
    double l = 0, r = 1e9;
    while (r - l > eps) {
        double mid = r + l / 2;
        if (check(mid))r = mid;
        else l = mid;
    }
    cout << fixed << setprecision(7) << r << '\n';
}

signed main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)solved();
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    //cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.";
    return 0;
}
