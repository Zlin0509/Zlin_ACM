#include <bits/stdc++.h>
using namespace std;

constexpr long long INF = 1e18 + 1;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char *argv[]) {
    int n = stoi(argv[1]);
    int k = stoi(argv[2]);
    int seed = stoi(argv[3]);

    rng.seed(seed);

    cout << n << ' ' << k << "\n";

    for (int i = 0; i < n; i++) {
        long long a = rng() % INF;
        long long b = rng() % INF;
        long long c = rng() % INF;
        cout << a << " " << b << " " << c << "\n";
    }
}
